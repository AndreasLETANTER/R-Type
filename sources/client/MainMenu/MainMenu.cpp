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
    float buttonWidth = windowSize.x * 0.2;
    float buttonHeight = windowSize.y * 0.1;
    float spacing = windowSize.y * 0.05;
    float xPos = (windowSize.x - buttonWidth) / 2;
    float yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;

    TextButton playButton = TextButton()
        .setButtonPosition(sf::Vector2f(xPos, yPos))
        .setButtonSize(sf::Vector2f(buttonWidth, buttonHeight))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setTextString("Play")
        .setTextSize(50)
        .setTextFont(m_font)
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Green)
        .setCallback([]() {
            std::cout << "Play button clicked" << std::endl;
        });
    m_buttons.push_back(playButton);
    yPos += buttonHeight + spacing;
    TextButton quitButton = TextButton()
        .setButtonPosition(sf::Vector2f(xPos, yPos))
        .setButtonSize(sf::Vector2f(buttonWidth, buttonHeight))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Red)
        .setTextString("Quit")
        .setTextFont(m_font)
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextSize(50)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Red)
        .setCallback([this]() {
            // m_window.close();
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

void MainMenu::resize()
{
    sf::Vector2u windowSize = m_window.getSize();
    float buttonWidth = windowSize.x * 0.2;
    float buttonHeight = windowSize.y * 0.1;
    float spacing = windowSize.y * 0.05;
    float xPos = (windowSize.x - buttonWidth) / 2;
    float yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;

    m_buttons[0].resize(sf::Vector2f(buttonWidth, buttonHeight),
        sf::Vector2f(xPos, yPos), 50, TextButton::CENTER, TextButton::MIDDLE);
    yPos += buttonHeight + spacing;
    m_buttons[1].resize(sf::Vector2f(buttonWidth, buttonHeight),
        sf::Vector2f(xPos, yPos), 50, TextButton::CENTER, TextButton::MIDDLE);
}
