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
#include "client/Buttons/TextButton/TextButton.hpp"

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
    tcpClientSocket tcpClient(handleArguments.getPort(av[1]), handleArguments.getIp(av[3]));
    udpClientSocket udpClient(handleArguments.getPort(av[2]), handleArguments.getIp(av[3]));
    Assets assets;

    tcpClient.run();
    udpClient.run();
    tcpClient.receive();
    Registry registry;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    window.setFramerateLimit(144);
    sf::Clock clock;
    MainMenu mainMenu(window, assets);
    TextButton scoreButton = TextButton()
        .setButtonPosition(sf::Vector2f(0, 0))
        .setButtonSize(window.getSize(), sf::Vector2f(10, 10))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::Transparent)
        .setButtonOutlineThickness(1)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Transparent)
        .setTextString("Score: ")
        .setTextSize(window.getSize(), 15)
        .setTextFont(assets.get_font("font.ttf"))
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Transparent)
        .setCallback([]() {
        });

    sf::Keyboard::Key lastKey = sf::Keyboard::Unknown;

    while (window.isOpen()) {
        udpClient.send(std::vector<char>({'1'}));
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code != lastKey) {
                    lastKey = event.key.code;
                    udpClient.send(converter.convertStructToInput(tcpClient.getId(), event.key.code));
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == lastKey) {
                    lastKey = sf::Keyboard::Unknown;
                    udpClient.send(converter.convertStructToInput(tcpClient.getId(), sf::Keyboard::Unknown));
                }
            }
        }
        std::pair<message_t *, size_t> messages = converter.convertBinaryToStruct(udpClient.receive());
        registry = Registry();
        registry.importFromMessages(messages.first, messages.second, &window);
        window.clear();
        registry.run_systems();
        scoreButton.draw(window);
        mainMenu.draw();
        window.display();
    }
    return 0;
}
