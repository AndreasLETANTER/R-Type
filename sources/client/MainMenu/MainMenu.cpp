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
    float buttonWidthRatio = 0.2;
    float buttonHeightRatio = 0.1;
    float textRatio = 15;
    float buttonWidth = windowSize.x * buttonWidthRatio;
    float buttonHeight = windowSize.y * buttonHeightRatio;
    float spacing = windowSize.y * 0.05;
    float xPos = (windowSize.x - buttonWidth) / 2;
    float yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;
    m_font.loadFromFile("assets/font.ttf");

    TextButton playButton = TextButton()
        .setButtonPosition(sf::Vector2f(xPos, yPos))
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setTextString("Play")
        .setTextSize(windowSize, textRatio)
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
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Red)
        .setTextString("Quit")
        .setTextFont(m_font)
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextSize(windowSize, textRatio)
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
    float buttonWidthRatio = 0.2;
    float buttonHeightRatio = 0.1;
    float textRatio = 15;
    float buttonWidth = windowSize.x * buttonWidthRatio;
    float buttonHeight = windowSize.y * buttonHeightRatio;
    float spacing = windowSize.y * 0.05;
    float xPos = (windowSize.x - buttonWidth) / 2;
    float yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;

    m_buttons[0].resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
    yPos += buttonHeight + spacing;
    m_buttons[1].resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
}
