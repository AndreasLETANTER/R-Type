/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** DefaultMode
*/

#include "DefaultMode.hpp"

#include "ECS/Components/EntityClass.hpp"
#include "ECS/Systems/LoggingSystem/LoggingSystem.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"
#include "ECS/Systems/ControlSystem/ControlSystem.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Systems/AutoMoveSystem/AutoMoveSystem.hpp"
#include "ECS/Systems/ShootSystem/ShootSystem.hpp"
#include "ECS/Systems/ProjectileSystem/ProjectileSystem.hpp"
#include "ECS/Systems/CollisionSystem/CollisionSystem.hpp"
#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/ScrollSystem/ScrollSystem.hpp"
#include "ECS/Systems/HealthSystem/HealthSystem.hpp"
#include "ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.hpp"
#include "ECS/Systems/ScoreSystem/ScoreSystem.hpp"
#include "ECS/Systems/PowerUpSystem/PowerUpSystem.hpp"
#include "ECS/Systems/EntityClassSystem/EntityClassSystem.hpp"

#include "utils/ParserClass/Parser.hpp"

#include <iostream>

void DefaultMode::init()
{
    if (m_currentLevel == m_filePath.size()) {
        m_currentLevel = 0;
    }
    Parser parser(registry, window, clock, m_filePath[m_currentLevel]);

    registry.setClock(&clock);
    registry.setWindow(&window);

    registry.register_component<Component::EntityClass>();
    registry.register_component<Component::Position>();
    registry.register_component<Component::Velocity>();
    registry.register_component<Component::Controllable>();
    registry.register_component<Component::Drawable>();
    registry.register_component<Component::AutoMove>();
    registry.register_component<Component::Shoot>();
    registry.register_component<Component::Projectile>();
    registry.register_component<Component::Collision>();
    registry.register_component<Component::Scroll>();
    registry.register_component<Component::Health>();
    registry.register_component<Component::Score>();
    registry.register_component<Component::Group>();
    registry.register_component<Component::PowerUp>();

    registry.add_system<Component::Position, Component::Velocity>(PositionSystem());
    registry.add_system<Component::Controllable, Component::Velocity>(ControlSystem());
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::AutoMove>(AutoMoveSystem());
    registry.add_system<Component::Shoot, Component::Position, Component::Drawable, Component::Group>(ShootSystem());
    registry.add_system<Component::Projectile, Component::Position, Component::Velocity>(ProjectileSystem());
    registry.add_system<Component::Position, Component::Collision>(CollisionSystem());
    registry.add_system<Component::Position, Component::Scroll>(ScrollSystem());
    registry.add_system<Component::Health, Component::Position>(HealthSystem());
    registry.add_system<Component::Score>(ScoreSystem());
    registry.add_system<Component::Projectile, Component::Collision, Component::Health, Component::Score, Component::Group>(ProjectileCollisionSystem());
    registry.add_system<Component::EntityClass,Component::Controllable, Component::Collision, Component::PowerUp>(PowerUpSystem());
    registry.add_system<Component::EntityClass, Component::Shoot, Component::Health, Component::Velocity>(EntityClassSystem());

    parser.loadFromFile();
    m_isAPlayerCreated = false;
}

void DefaultMode::run()
{
    tcpServer->run();
    sf::Time lastUpdate = clock.getElapsedTime();
    sf::Time lastLagRefresh = clock.getElapsedTime();
    while (true) {
        if (tcpServer->getNbClients() == 0) {
            continue;
        }
        if (clock.getElapsedTime().asMilliseconds() - lastUpdate.asMilliseconds() < 1000 / TICKRATE) {
            continue;
        } else {
            lastUpdate = clock.getElapsedTime();
        }
        registry.run_systems();
        if (m_isAPlayerCreated && registry.playersAreDead()) {
            packet_t packet;

            packet.messageType = LOSE_CODE;
            udpServer->send(converter.convertStructToBinary(packet));
            registry = Registry();
            init();
        }
        if (registry.enemiesAreDead()) {
            packet_t packet;

            m_currentLevel++;
            if (m_currentLevel == m_filePath.size()) {
                packet.messageType = END_CODE;

                udpServer->send(converter.convertStructToBinary(packet));
            } else {
                packet.messageType = WIN_CODE;
                udpServer->send(converter.convertStructToBinary(packet));
                registry = Registry();
                init();
            }
        }
        std::vector<client_packet_t> received_packets = udpServer->get_packet_queue();
        for (unsigned int i = 0; i < received_packets.size(); i++) {
            if (received_packets[i].messageType == CLIENT_INPUT_CODE && received_packets[i].input.id == 0) {
                continue;
            }
            if (received_packets[i].messageType == CLIENT_CLASS_CODE) {
                create_player(150, 450, received_packets[i].input.id, received_packets[i].entityClass);
                m_isAPlayerCreated = true;
            }
            if (received_packets[i].messageType == CLIENT_DISCONNECT_CODE) {
                try {
                    auto entity = registry.player_from_id(received_packets[i].input.id);
                    registry.kill_entity(entity);
                } catch (std::exception &e) {
                    continue;
                }
            }
            if (received_packets[i].messageType == CLIENT_INPUT_CODE) {
                registry.updateEntityKeyPressed(received_packets[i].input);
            }
        }
        if (received_packets.size() > 0) {
            udpServer->clear_packet_queue();
        }
        std::vector<packet_t> packets = registry.exportToPackets(tcpServer->isNewClient());
        if (tcpServer->isNewClient()) {
            tcpServer->setNewClient(false);
        }
        for (unsigned int i = 0; i < packets.size(); i++) {
            udpServer->send(converter.convertStructToBinary(packets[i]));
        }
        if (clock.getElapsedTime().asMilliseconds() - lastLagRefresh.asMilliseconds() > REFRESHRATE) {
            lastLagRefresh = clock.getElapsedTime();
            tcpServer->setNewClient(true);
            std::vector<packet_t> recentlyKilledPackets = registry.exportRecentlyKilledEntities();
            for (unsigned int i = 0; i < recentlyKilledPackets.size(); i++) {
                udpServer->send(converter.convertStructToBinary(recentlyKilledPackets[i]));
            }
        }
    }
}
