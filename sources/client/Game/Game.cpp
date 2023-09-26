/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Game
*/

#include "Game.hpp"

#include "../Background/Background.hpp"
#include "../../../build/assets/Space_Background.hpp"

Game::Game():
    m_window(sf::VideoMode(1920, 1080), "R-Type")
{
    m_background.loadTexture(___assets_Space_Background_png, ___assets_Space_Background_png_len);
    m_background.setSize(m_window.getSize());
}

void Game::run()
{
    while (m_window.isOpen()) {
        processEvents();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}

void Game::render() {
    m_window.clear();
    m_background.draw(m_window);
    m_window.display();
}
