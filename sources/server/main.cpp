/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ECS/Systems/LoggingSystem/LoggingSystem.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"
#include "ECS/Systems/ControlSystem/ControlSystem.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Systems/AutoMoveSystem/AutoMoveSystem.hpp"
#include "ECS/Systems/ShootSystem/ShootSystem.hpp"
#include "ECS/Systems/ProjectileSystem/ProjectileSystem.hpp"
#include "ECS/Systems/CollisionSystem/CollisionSystem.hpp"
#include "ECS/RegistryClass/Registry.hpp"

int main(const int ac, const char **av)
{
    (void) ac;
    (void) av;
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    Registry registry;
    Registry registry2;
    window.setFramerateLimit(144);

    sf::Clock clock;

    registry.spawn_entity();
    registry.spawn_entity();
    // registry.spawn_entity();
    // registry.spawn_entity();

    registry.register_component<Component::Position>();
    registry.register_component<Component::Velocity>();
    registry.register_component<Component::Controllable>();
    registry.register_component<Component::Drawable>();
    registry.register_component<Component::AutoMove>();
    registry.register_component<Component::Shoot>();
    registry.register_component<Component::Projectile>();
    registry.register_component<Component::Collision>();

    //entity that is movable, using all components.
    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));
    registry.add_component<Component::Velocity>(registry.entity_from_index(0), Component::Velocity(0, 0));
    registry.add_component<Component::Controllable>(registry.entity_from_index(0), Component::Controllable(true));
    registry.add_component<Component::Drawable>(registry.entity_from_index(0), Component::Drawable("NugoTemporaryIcon.png", &window, true));
    registry.add_component<Component::Shoot>(registry.entity_from_index(0), Component::Shoot(true, &clock, sf::Time(sf::milliseconds(250)), 10, "BurpTemporaryBullet.png"));
    registry.add_component<Component::Collision>(registry.entity_from_index(0), Component::Collision(80, 80));

    registry.add_system<Component::Position, Component::Velocity>(PositionSystem());
    registry.add_system<Component::Controllable, Component::Velocity>(ControlSystem());
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::AutoMove>(AutoMoveSystem());
    registry.add_system<Component::Shoot, Component::Position, Component::Drawable>(ShootSystem());
    registry.add_system<Component::Projectile, Component::Position, Component::Velocity>(ProjectileSystem());
    registry.add_system<Component::Position, Component::Collision>(CollisionSystem());

    registry2.importFromMessages(registry.exportToMessages().first, registry.exportToMessages().second, &window);
    registry2.add_system<Component::Position, Component::Drawable>(DrawSystem());
    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        registry2.run_systems();
        window.display();
    }
}

// #include "udpSocket/udpSocket.hpp"
// #include "handleArgument/handleArgument.hpp"


// int main(int ac, char **av)
// {
//     (void)ac;
//     handleArgument handleArgument;
//     udpSocket server(handleArgument.getPort(av[1]), handleArgument.getPort(av[2]));

//     while (true) {
//         server.start();
//     }
//     return 0;
// }