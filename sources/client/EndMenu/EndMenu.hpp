/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EndMenu
*/

#pragma once

#define _WIN32_WINNT	0x0601

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "ECS/Assets/Assets.hpp"
#include "client/Buttons/IButton.hpp"
 
#include "client/Buttons/ButtonFactory/ButtonFactory.hpp"
#include "client/udpClientSocket/udpClientSocket.hpp"

/**
 * @class EndMenu
 * @brief Represents the end menu of the game.
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

        /**
         * @brief Draws the EndMenu on the SFML RenderWindow.
         */
        void draw();

        /**
         * @brief Updates the EndMenu.
         */
        void update();

        /**
         * @brief Resizes the EndMenu.
         */
        void resize();

        /**
         * @brief Returns whether the player wants to play again.
         *
         * @return True if the player wants to play again, false otherwise.
         */
        bool wantToPlayAgain() const {return m_wantToPlayAgain;};
    private:
        sf::RenderWindow &m_window; /**< The SFML RenderWindow to draw the EndMenu on. */
        udpClientSocket &m_udpClient; /**< The udpClientSocket to send the Restart message to the server. */
        Assets m_assets; /**< The assets used by the EndMenu. */
        std::vector<std::unique_ptr<IButton>> m_buttons; /**< The buttons of the EndMenu. */
        sf::Font m_font; /**< The font used by the EndMenu. */
        bool m_wantToPlayAgain = false; /**< Whether the player wants to play again. */
};
