/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EndingMenu
*/

#include "client/EndingMenu/EndingMenu.hpp"
#include "client/Buttons/ButtonFactory/ButtonFactory.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"

EndingMenu::EndingMenu(sf::RenderWindow &window, udpClientSocket &udpClient)
    : m_window(window),
    m_udpClient(udpClient)
{
    ButtonFactory buttonFactory;
    std::unique_ptr<IButton> winButton = buttonFactory.createButton("Default");
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 5;
    double buttonHeightRatio = 10;
    double textRatio = 15;
    double buttonWidth = windowSize.x / buttonWidthRatio;
    double buttonHeight = windowSize.y / buttonHeightRatio;
    double xPos = (windowSize.x - buttonWidth) / 2;
    double yPos = (windowSize.y - (2 * buttonHeight)) / 2;

    m_font = m_assets.get_font("font.ttf");
    winButton
        ->setButtonPosition(sf::Vector2f(xPos, yPos))
        .setButtonSize(window.getSize(), sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::Transparent)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Transparent)
        .setTextString("You Win!")
        .setTextSize(window.getSize(), textRatio)
        .setTextFont(m_font)
        .setTextPosition(IButton::CENTER, IButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::White)
        .setCallback([this]() {

        });
    m_buttons.push_back(std::move(winButton));

    yPos += buttonHeight;
    std::unique_ptr<IButton> playAgainButton = buttonFactory.createButton("OneUse");
    playAgainButton
        ->setButtonPosition(sf::Vector2f(xPos, yPos))
        .setButtonSize(window.getSize(), sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::Green)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setTextString("Play Again")
        .setTextSize(window.getSize(), textRatio)
        .setTextFont(m_font)
        .setTextPosition(IButton::CENTER, IButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Green)
        .setCallback([this]() {
            client_packet_t packet;

            packet.messageType = RESTART_CODE;

            m_udpClient.send(binaryConverter().convertInputToBinary(packet));
            m_wantToPlayAgain = true;
        });
    m_buttons.push_back(std::move(playAgainButton));
    this->resize();
}

void EndingMenu::draw()
{
    for (auto &button : m_buttons) {
        button->draw(m_window);
    }
}

void EndingMenu::update()
{
    for (auto &button : m_buttons) {
        button->update(m_window);
    }
}

void EndingMenu::resize()
{
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 5;
    double buttonHeightRatio = 10;
    double textRatio = 15;
    double buttonWidth = windowSize.x / buttonWidthRatio;
    double buttonHeight = windowSize.y / buttonHeightRatio;
    double xPos = (windowSize.x - buttonWidth) / 2;
    double yPos = (windowSize.y - (2 * buttonHeight)) / 2;

    m_buttons[0]->resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
    yPos += buttonHeight;
    m_buttons[1]->resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
}
