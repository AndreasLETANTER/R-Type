/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** CooldownButton
*/

#include <iostream>

#include "client/Buttons/CooldownButton/CooldownButton.hpp"
#include "CooldownButton.hpp"

void CooldownButton::update(sf::RenderWindow &window)
{
    float cooldown = this->getCooldown();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    const sf::Vector2f buttonPosition = this->getButtonPosition();
    const sf::Vector2f buttonSize = this->getButtonSize();
    sf::RectangleShape &shape = this->getShape();
    const sf::Color buttonColor = this->getButtonColor();
    const sf::Color buttonOutlineColor = this->getButtonOutlineColor();
    const sf::Color buttonHoverColor = this->getButtonHoverColor();
    const sf::Color buttonHoverOutlineColor = this->getButtonHoverOutlineColor();
    sf::Text &text = this->getText();
    const sf::Color textColor = this->getTextColor();
    const sf::Color textHoverColor = this->getTextHoverColor();
    const std::function<void()> callback = this->getCallback();

    if (!m_isCooldownPassed) {
        float elapsedTime = m_clock.getElapsedTime().asSeconds();
        m_timeLeft = std::max(cooldown - elapsedTime, 0.0f);

        if (elapsedTime >= cooldown) {
            m_isCooldownPassed = true;
            m_timeLeft = 0.0f;
        }

        if (static_cast<int>(elapsedTime) != static_cast<int>(elapsedTime - 1)) {
            this->setTextString(text.getString());
        }
    }
    if (mousePosition.x >= buttonPosition.x && mousePosition.x <= buttonPosition.x + buttonSize.x &&
        mousePosition.y >= buttonPosition.y && mousePosition.y <= buttonPosition.y + buttonSize.y) {
        shape.setFillColor(buttonHoverColor);
        shape.setOutlineColor(buttonHoverOutlineColor);
        text.setFillColor(textHoverColor);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
            && callback != nullptr && !m_buttonWasClicked) {
            callback();
            m_clock.restart();
            m_isCooldownPassed = false;
            m_buttonWasClicked = true;
        }
    } else {
        shape.setFillColor(buttonColor);
        shape.setOutlineColor(buttonOutlineColor);
        text.setFillColor(textColor);
    }
    if (m_isCooldownPassed && callback != nullptr) {
        callback();
        m_clock.restart();
        m_isCooldownPassed = false;
    }
}

IButton &CooldownButton::setTextString(const std::string &text)
{
    sf::Text &textObject = this->getText();
    std::string textString = text;

    if (static_cast<int>(m_timeLeft) == 0) {
        textObject.setString(textString);
        return *this;
    }
    textString = textString.substr(0, textString.find(" ("));
    textString += " (" + std::to_string(static_cast<int>(m_timeLeft)) + ")";
    textObject.setString(textString);
    return *this;
}
