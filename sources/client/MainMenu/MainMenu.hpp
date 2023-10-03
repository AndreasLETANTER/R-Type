/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MainMenu
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "client/Buttons/TextButton/TextButton.hpp"

class MainMenu {
    public:
        MainMenu(sf::RenderWindow &window);

        void draw();
        void update();

    private:
        sf::RenderWindow &m_window;
        std::vector<TextButton> m_buttons;
        sf::Font m_font;
};
