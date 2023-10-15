/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** PlayMenu
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "client/Buttons/TextButton/TextButton.hpp"
#include "ECS/Assets/Assets.hpp"
#include "ECS/RegistryClass/Registry.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"
#include "utils/handleArgument/handleArgument.hpp"
#include "client/tcpClientSocket/tcpClientSocket.hpp"
#include "client/udpClientSocket/udpClientSocket.hpp"

class PlayMenu {
public:
    PlayMenu(sf::RenderWindow &window, Assets &assets, Registry &registry);
    void draw();
    void update();
    void resize();
    void editTextButton(TextButton &button,
        const std::string &initialText, bool &isEditable,
        const long unsigned int &maxSize, const std::string &acceptedChars = "");
    void launchGame(tcpClientSocket &tcpClient, udpClientSocket &udpClient);
private:
    sf::RenderWindow &m_window;
    Assets &m_assets;
    Registry &m_registry;
    std::vector<TextButton> m_buttons;
    sf::Font m_font;
    bool m_isIpEditable = false;
    bool m_isTcpPortEditable = false;
    bool m_isUdpPortEditable = false;
    bool m_areInfosValid = false;
    binaryConverter m_converter;
};
