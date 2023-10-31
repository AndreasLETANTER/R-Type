/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** EndlessMode
*/

#include "EndlessMode.hpp"

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
#include "ECS/Systems/WaveSystem/WaveSystem.hpp"
#include "ECS/Systems/PowerUpSystem/PowerUpSystem.hpp"
#include "ECS/Systems/EntityClassSystem/EntityClassSystem.hpp"

#include "../../../../build/assets/Level1Config.hpp"

#include "utils/ParserClass/Parser.hpp"

#include <iostream>

void EndlessMode::init()
{
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
    registry.add_system<Component::Health>(HealthSystem());
    registry.add_system<Component::Score>(ScoreSystem());
    registry.add_system<Component::Projectile, Component::Collision, Component::Health, Component::Score, Component::Group>(ProjectileCollisionSystem());
    registry.add_system<Component::Controllable, Component::Collision, Component::PowerUp>(PowerUpSystem());
    registry.add_system<Component::EntityClass, Component::Shoot, Component::Health, Component::Velocity>(EntityClassSystem());
    registry.add_system<>(WaveSystem());

    create_background();

    if (m_isMultiplayer) {
        create_player(150, 300, 1, EntityClasses::ANDREAS);
        create_player(200, 400, 2, EntityClasses::NUGO);
        create_player(150, 500, 3, EntityClasses::LOUIS);
        create_player(200, 600, 4, EntityClasses::ELIOT);
    } else {
        create_player(150, 450, 1, EntityClasses::ANDREAS);
    }
    auto tempPowerUp = registry.spawn_entity();
    Component::EntityClass entityClassTmp = Component::EntityClassFactory::CreateEntityClass(EntityClasses::ANDREAS);
    registry.add_component<Component::Group>(tempPowerUp, Component::Group(3));
    registry.add_component<Component::Position>(tempPowerUp, Component::Position(500, 500));
    registry.add_component<Component::Drawable>(tempPowerUp, Component::Drawable(entityClassTmp.assetName, &window, sf::IntRect(entityClassTmp.rect.left, entityClassTmp.rect.top, entityClassTmp.rect.width, entityClassTmp.rect.height), Component::Position(entityClassTmp.scale.x, entityClassTmp.scale.y), registry.get_assets().get_texture(entityClassTmp.assetName)));
    registry.add_component<Component::Collision>(tempPowerUp, Component::Collision(entityClassTmp.rect.height, entityClassTmp.rect.width));
    registry.add_component<Component::PowerUp>(tempPowerUp, Component::PowerUp(sf::Time(sf::seconds(10)), PowerUpType::AttackSpeed, &clock, 100));
}

void EndlessMode::run()
{
    tcpServer->run();
    sf::Time lastUpdate = clock.getElapsedTime();
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
        std::vector<input_t> inputs = udpServer->get_packet_queue();
        for (unsigned int i = 0; i < inputs.size(); i++) {
            if (inputs[i].id == 0) {
                continue;
            }
            registry.updateEntityKeyPressed(inputs[i]);
        }
        if (inputs.size() > 0) {
            udpServer->clear_packet_queue();
        }
        std::vector<packet_t> packets = registry.exportToPackets(tcpServer->isNewClient());
        if (tcpServer->isNewClient()) {
            tcpServer->setNewClient(false);
        }
        for (unsigned int i = 0; i < packets.size(); i++) {
            udpServer->send(converter.convertStructToBinary(packets[i]));
        }
    }
}
