/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** main
*/

#include <iostream>
#include "Systems/LoggingSystem/LoggingSystem.hpp"
#include "Systems/PositionSystem/PositionSystem.hpp"
#include "Systems/ControlSystem/ControlSystem.hpp"
#include "Systems/DrawSystem/DrawSystem.hpp"
#include "Systems/AutoMoveSystem/AutoMoveSystem.hpp"
#include "RegistryClass/Registry.hpp"
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
    sf::Sprite sprite(texture);

    registry.spawn_entity();
    registry.spawn_entity();
    registry.spawn_entity();
    registry.spawn_entity();

    registry.register_component<Component::Position>();
    registry.register_component<Component::Velocity>();
    registry.register_component<Component::Controllable>();
    registry.register_component<Component::Drawable>();
    registry.register_component<Component::AutoMove>();

    //entity that is movable, using all components.
    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));
    registry.add_component<Component::Velocity>(registry.entity_from_index(0), Component::Velocity(0, 0));
    registry.add_component<Component::Controllable>(registry.entity_from_index(0), Component::Controllable(true));
    registry.add_component<Component::Drawable>(registry.entity_from_index(0), Component::Drawable(sprite, &window));

    // static entities, that have drawable and position components, but not velocity.
    registry.add_component<Component::Position>(registry.entity_from_index(1), Component::Position(100, 100));
    registry.add_component<Component::Drawable>(registry.entity_from_index(1), Component::Drawable(sprite, &window));
    registry.add_component<Component::AutoMove>(registry.entity_from_index(1), Component::AutoMove(Component::Position(100, 100), Component::Position(1000, 100)));

    registry.add_component<Component::Position>(registry.entity_from_index(2), Component::Position(300, 300));
    registry.add_component<Component::Drawable>(registry.entity_from_index(2), Component::Drawable(sprite, &window));
    registry.add_component<Component::AutoMove>(registry.entity_from_index(2), Component::AutoMove(Component::Position(300, 300), Component::Position(300, 1000)));
    
    registry.add_component<Component::Position>(registry.entity_from_index(3), Component::Position(500, 500));
    registry.add_component<Component::Drawable>(registry.entity_from_index(3), Component::Drawable(sprite, &window));
    registry.add_component<Component::AutoMove>(registry.entity_from_index(3), Component::AutoMove(Component::Position(500, 500), Component::Position(1000, 1000)));

    registry.add_system<Component::Position, Component::Velocity>(LoggingSystem());
    registry.add_system<Component::Position, Component::Velocity>(PositionSystem());
    registry.add_system<Component::Controllable, Component::Velocity>(ControlSystem());
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::AutoMove>(AutoMoveSystem());

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
