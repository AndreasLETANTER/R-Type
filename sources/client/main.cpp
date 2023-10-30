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
 * @param registry The entity registry used to update the game state.
 * @param window The SFML window used to render the game.
 */
static void update_game_from_packets(udpClientSocket &udpClient, Registry &registry, bool &needGameInfos, sf::RenderWindow *window, TextButton &scoreButton)
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
        registry.updateFromPacket(packets[i], window, scoreButton);
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
    bool needGameInfos = true;
    Assets assets;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    window.setFramerateLimit(144);
    sf::Clock clock;
    Registry registry(assets, &window, &clock);

    registry.register_component<Component::Drawable>();
    registry.register_component<Component::Position>();
    registry.register_component<Component::Scroll>();
    registry.register_component<Component::Score>();
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::Scroll>(ScrollSystem());

    registry.spawn_entity();
    registry.spawn_entity();

    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));
    registry.add_component<Component::Drawable>(registry.entity_from_index(0), Component::Drawable("SpaceBackground.png", &window, sf::IntRect(0, 0, 300, 207), Component::Position(1920, 1080), registry.get_assets().get_texture("SpaceBackground.png")));
    registry.add_component<Component::Scroll>(registry.entity_from_index(0), Component::Scroll(Component::Position(0, 0), Component::Position(-5700, 0), 0.5));
    registry.add_component<Component::Position>(registry.entity_from_index(1), Component::Position(5700, 0));
    registry.add_component<Component::Drawable>(registry.entity_from_index(1), Component::Drawable("SpaceBackground.png", &window, sf::IntRect(0, 0, 300, 207), Component::Position(1920, 1080), registry.get_assets().get_texture("SpaceBackground.png")));
    registry.add_component<Component::Scroll>(registry.entity_from_index(1), Component::Scroll(Component::Position(0, 0), Component::Position(0, 0), 0.5));

    MainMenu mainMenu(window, assets, registry);
    while (window.isOpen() && mainMenu.getButtonPressed() != 3) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }
            if (event.type == sf::Event::KeyPressed) {
                mainMenu.setKey(event.key.code);
            }
        }
        window.clear();
        registry.run_systems();
        mainMenu.update();
        mainMenu.draw();
        window.display();
    }
    registry.kill_entity(registry.entity_from_index(0));
    registry.kill_entity(registry.entity_from_index(1));
    tcpClientSocket tcpClient(mainMenu.getTCPPort(), mainMenu.getIp());
    udpClientSocket udpClient(mainMenu.getUDPPort(), mainMenu.getIp());
    udpClient.send(converter.convertInputToBinary(input_t{0, sf::Keyboard::Unknown, false}));
    tcpClient.run();
    tcpClient.receive();

    TextButton scoreButton = TextButton()
    .setButtonPosition(sf::Vector2f(0, 0))
    .setButtonSize(window.getSize(), sf::Vector2f(10, 10))
    .setButtonColor(sf::Color::Transparent)
    .setButtonOutlineColor(sf::Color::Transparent)
    .setButtonOutlineThickness(1)
    .setButtonHoverColor(sf::Color::Transparent)
    .setButtonHoverOutlineColor(sf::Color::Transparent)
    .setTextString("Score: 0")
    .setTextSize(window.getSize(), 20)
    .setTextFont(assets.get_font("font.ttf"))
    .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
    .setTextColor(sf::Color::White)
    .setTextHoverColor(sf::Color::Transparent)
    .setCallback([]() {
    });
    InputHandler inputHandler(tcpClient.getId());
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
        update_game_from_packets(udpClient, registry, needGameInfos, &window, scoreButton);
        window.clear();
        registry.run_systems();
        scoreButton.update(window);
        scoreButton.draw(window);
        window.display();
    }
    return 0;
}
