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
#include "client/RestartMenu/RestartMenu.hpp"

/**
 * @brief Updates the game state by processing packets received from the server.
 *
 * @param udpClient The UDP client socket used to receive packets.
 * @param tcpClient The TCP client socket used to receive packets.
 * @param registry The entity registry used to update the game state.
 * @param window The SFML window used to render the game.
 */
static void update_game_from_packets(udpClientSocket &udpClient, tcpClientSocket &tcpClient, Registry &registry, sf::RenderWindow *window, std::unique_ptr<IButton> &scoreButton)
{
    std::vector<packet_t> packets = udpClient.get_packet_queue();
    for (unsigned int i = 0; i < packets.size(); i++) {
        if (packets[i].messageType == LOSE_CODE) {
            RestartMenu restartMenu(*window, tcpClient, udpClient);
            while (window->isOpen() && !restartMenu.isCallbackCalled()) {
                for (auto event = sf::Event{}; window->pollEvent(event);) {
                    if (event.type == sf::Event::Closed) {
                        window->close();
                        exit(0);
                    }
                }
                window->clear();
                registry.run_systems();
                restartMenu.update();
                restartMenu.draw();
                window->display();
            }
            for (auto entity : registry.getEntities()) {
                if (entity.has_value())
                    registry.kill_entity(entity.value().first);
            }
        }
        if (packets[i].messageType == NO_MORE_GAME_INFO_CODE) {
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
    ButtonFactory buttonFactory;
    Assets assets;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    window.setFramerateLimit(144);
    sf::Clock clock;
    Registry registry(assets, &window, &clock);

    registry.register_component<Component::Drawable>();
    registry.register_component<Component::Position>();
    registry.register_component<Component::Score>();
    registry.register_component<Component::Scroll>();
    registry.add_system<Component::Position, Component::Drawable>(DrawSystem());
    registry.add_system<Component::Position, Component::Scroll>(ScrollSystem());

    MainMenu mainMenu(window, assets, registry);
    mainMenu.loadBackground(&window, registry);
    bool firstTime = true;
    assets.get_music("MenuMusic")->setLoop(true);
    assets.get_music("MenuMusic")->play();
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
    unsigned int tcp = mainMenu.getTCPPort();
    unsigned int udp = mainMenu.getUDPPort();
    boost::asio::ip::address ip = mainMenu.getIp();
    mainMenu.deleteButtons(registry);
    mainMenu.loadClass(&window, registry);
    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }
        }
        window.clear();
        registry.run_systems();
        mainMenu.update();
        mainMenu.drawClass();
        window.display();
        if (mainMenu.m_nugoSelected == true || mainMenu.m_andreasSelected == true || mainMenu.m_eliotSelected == true || mainMenu.m_louisSelected == true) {
            break;
        }
    }
    assets.get_music("MenuMusic")->setLoop(false);
    assets.get_music("MenuMusic")->stop();
    mainMenu.deleteBackground(registry);
    mainMenu.deleteClass(registry);
    tcpClientSocket tcpClient(tcp, ip);
    udpClientSocket udpClient(udp, ip);
    udpClient.send(converter.convertInputToBinary(client_packet_t{CLIENT_INPUT_CODE, EntityClasses::ANDREAS, input_t{0, sf::Keyboard::Unknown, false}}));
    tcpClient.run();
    tcpClient.receive();
    if (firstTime == true) {
        if (mainMenu.m_andreasSelected == true) {
            udpClient.send(converter.convertInputToBinary(client_packet_t{CLIENT_CLASS_CODE, EntityClasses::ANDREAS, input_t{tcpClient.getId(), sf::Keyboard::Unknown, false}}));
        }
        if (mainMenu.m_nugoSelected == true) {
            udpClient.send(converter.convertInputToBinary(client_packet_t{CLIENT_CLASS_CODE, EntityClasses::NUGO, input_t{tcpClient.getId(), sf::Keyboard::Unknown, false}}));
        }
        if (mainMenu.m_eliotSelected == true) {
            udpClient.send(converter.convertInputToBinary(client_packet_t{CLIENT_CLASS_CODE, EntityClasses::ELIOT, input_t{tcpClient.getId(), sf::Keyboard::Unknown, false}}));
        }
        if (mainMenu.m_louisSelected == true) {
            udpClient.send(converter.convertInputToBinary(client_packet_t{CLIENT_CLASS_CODE, EntityClasses::LOUIS, input_t{tcpClient.getId(), sf::Keyboard::Unknown, false}}));
        }
        firstTime = false;
    }

    std::unique_ptr<IButton> scoreButton = buttonFactory.createButton("OneUse");
    scoreButton
    ->setButtonPosition(sf::Vector2f(30, 0))
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
    InputHandler inputHandler(tcpClient.getId());
    assets.get_music("BackgroundMusic")->setLoop(true);
    assets.get_music("BackgroundMusic")->play();
    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
                udpClient.send(converter.convertInputToBinary(client_packet_t{CLIENT_DISCONNECT_CODE, EntityClasses::ANDREAS, input_t{tcpClient.getId(), sf::Keyboard::Unknown, false}}));
                exit(0);
            }
        }
        std::vector<client_packet_t> packets = inputHandler.handle_inputs();
        for (unsigned int i = 0; i < packets.size(); i++) {
            udpClient.send(converter.convertInputToBinary(packets[i]));
        }
        update_game_from_packets(udpClient, tcpClient, registry, &window, scoreButton);
        window.clear();
        registry.run_systems();
        scoreButton->update(window);
        scoreButton->draw(window);
        window.display();
    }
    return 0;
}
