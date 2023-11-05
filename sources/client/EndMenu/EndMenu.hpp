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
 * @brief Class to create the end menu with Restart and Quit buttons
 */
class EndMenu {
    public:
        /**
         * @brief Constructs a EndMenu object.
         *
         * @param window The SFML RenderWindow to draw the EndMenu on.
         */
        EndMenu(sf::RenderWindow &window);

        void draw();
        void update();
        void resize();
    private:
        sf::RenderWindow &m_window;
        Assets m_assets;
        std::vector<std::unique_ptr<IButton>> m_buttons;
        sf::Font m_font;
        bool m_wantToPlayAgain = false;
};
