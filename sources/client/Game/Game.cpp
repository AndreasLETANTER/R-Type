/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Game
*/

#include "client/Game/Game.hpp"
#include "assets/Space_Background.hpp"

Game::Game():
    m_window(sf::VideoMode(1920, 1080), "R-Type"), m_timeAccumulator(0.0f), m_scrollSpeed(5.0f)
{
    m_background.loadTexture(___assets_Space_Background_png, ___assets_Space_Background_png_len);
    m_background.setSize(m_window.getSize());
}

void Game::run()
{
    while (m_window.isOpen()) {
        sf::Time elapsed = m_clock.restart();
        float dt = elapsed.asSeconds();
        processEvents();
        m_timeAccumulator += dt;
        while (m_timeAccumulator >= 0.1f) {
            m_timeAccumulator -= 0.1f;
            doParallax();
        }
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

void Game::doParallax()
{
    m_background.move(-m_scrollSpeed);
    m_background.resetPosition();
}

void Game::render() {
    m_window.clear();
    m_background.draw(m_window);
    m_window.display();
}
