/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** RestartMenu
*/

#include "client/RestartMenu/RestartMenu.hpp"
#include "client/Buttons/ButtonFactory/ButtonFactory.hpp"

RestartMenu::RestartMenu(sf::RenderWindow &window, tcpClientSocket &tcpClient, udpClientSocket &udpClient)
    : m_window(window), m_tcpClient(tcpClient), m_udpClient(udpClient)
{
    ButtonFactory buttonFactory;
    std::unique_ptr<IButton> restartButton = buttonFactory.createButton("Cooldown");
    
    m_font = m_assets.get_font("font.ttf");
    restartButton
        ->setButtonPosition(sf::Vector2f(400, 400))
        .setButtonSize(window.getSize(), sf::Vector2f(10, 10))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::Transparent)
        .setButtonOutlineThickness(1)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Transparent)
        .setTextString("Restart")
        .setTextSize(window.getSize(), 20)
        .setTextFont(m_font)
        .setTextPosition(IButton::CENTER, IButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::White)
        .setCallback([this]() {
            input_t input = {m_tcpClient.getId(), sf::Keyboard::R, false};

            m_udpClient.send(binaryConverter().convertInputToBinary(input));
        });
    m_buttons.push_back(std::move(restartButton));
    
}

void RestartMenu::draw()
{
    for (auto &button : m_buttons)
        button->draw(m_window);
}

void RestartMenu::update()
{
    for (auto &button : m_buttons)
        button->update(m_window);
}

void RestartMenu::resize()
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

    m_buttons[0]->resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
}