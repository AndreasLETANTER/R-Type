/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** main
*/

#include <iostream>
#include "ECS/Systems/LoggingSystem/LoggingSystem.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"
#include "ECS/Systems/ControlSystem/ControlSystem.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Systems/AutoMoveSystem/AutoMoveSystem.hpp"
#include "ECS/Systems/ShootSystem/ShootSystem.hpp"
#include "ECS/Systems/ProjectileSystem/ProjectileSystem.hpp"
#include "ECS/Systems/CollisionSystem/CollisionSystem.hpp"
#include "ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.hpp"
#include "ECS/Systems/HealthSystem/HealthSystem.hpp"
#include "ECS/RegistryClass/Registry.hpp"
#include <SFML/Graphics.hpp>

int main(const int ac, const char **av)
{
    (void) ac;
    (void) av;
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    Registry registry;
    window.setFramerateLimit(144);
    sf::Texture texture;
    texture.loadFromFile("assets/NugoTemporaryIcon.png");
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile("assets/BurpTemporaryBullet.png");
    bulletTexture.setSmooth(true);
    sf::Sprite sprite(texture);
    sf::Sprite bulletSprite(bulletTexture);

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
    registry.register_component<Component::Health>();

    //entity that is movable, using all components.
    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));
    registry.add_component<Component::Velocity>(registry.entity_from_index(0), Component::Velocity(0, 0));
    registry.add_component<Component::Controllable>(registry.entity_from_index(0), Component::Controllable(true));
    registry.add_component<Component::Drawable>(registry.entity_from_index(0), Component::Drawable(sprite, &window));
    registry.add_component<Component::Shoot>(registry.entity_from_index(0), Component::Shoot(true, &clock, sf::Time(sf::milliseconds(250)), bulletSprite));
    registry.add_component<Component::Collision>(registry.entity_from_index(0), Component::Collision(80, 80));
    registry.add_component<Component::Health>(registry.entity_from_index(0), Component::Health(100));

    // static entities, that have drawable and position components, but not velocity.
    registry.add_component<Component::Position>(registry.entity_from_index(1), Component::Position(1000, 500));
    registry.add_component<Component::Drawable>(registry.entity_from_index(1), Component::Drawable(sprite, &window));
    registry.add_component<Component::Collision>(registry.entity_from_index(1), Component::Collision(80, 80));
    registry.add_component<Component::Health>(registry.entity_from_index(1), Component::Health(100));

    // registry.add_component<Component::Position>(registry.entity_from_index(2), Component::Position(300, 300));
    // registry.add_component<Component::Drawable>(registry.entity_from_index(2), Component::Drawable(sprite, &window));
    // registry.add_component<Component::AutoMove>(registry.entity_from_index(2), Component::AutoMove(Component::Position(300, 300), Component::Position(300, 1000)));
    // registry.add_component<Component::Collision>(registry.entity_from_index(2), Component::Collision(80, 80));
    
    // registry.add_component<Component::Position>(registry.entity_from_index(3), Component::Position(500, 500));
    // registry.add_component<Component::Drawable>(registry.entity_from_index(3), Component::Drawable(sprite, &window));
    // registry.add_component<Component::AutoMove>(registry.entity_from_index(3), Component::AutoMove(Component::Position(500, 500), Component::Position(1000, 1000)));
    // registry.add_component<Component::Collision>(registry.entity_from_index(3), Component::Collision(80, 80));

    //registry.add_system<Component::Position, Component::Velocity>(LoggingSystem());
    registry.add_system<Component::Position, Component::Velocity>(PositionSystem());
    registry.add_system<Component::Controllable, Component::Velocity>(ControlSystem());
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::AutoMove>(AutoMoveSystem());
    registry.add_system<Component::Shoot, Component::Position, Component::Drawable>(ShootSystem());
    registry.add_system<Component::Projectile, Component::Position, Component::Velocity>(ProjectileSystem());
    registry.add_system<Component::Position, Component::Collision>(CollisionSystem());
    registry.add_system<Component::Projectile, Component::Collision>(ProjectileCollisionSystem());
    registry.add_system<Component::Health>(HealthSystem());

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
