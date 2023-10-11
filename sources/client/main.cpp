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
    tcpClientSocket tcpClient(handleArguments.getPort(av[1]));
    udpClientSocket udpClient(handleArguments.getPort(av[2]));
    
    tcpClient.run();
    udpClient.run();
    tcpClient.receive();
    Registry registry;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    window.setFramerateLimit(144);

    udpClient.send(std::vector<char>({'1'}));
    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
                std::cout << "Key pressed: " << event.key.code << std::endl;
                std::cout << "zoulou" << tcpClient.getId() << std::endl;
                udpClient.send(converter.convertStructToInput(tcpClient.getId(), event.key.code));
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
