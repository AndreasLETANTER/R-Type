/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EndMenu
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "ECS/Assets/Assets.hpp"
#include "client/Buttons/IButton.hpp"
#include "client/Buttons/ButtonFactory/ButtonFactory.hpp"
#include "client/udpClientSocket/udpClientSocket.hpp"

/**
 * @brief Class to create the end menu with Restart and Quit buttons
 */
class EndMenu {
    public:
        /**
         * @brief Constructs a EndMenu object.
         *
         * @param window The SFML RenderWindow to draw the EndMenu on.
         * @param udpClient The udpClientSocket to send the Restart message to the server.
         */
        EndMenu(sf::RenderWindow &window, udpClientSocket &udpClient);

        void draw();
        void update();
        void resize();

        bool wantToPlayAgain() const {return m_wantToPlayAgain;};
    private:
        sf::RenderWindow &m_window;
        udpClientSocket &m_udpClient;
        Assets m_assets;
        std::vector<std::unique_ptr<IButton>> m_buttons;
        sf::Font m_font;
        bool m_wantToPlayAgain = false;
};
