/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EndMenu
*/

#include "client/EndMenu/EndMenu.hpp"
#include "client/Buttons/ButtonFactory/ButtonFactory.hpp"

EndMenu::EndMenu(sf::RenderWindow *window)
    : m_window(window)
{
    ButtonFactory buttonFactory;
    std::unique_ptr<IButton> winButton = buttonFactory.createButton("Default");
    sf::Vector2u windowSize = m_window->getSize();
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
        .setButtonSize(window->getSize(), sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::Transparent)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Transparent)
        .setTextString("You Win!")
        .setTextSize(window->getSize(), textRatio)
        .setTextFont(m_font)
        .setTextPosition(IButton::CENTER, IButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::White)
        .setCallback([]() {
        });
    m_buttons.push_back(std::move(winButton));
    this->resize();
}

void EndMenu::draw()
{
    for (auto &button : m_buttons) {
        button->draw(m_window);
    }
}

void EndMenu::update()
{
    for (auto &button : m_buttons) {
        button->update(m_window);
    }
}

void EndMenu::resize()
{
    sf::Vector2u windowSize = m_window->getSize();
    double buttonWidthRatio = 5;
    double buttonHeightRatio = 10;
    double textRatio = 15;
    double buttonWidth = windowSize.x / buttonWidthRatio;
    double buttonHeight = windowSize.y / buttonHeightRatio;
    double xPos = (windowSize.x - buttonWidth) / 2;
    double yPos = (windowSize.y - (2 * buttonHeight)) / 2;

    m_buttons[0]->resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
}
