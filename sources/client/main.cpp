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
#include "client/Buttons/ButtonFactory/ButtonFactory.hpp"
#include "client/MainMenu/MainMenu.hpp"
#include "utils/HandleArgument/HandleArgument.hpp"
#include "client/tcpClientSocket/tcpClientSocket.hpp"
#include "client/udpClientSocket/udpClientSocket.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"
#include "InputHandler/InputHandler.hpp"
#include "ECS/Assets/Assets.hpp"

/**
 * @brief Updates the game state by processing packets received from the server.
 *
 * @param udpClient The UDP client socket used to receive packets.
 * @param tcpClient The TCP client socket used to receive packets.
 * @param registry The entity registry used to update the game state.
 * @param window The SFML window used to render the game.
 */
static void update_game_from_packets(udpClientSocket &udpClient, tcpClientSocket &tcpClient, Registry &registry, bool &needGameInfos, sf::RenderWindow *window, std::unique_ptr<IButton> &scoreButton)
{
    std::vector<packet_t> packets = udpClient.get_packet_queue();
    for (unsigned int i = 0; i < packets.size(); i++) {
        if (packets[i].messageType == NO_MORE_GAME_INFO_CODE) {
            needGameInfos = false;
            continue;
        }
        if (packets[i].messageType != ALL_GAME_INFO_CODE && needGameInfos == true){
            continue;
        }
        if (packets[i].messageType == ALL_GAME_INFO_CODE && needGameInfos == false) {
            continue;
        }
        registry.updateFromPacket(packets[i], window, scoreButton, tcpClient.getId());
    }
    if (packets.size() > 0) {
        udpClient.clear_packet_queue();
    }
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    binaryConverter converter;
    HandleArgument handleArguments;
    tcpClientSocket tcpClient(handleArguments.getPort(av[1]), handleArguments.getIp(av[3]));
    udpClientSocket udpClient(handleArguments.getPort(av[2]), handleArguments.getIp(av[3]));
    bool needGameInfos = true;
    ButtonFactory buttonFactory;

    udpClient.send(converter.convertInputToBinary(input_t{0, sf::Keyboard::Unknown, false}));
    tcpClient.run();
    tcpClient.receive();
    InputHandler inputHandler(tcpClient.getId());
    Assets assets;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    sf::Clock clock;
    Registry registry(assets, &window, &clock);

    registry.register_component<Component::Drawable>();
    registry.register_component<Component::Position>();
    registry.register_component<Component::Score>();
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());

    window.setFramerateLimit(144);
    MainMenu mainMenu(window, assets);
    std::unique_ptr<IButton> scoreButton = buttonFactory.createButton("Text");
    scoreButton
        ->setButtonPosition(sf::Vector2f(50, 10))
        .setButtonSize(window.getSize(), sf::Vector2f(10, 10))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::Transparent)
        .setButtonOutlineThickness(1)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Transparent)
        .setTextString("Score: 0")
        .setTextSize(window.getSize(), 20)
        .setTextFont(assets.get_font("font.ttf"))
        .setTextPosition(IButton::CENTER, IButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Transparent)
        .setCallback([]() {
        });

    assets.get_music("BackgroundMusic")->setLoop(true);
    assets.get_music("BackgroundMusic")->play();
    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }
        }
        std::vector<input_t> inputs = inputHandler.handle_inputs();
        for (unsigned int i = 0; i < inputs.size(); i++) {
            udpClient.send(converter.convertInputToBinary(inputs[i]));
        }
        update_game_from_packets(udpClient, tcpClient, registry, needGameInfos, &window, scoreButton);
        window.clear();
        registry.run_systems();
        scoreButton->update(window);
        scoreButton->draw(window);
        window.display();
    }
    return 0;
}
