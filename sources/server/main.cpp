/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/


#include <iostream>
#include <SFML/Graphics.hpp>

#include "utils/ParserClass/Parser.hpp"
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
#include "../../build/assets/Level1Config.hpp"
#include "utils/handleArgument/handleArgument.hpp"
#include "udpSocket/udpSocket.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"

#define TICKRATE 64

int main(const int ac, const char **av)
{
    (void)ac;
    handleArgument handleArgument;
    binaryConverter converter;
    udpSocket udpServer(handleArgument.getPort(av[1]), handleArgument.getIp(av[2]));

    Registry registry;
    sf::Clock clock;
    sf::RenderWindow window;
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

    registry.add_system<Component::Position, Component::Velocity>(PositionSystem());
    registry.add_system<Component::Controllable, Component::Velocity>(ControlSystem());
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::AutoMove>(AutoMoveSystem());
    registry.add_system<Component::Shoot, Component::Position, Component::Drawable>(ShootSystem());
    registry.add_system<Component::Projectile, Component::Position, Component::Velocity>(ProjectileSystem());
    registry.add_system<Component::Position, Component::Collision>(CollisionSystem());
    registry.add_system<Component::Position, Component::Scroll>(ScrollSystem());
    registry.add_system<Component::Health>(HealthSystem());
    registry.add_system<Component::Projectile, Component::Collision, Component::Health>(ProjectileCollisionSystem());
    parser.loadFromFile();

    udpServer.run();
    char *received;
    sleep(4);
    sf::Time lastUpdate = clock.getElapsedTime();
    while (true) {
        if (clock.getElapsedTime().asMilliseconds() - lastUpdate.asMilliseconds() < 1000 / TICKRATE) {
            continue;
        } else {
            lastUpdate = clock.getElapsedTime();
        }
        registry.run_systems();
        received = udpServer.receive();
        if (received != nullptr) {
            input_t input = converter.convertBinaryToInput(received);
            if (input.id != 0) {
                registry.updateEntityKeyPressed(input);
            }
        }
        std::vector<packet_t> packets = registry.exportToPackets();
        for (unsigned int i = 0; i < packets.size(); i++) {
            udpServer.send(converter.convertStructToBinary(packets[i]));
        }
    }
}
