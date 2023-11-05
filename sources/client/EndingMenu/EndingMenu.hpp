/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EndingMenu
*/

#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "ECS/Assets/Assets.hpp"
#include "client/Buttons/IButton.hpp"
 
#include "client/Buttons/ButtonFactory/ButtonFactory.hpp"
#include "client/udpClientSocket/udpClientSocket.hpp"

/**
 * @class EndingMenu
 * @brief Represents the end menu of the game.
 */
class EndingMenu {
    public:
        /**
         * @brief Constructs a EndingMenu object.
         *
         * @param window The SFML RenderWindow to draw the EndingMenu on.
         * @param udpClient The udpClientSocket to send the Restart message to the server.
         */
        EndingMenu(sf::RenderWindow &window, udpClientSocket &udpClient);

        /**
         * @brief Draws the EndingMenu on the SFML RenderWindow.
         */
        void draw();

        /**
         * @brief Updates the EndingMenu.
         */
        void update();

        /**
         * @brief Resizes the EndingMenu.
         */
        void resize();

        /**
         * @brief Returns whether the player wants to play again.
         *
         * @return True if the player wants to play again, false otherwise.
         */
        bool wantToPlayAgain() const {return m_wantToPlayAgain;};
    private:
        sf::RenderWindow &m_window; /**< The SFML RenderWindow to draw the EndingMenu on. */
        udpClientSocket &m_udpClient; /**< The udpClientSocket to send the Restart message to the server. */
        Assets m_assets; /**< The assets used by the EndingMenu. */
        std::vector<std::unique_ptr<IButton>> m_buttons; /**< The buttons of the EndingMenu. */
        sf::Font m_font; /**< The font used by the EndingMenu. */
        bool m_wantToPlayAgain = false; /**< Whether the player wants to play again. */
};
