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

void signalHandler(int signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    exit(signum);
}
#include "ECS/Assets/Assets.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    binaryConverter converter;
    handleArgument handleArguments;
    tcpClientSocket tcpClient(handleArguments.getPort(av[1]));
    udpClientSocket udpClient(handleArguments.getPort(av[2]));
    
    tcpClient.run();
    udpClient.run();
    udpClient.send("connect");
    Assets assets;
    Registry registry(assets);
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    window.setFramerateLimit(144);
    sf::Clock clock;
    MainMenu mainMenu(window, assets);

    udpClient.send("");
    unsigned int i = 0;
    while (window.isOpen()) {
        std::cout << "loop " << i << std::endl;
        i++;
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed)
                window.close();
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
