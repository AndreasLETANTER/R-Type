/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MainMenu
*/

#include <iostream>

#include "client/MainMenu/MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow &window):
    m_window(window)
{
    sf::Vector2u windowSize = m_window.getSize();
    float buttonWidth = 200;
    float buttonHeight = 100;
    float spacing = 50;
    float xPos = (windowSize.x - buttonWidth) / 2;
    float yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;

    TextButton playButton = TextButton()
        .setButtonPosition(sf::Vector2f(xPos, yPos))
        .setButtonSize(sf::Vector2f(buttonWidth, buttonHeight))
        .setButtonColor(sf::Color::Red)
        .setButtonOutlineColor(sf::Color::Blue)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Green)
        .setButtonHoverOutlineColor(sf::Color::Yellow)
        .setTextString("Play")
        .setTextSize(50)
        .setTextFont(m_font)
        .setTextPosition(sf::Vector2f(xPos + 50, yPos + 25))
        .setTextColor(sf::Color::Black)
        .setTextHoverColor(sf::Color::Black)
        .setCallback([]() {
            std::cout << "Play button clicked" << std::endl;
        });
    m_buttons.push_back(playButton);
    yPos += buttonHeight + spacing;
    TextButton quitButton = TextButton()
        .setButtonPosition(sf::Vector2f(xPos, yPos))
        .setButtonSize(sf::Vector2f(buttonWidth, buttonHeight))
        .setButtonColor(sf::Color::Red)
        .setButtonOutlineColor(sf::Color::Blue)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Green)
        .setButtonHoverOutlineColor(sf::Color::Yellow)
        .setTextString("Quit")
        .setTextFont(m_font)
        .setTextPosition(sf::Vector2f(xPos + 50, yPos + 25))
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Black)
        .setCallback([this]() {
            m_window.close();
        });
    m_buttons.push_back(quitButton);
}

void MainMenu::draw()
{
    for (auto &button : m_buttons)
        button.draw(m_window);
}

void MainMenu::update()
{
    for (auto &button : m_buttons)
        button.update(m_window);
}
