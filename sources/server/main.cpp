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
#include "ECS/Systems/ScrollingBackgroundSystem/ScrollingBackgroundSystem.hpp"

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
    registry.spawn_entity();

    registry.register_component<Component::Position>();
    registry.register_component<Component::Velocity>();
    registry.register_component<Component::Controllable>();
    registry.register_component<Component::Drawable>();
    registry.register_component<Component::AutoMove>();
    registry.register_component<Component::Shoot>();
    registry.register_component<Component::Projectile>();
    registry.register_component<Component::Collision>();
    registry.register_component<Component::ScrollingBackground>();

    // Background
    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));
    registry.add_component<Component::Drawable>(registry.entity_from_index(0), Component::Drawable("Space_Background.png", &window, sf::IntRect(0, 0, 300, 207), true, true));
    registry.add_component<Component::ScrollingBackground>(registry.entity_from_index(0), Component::ScrollingBackground(Component::Position(0, 0), Component::Position(-5700, 0)));
    registry.add_component<Component::Position>(registry.entity_from_index(1), Component::Position(5700, 0));
    registry.add_component<Component::Drawable>(registry.entity_from_index(1), Component::Drawable("Space_Background.png", &window, sf::IntRect(0, 0, 300, 207), true, true));
    registry.add_component<Component::ScrollingBackground>(registry.entity_from_index(1), Component::ScrollingBackground(Component::Position(5700, 0), Component::Position(0, 0)));

    //entity that is movable, using all components.
    registry.add_component<Component::Position>(registry.entity_from_index(2), Component::Position(0, 0));
    registry.add_component<Component::Velocity>(registry.entity_from_index(2), Component::Velocity(0, 0));
    registry.add_component<Component::Controllable>(registry.entity_from_index(2), Component::Controllable(true));
    registry.add_component<Component::Drawable>(registry.entity_from_index(2), Component::Drawable("NugoTemporaryIcon.png", &window, sf::IntRect(0, 0, 0, 0), true, false));
    registry.add_component<Component::Shoot>(registry.entity_from_index(2), Component::Shoot(true, &clock, sf::Time(sf::milliseconds(250)), 20, "BurpTemporaryBullet.png"));
    registry.add_component<Component::Collision>(registry.entity_from_index(2), Component::Collision(80, 80));

    registry.add_system<Component::Position, Component::Velocity>(PositionSystem());
    registry.add_system<Component::Controllable, Component::Velocity>(ControlSystem());
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::AutoMove>(AutoMoveSystem());
    registry.add_system<Component::Shoot, Component::Position, Component::Drawable>(ShootSystem());
    registry.add_system<Component::Projectile, Component::Position, Component::Velocity>(ProjectileSystem());
    registry.add_system<Component::Position, Component::Collision>(CollisionSystem());
    registry.add_system<Component::Position, Component::ScrollingBackground>(ScrollingBackgroundSystem());

    registry2.importFromMessages(registry.exportToMessages().first, registry.exportToMessages().second, &window, sf::IntRect(0, 0, 0, 0));
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
