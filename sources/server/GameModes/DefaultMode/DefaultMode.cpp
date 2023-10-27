/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** DefaultMode
*/

#include "DefaultMode.hpp"

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

#include "../../../../build/assets/Level1Config.hpp"

#include "utils/ParserClass/Parser.hpp"

#include <iostream>

void DefaultMode::init()
{
    std::vector<std::string> filePath = {Level1Config};
    Parser parser(registry, window, clock, filePath);

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

    registry.add_system<Component::Position, Component::Velocity>(PositionSystem());
    registry.add_system<Component::Controllable, Component::Velocity>(ControlSystem());
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::AutoMove>(AutoMoveSystem());
    registry.add_system<Component::Shoot, Component::Position, Component::Drawable>(ShootSystem());
    registry.add_system<Component::Projectile, Component::Position, Component::Velocity>(ProjectileSystem());
    registry.add_system<Component::Position, Component::Collision>(CollisionSystem());
    registry.add_system<Component::Position, Component::Scroll>(ScrollSystem());
    registry.add_system<Component::Health>(HealthSystem());
    registry.add_system<Component::Score>(ScoreSystem());
    registry.add_system<Component::Projectile, Component::Collision, Component::Health, Component::Score, Component::Group>(ProjectileCollisionSystem());

    parser.loadFromFile();
}

void DefaultMode::run()
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
