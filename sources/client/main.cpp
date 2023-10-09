/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/

#include <SFML/Graphics.hpp>

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Systems/ScrollSystem/ScrollSystem.hpp"
#include "client/MainMenu/MainMenu.hpp"
#include "ECS/Assets/Assets.hpp"

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hess-Type");
    Assets assets;
    Registry registry(assets);
    window.setFramerateLimit(144);
    sf::Clock clock;
    MainMenu mainMenu(window);

    registry.spawn_entity();
    registry.spawn_entity();

    registry.register_component<Component::Position>();
    registry.register_component<Component::Velocity>();
    registry.register_component<Component::Drawable>();
    registry.register_component<Component::Scroll>();

    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));
    registry.add_component<Component::Drawable>(registry.entity_from_index(0), Component::Drawable("Space_Background.png", &window, sf::IntRect(0, 0, 300, 207), Component::Position(0, 0), true, assets.get_texture("Space_Background.png")));
    registry.add_component<Component::Scroll>(registry.entity_from_index(0), Component::Scroll(Component::Position(0, 0), Component::Position(-5700, 0)));
    registry.add_component<Component::Position>(registry.entity_from_index(1), Component::Position(5700, 0));
    registry.add_component<Component::Drawable>(registry.entity_from_index(1), Component::Drawable("Space_Background.png", &window, sf::IntRect(0, 0, 300, 207), Component::Position(0, 0), true, assets.get_texture("Space_Background.png")));
    registry.add_component<Component::Scroll>(registry.entity_from_index(1), Component::Scroll(Component::Position(5700, 0), Component::Position(0, 0)));

    registry.add_system<Component::Position, Component::Velocity>(PositionSystem());
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::Scroll>(ScrollSystem());
    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                mainMenu.resize();
            }
        }
        window.clear();
        registry.run_systems();
        mainMenu.update();
        mainMenu.draw();
        window.display();
    }
    return (0);
}
