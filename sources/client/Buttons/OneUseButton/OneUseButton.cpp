/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** OneUseButton
*/

#include "client/Buttons/OneUseButton/OneUseButton.hpp"

#include <iostream>

void OneUseButton::update(sf::RenderWindow &window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    const sf::Vector2f buttonPosition = this->getButtonPosition();
    const sf::Vector2f buttonSize = this->getButtonSize();
    sf::RectangleShape &shape = this->getShape();
    const sf::Color buttonColor = this->getButtonColor();
    const sf::Color buttonOutlineColor = this->getButtonOutlineColor();
    const sf::Color buttonHoverColor = this->getButtonHoverColor();
    const sf::Color buttonHoverOutlineColor = this->getButtonHoverOutlineColor();
    sf::Text text = this->getText();
    const sf::Color textColor = this->getTextColor();
    const sf::Color textHoverColor = this->getTextHoverColor();
    const std::function<void()> callback = this->getCallback();

    if (mousePosition.x >= buttonPosition.x && mousePosition.x <= buttonPosition.x + buttonSize.x &&
        mousePosition.y >= buttonPosition.y && mousePosition.y <= buttonPosition.y + buttonSize.y) {
        shape.setFillColor(buttonHoverColor);
        shape.setOutlineColor(buttonHoverOutlineColor);
        text.setFillColor(textHoverColor);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && callback != nullptr && !m_buttonWasClicked) {
            callback();
            m_buttonWasClicked = true;
        }
    } else {
        shape.setFillColor(buttonColor);
        shape.setOutlineColor(buttonOutlineColor);
        text.setFillColor(textColor);
    }
}
