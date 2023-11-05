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
 
/**
 * @class EndMenu
 * @brief Represents the end menu of the game.
 * 
 * This class is responsible for drawing and updating the end menu of the game.
 * It contains a SFML RenderWindow to draw the menu on, a vector of buttons, a font, and a boolean to check if the player wants to play again.
 */
class EndMenu {
    public:
        /**
         * @brief Constructs a EndMenu object.
         *
         * @param window The SFML RenderWindow to draw the EndMenu on.
         */
        EndMenu(sf::RenderWindow &window);

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

    private:
        sf::RenderWindow &m_window; /**< The SFML RenderWindow to draw the EndMenu on. */
        Assets m_assets; /**< The assets used by the EndMenu. */
        std::vector<std::unique_ptr<IButton>> m_buttons; /**< The vector of buttons in the EndMenu. */
        sf::Font m_font; /**< The font used by the EndMenu. */
        bool m_wantToPlayAgain = false; /**< A boolean to check if the player wants to play again. */
};
