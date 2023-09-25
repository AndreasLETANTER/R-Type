/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Game
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "../Background/Background.hpp"

class Game {
    public:
        Game();
        void run();
    private:
        void processEvents();
        void render();
        sf::RenderWindow m_window;
        Background m_background;
};
