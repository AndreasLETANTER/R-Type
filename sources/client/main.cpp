/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Systems/ScrollSystem/ScrollSystem.hpp"
#include "client/MainMenu/MainMenu.hpp"
#include "client/Network/Network.hpp"
#include "utils/handleArgument/handleArgument.hpp"

#include "client/tcpClientSocket/tcpClientSocket.hpp"
#include "client/udpClientSocket/udpClientSocket.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"
#include "ECS/Assets/Assets.hpp"
#include "client/PlayMenu/PlayMenu.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    Assets assets;
    Registry registry(assets);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    window.setFramerateLimit(144);

    registry.register_component<Component::Position>();
    registry.register_component<Component::Drawable>();
    registry.register_component<Component::Scroll>();

    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::Scroll>(ScrollSystem());

    registry.spawn_entity();
    registry.spawn_entity();

    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));
    registry.add_component<Component::Drawable>(registry.entity_from_index(0), Component::Drawable("Space_Background.png", &window, sf::IntRect(0, 0, 300, 207), Component::Position(1920, 1080), registry.get_assets().get_texture("Space_Background.png")));
    registry.add_component<Component::Scroll>(registry.entity_from_index(0), Component::Scroll(Component::Position(0, 0), Component::Position(-5700, 0)));

    registry.add_component<Component::Position>(registry.entity_from_index(1), Component::Position(5700, 0));
    registry.add_component<Component::Drawable>(registry.entity_from_index(1), Component::Drawable("Space_Background.png", &window, sf::IntRect(0, 0, 300, 207), Component::Position(1920, 1080), registry.get_assets().get_texture("Space_Background.png")));
    registry.add_component<Component::Scroll>(registry.entity_from_index(1), Component::Scroll(Component::Position(0, 0), Component::Position(0, 0)));

    MainMenu mainMenu(window, assets, registry);
    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                mainMenu.resize();
            }
        }
        window.clear();
        registry.run_systems();
        mainMenu.draw();
        mainMenu.update();
        window.display();
    }
    return 0;
}
