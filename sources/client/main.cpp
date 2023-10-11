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
#include "client/ArgumentsHandling/ArgumentsHandling.hpp"

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
    tcpClientSocket tcpClient(8080);
    udpClientSocket udpClient(4242);
    
    handleArguments(ac, av);
    tcpClient.run();
    udpClient.run();
    Registry registry;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    window.setFramerateLimit(144);

    udpClient.send("connect");
    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::pair<message_t *, size_t> messages = converter.convertBinaryToStruct(udpClient.receive());
        registry = Registry();
        registry.importFromMessages(messages.first, messages.second, &window);
        window.clear();
        registry.run_systems();
        std::cout << "test" << std::endl;
        window.display();
    }
    return 0;
}
