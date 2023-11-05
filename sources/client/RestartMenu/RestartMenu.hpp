/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** RestartMenu
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "client/tcpClientSocket/tcpClientSocket.hpp"
#include "client/udpClientSocket/udpClientSocket.hpp"
#include "ECS/Assets/Assets.hpp"

class RestartMenu {
    public:
        RestartMenu(sf::RenderWindow &window, tcpClientSocket &tcpClient, udpClientSocket &udpClient, bool isWin);
        void draw();
        void update();
        void resize();
        bool isCallbackCalled() const {return m_isCallbackCalled;};
    private:
        sf::RenderWindow &m_window;
        tcpClientSocket &m_tcpClient;
        udpClientSocket &m_udpClient;
        bool m_isWin;
        std::vector<std::unique_ptr<IButton>> m_buttons;
        Assets m_assets;
        sf::Font m_font;
        bool m_isCallbackCalled = false;
};
