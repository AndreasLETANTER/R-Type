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
    m_window(window), m_assets(assets), m_registry(registry)
{
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 8;
    double buttonHeightRatio = 12;
    double textRatio = 24;
    sf::Vector2f pos = sf::Vector2f((windowSize.x / 2) - ((windowSize.x / buttonWidthRatio) / 2),
        (windowSize.y / 8));
    m_font = m_assets.get_font("font.ttf");

    std::shared_ptr title = std::make_shared<TextButton>();
    title->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setTextString("R-Type")
        .setTextFont(m_font)
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setButtonHoverColor(sf::Color::Transparent);
    m_buttons.push_back(title);

    pos.y += 150;
    pos.x -= 200;
    std::shared_ptr tcpPortButton = std::make_shared<TextButton>();
    m_buttons.emplace_back<TextButton>();
    tcpPortButton->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setTextString("TCP Port")
        .setTextSize(windowSize, textRatio)
        .setTextFont(m_font)
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Green)
        .setCallback([this, &tcpPortButton]() {
            std::cout << "tcp Clicked" << std::endl;
            tcpPortButton->setState(true);
        });
    m_buttons.push_back(tcpPortButton);

    pos.x += 400;
    std::shared_ptr udpPortButton = std::make_shared<TextButton>();
    udpPortButton->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setTextString("UDP Port")
        .setTextSize(windowSize, textRatio)
        .setTextFont(m_font)
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Green)
        .setCallback([this]() {
            std::cout << "udp Clicked" << std::endl;
        });
    m_buttons.push_back(udpPortButton);

    pos.y += 150;
    pos.x -= 200;
    std::shared_ptr ipButton = std::make_shared<TextButton>();
    ipButton->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setTextString("IP Address")
        .setTextSize(windowSize, textRatio)
        .setTextFont(m_font)
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Green)
        .setCallback([this]() {
            std::cout << "ip clicked" << std::endl;
        });
    m_buttons.push_back(ipButton);
}

void MainMenu::draw()
{
    int i = 0;
    for (auto &button : m_buttons) {
        i++;
        std::cout << "button n°" << i << " state : " << button->getState() << std::endl;
        button->draw(m_window);
    }
}

void MainMenu::update()
{
    for (auto &button : m_buttons) {
        button->update(m_window);
    }
}

void MainMenu::resize()
{
    //sf::Vector2u windowSize = m_window.getSize();
    //double buttonWidthRatio = 5;
    //double buttonHeightRatio = 10;
    //double textRatio = 15;
    //double buttonWidth = windowSize.x / buttonWidthRatio;
    //double buttonHeight = windowSize.y / buttonHeightRatio;
    //double spacing = windowSize.y / 20;
    //double xPos = (windowSize.x - buttonWidth) / 2;
    //double yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;

    /*m_buttons[0].resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
    yPos += buttonHeight + spacing;
    m_buttons[1].resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);*/
}
