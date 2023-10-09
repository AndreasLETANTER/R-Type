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

int main(const int ac, const char **av)
{
    (void) ac;
    (void) av;
    Registry registry;
    sf::RenderWindow window {sf::VideoMode(1920, 1080), "R-Type" };
    sf::Clock clock;
    std::vector<std::string> filesContents = {LevelConfig::Level1Config};
    Parser parser(registry, window, clock, filesContents);

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
    window.setFramerateLimit(144);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        registry.run_systems();
        window.display();
    }
}
