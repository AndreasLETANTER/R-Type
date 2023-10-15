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
    MainMenu mainMenu(window, assets);
    PlayMenu playMenu(window, assets, registry);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                playMenu.resize();
            }
        }
        // std::pair<message_t *, size_t> messages = converter.convertBinaryToStruct(udpClient.receive());
        registry = Registry();
        // registry.importFromMessages(messages.first, messages.second, &window);
        window.clear();
        playMenu.draw();
        playMenu.update();
        // registry.run_systems();
        window.display();
    }
    return 0;
}
