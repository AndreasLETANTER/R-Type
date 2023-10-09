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
    sf::Clock clock;
    sf::RenderWindow window;
    std::vector<std::string> filePath = {"./assets/Level1.yaml"};
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
   
    // server.run();
    udpServer.run();


    udpServer.receive();
    
    //std::cout << "buffer: " << buffer << std::endl;
    while (true) {
        registry.run_systems();
        std::pair<message_t *, size_t> messages = registry.exportToMessages();
        udpServer.send(converter.convertStructToBinary(messages.second, messages.first));
        //sleep(0.1); // disable this line if you are a terrorist
    }
    // while (true) {
    //     udpServer.send(
    // }
    // std::cout << "buffer: " << buffer << std::endl;
    // return 0;
}
