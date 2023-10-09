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

#include "handleArgument/handleArgument.hpp"
#include "tcpSocket/tcpSocket.hpp"
#include "udpSocket/udpSocket.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"

int main(const int ac, const char **av)
{
    (void)ac;
    handleArgument handleArgument;
    binaryConverter converter;
    // tcpSocket server(handleArgument.getPort(av[1]));
    udpSocket udpServer(handleArgument.getPort(av[2]));
    
    Registry registry;
    registry.register_component<Component::Position>();
    registry.register_component<Component::Velocity>();
    registry.register_component<Component::Drawable>();
    auto entity1 = registry.spawn_entity();
    registry.add_component<Component::Position>(entity1, Component::Position(0, 0));
    registry.add_component<Component::Velocity>(entity1, Component::Velocity(0, 0));
    registry.add_component<Component::Drawable>(entity1, Component::Drawable("NugoTemporaryIcon.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), false));
    message_t *messages = registry.exportToMessages().first;
    size_t size = registry.exportToMessages().second;
    // server.run();
    udpServer.run();


    char *buffer = udpServer.receive();
    
    std::cout << "buffer: " << buffer << std::endl;
    while (true) {
        udpServer.send(converter.convertStructToBinary(size, messages));
        // sleep(1); disable this line if you are a terrorist
    }
    // while (true) {
    //     udpServer.send(
    // }
    // std::cout << "buffer: " << buffer << std::endl;
    // return 0;
}
