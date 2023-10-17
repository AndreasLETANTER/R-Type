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
#include "utils/handleArgument/handleArgument.hpp"
#include "client/udpClientSocket/udpClientSocket.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"
#include "ECS/Assets/Assets.hpp"

void signalHandler(int signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    exit(signum);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    binaryConverter converter;
    handleArgument handleArguments;
    udpClientSocket udpClient(handleArguments.getPort(av[1]), handleArguments.getIp(av[2]));
    Assets assets;

    udpClient.run();
    Registry registry;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    window.setFramerateLimit(144);
    sf::Clock clock;
    MainMenu mainMenu(window, assets);

    sf::Keyboard::Key lastKey = sf::Keyboard::Unknown;

    while (window.isOpen()) {
        udpClient.send(std::vector<char>({'1'}));
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code != lastKey) {
                    lastKey = event.key.code;
                    //udpClient.send(converter.convertStructToInput(tcpClient.getId(), event.key.code));
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == lastKey) {
                    lastKey = sf::Keyboard::Unknown;
                    //udpClient.send(converter.convertStructToInput(tcpClient.getId(), sf::Keyboard::Unknown));
                }
            }
        }
        std::pair<message_t *, size_t> messages = converter.convertBinaryToStruct(udpClient.receive());
        registry = Registry();
        registry.importFromMessages(messages.first, messages.second, &window);
        window.clear();
        registry.run_systems();
        window.display();
    }
    return 0;
}
