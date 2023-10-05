/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MainMenu
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "client/Buttons/TextButton/TextButton.hpp"

/// @brief Class to create the main menu with Play and Quit buttons
class MainMenu {
    public:
        /// @brief Constructor of MainMenu which display a scrolling background and two buttons (Play and Quit)
        /// @param window The window where the main menu will be displayed
        MainMenu(sf::RenderWindow &window);

        /// @brief Draw the buttons on the window
        void draw();

        /// @brief Update the buttons to check if they are hovered or clicked
        void update();

        /// @brief Resize the buttons to fit the new window size
        void resize();

    private:
        sf::RenderWindow &m_window;
        std::vector<TextButton> m_buttons;
        sf::Font m_font;
};