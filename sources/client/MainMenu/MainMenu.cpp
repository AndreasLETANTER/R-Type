/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MainMenu
*/

#include <iostream>

#include "client/MainMenu/MainMenu.hpp"

MainMenu::MainMenu::MainMenu(sf::RenderWindow &window, Assets &assets,
    Registry &registry):
    m_window(window), m_assets(assets), m_registry(registry), m_playMenu(window, assets, registry)
{
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 5;
    double buttonHeightRatio = 10;
    double textRatio = 15;
    double buttonWidth = windowSize.x / buttonWidthRatio;
    double buttonHeight = windowSize.y / buttonHeightRatio;
    double spacing = windowSize.y / 20;
    double xPos = (windowSize.x - buttonWidth) / 2;
    double yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;
    m_font = m_assets.get_font("font.ttf");

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
        .setCallback([this]() {
            PlayMenu playMenu(m_window, m_assets, m_registry);
            m_isPlayMenuOpen = true;
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
            m_window.close();
        });
    m_buttons.push_back(quitButton);
    this->resize();
}

void MainMenu::draw()
{
    if (m_isPlayMenuOpen) {
        m_playMenu.draw();
        return;
    }
    for (auto &button : m_buttons)
        button.draw(m_window);
}

void MainMenu::update()
{
    if (m_isPlayMenuOpen) {
        m_playMenu.update();
        return;
    }
    for (auto &button : m_buttons)
        button.update(m_window);
}

void MainMenu::resize()
{
    if (m_isPlayMenuOpen) {
        m_playMenu.resize();
        return;
    }
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 5;
    double buttonHeightRatio = 10;
    double textRatio = 15;
    double buttonWidth = windowSize.x / buttonWidthRatio;
    double buttonHeight = windowSize.y / buttonHeightRatio;
    double spacing = windowSize.y / 20;
    double xPos = (windowSize.x - buttonWidth) / 2;
    double yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;

    m_buttons[0].resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
    yPos += buttonHeight + spacing;
    m_buttons[1].resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
}
