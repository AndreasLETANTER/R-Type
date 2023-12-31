/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** AButton
*/

#include "AButton.hpp"

void AButton::draw(sf::RenderWindow &window)
{
    window.draw(m_shape);
    window.draw(m_text);
}

void AButton::resize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio, const sf::Vector2f &buttonPosition, const int &textRatio)
{
    this->setButtonSize(windowSize, buttonRatio)
    .setButtonPosition(buttonPosition)
    .setTextSize(windowSize, textRatio)
    .setTextPosition(m_horizontalAlign, m_verticalAlign);
}

IButton &AButton::setButtonPosition(const sf::Vector2f &position)
{
    m_buttonPosition = position;
    m_shape.setPosition(m_buttonPosition);

    return (*this);
}

IButton &AButton::setButtonSize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio)
{
    m_buttonSize = sf::Vector2f(windowSize.x / buttonRatio.x,
        windowSize.y / buttonRatio.y);
    m_shape.setSize(m_buttonSize);
    return (*this);
}

IButton &AButton::setButtonColor(const sf::Color &color)
{
    m_buttonColor = color;
    return (*this);
}

IButton &AButton::setButtonOutlineColor(const sf::Color &outlineColor)
{
    m_buttonOutlineColor = outlineColor;
    return (*this);
}

IButton &AButton::setButtonOutlineThickness(const int &outlineThickness)
{
    m_shape.setOutlineThickness(outlineThickness);
    return (*this);
}

IButton &AButton::setButtonHoverColor(const sf::Color &hoverColor)
{
    m_buttonHoverColor = hoverColor;
    return (*this);
}

IButton &AButton::setButtonHoverOutlineColor(const sf::Color &hoverOutlineColor)
{
    m_buttonHoverOutlineColor = hoverOutlineColor;
    return (*this);
}

IButton &AButton::setTextString(const std::string &text)
{
    m_text.setString(text);
    return (*this);
}

IButton &AButton::setTextFont(const sf::Font &font)
{
    m_text.setFont(font);
    return (*this);
}

IButton &AButton::setTextSize(const sf::Vector2u &windowSize, const float &textRatio)
{
    m_text.setCharacterSize(windowSize.y / textRatio);
    return (*this);
}

IButton &AButton::setTextPosition(const AButton::HorizontalAlign &horizontalAlign,
    const AButton::VerticalAlign &verticalAlign)
{
    sf::FloatRect buttonBounds = this->m_shape.getGlobalBounds();
    sf::FloatRect textBounds = this->m_text.getLocalBounds();
    float x, y = 0;

    if (horizontalAlign == AButton::LEFT) {
        x = buttonBounds.left;
    } else if (horizontalAlign == AButton::CENTER) {
        x = buttonBounds.left + (buttonBounds.width - textBounds.width) / 2.0f - textBounds.left;
    } else {
        x = buttonBounds.left + buttonBounds.width - textBounds.width - textBounds.left;
    }

    if (verticalAlign == AButton::TOP) {
        y = buttonBounds.top;
    } else if (verticalAlign == AButton::MIDDLE) {
        y = buttonBounds.top + (buttonBounds.height - textBounds.height) / 2.0f - textBounds.top;
    } else {
        y = buttonBounds.top + buttonBounds.height - textBounds.height - textBounds.top;
    }
    m_horizontalAlign = horizontalAlign;
    m_verticalAlign = verticalAlign;
    this->m_text.setPosition(x, y);
    return (*this);
}

IButton &AButton::setTextColor(const sf::Color &color)
{
    m_textColor = color;
    return (*this);
}

IButton &AButton::setTextHoverColor(const sf::Color &hoverColor)
{
    m_textHoverColor = hoverColor;
    return (*this);
}

IButton &AButton::setCallback(const std::function<void()> &callback)
{
    m_callback = callback;
    return (*this);
}

IButton &AButton::setCooldown(const float &cooldown)
{
    m_cooldown = cooldown + 2;
    return (*this);
}

sf::RectangleShape &AButton::getShape()
{
    return (m_shape);
}

const sf::Vector2f &AButton::getButtonPosition() const
{
    return (m_buttonPosition);
}

const sf::Vector2f &AButton::getButtonSize() const
{
    return (m_buttonSize);
}

const sf::Color &AButton::getButtonColor() const
{
    return (m_buttonColor);
}

const sf::Color &AButton::getButtonOutlineColor() const
{
    return (m_buttonOutlineColor);
}

const sf::Color &AButton::getButtonHoverColor() const
{
    return (m_buttonHoverColor);
}

const sf::Color &AButton::getButtonHoverOutlineColor() const
{
    return (m_buttonHoverOutlineColor);
}

sf::Text &AButton::getText()
{
    return (m_text);
}

const sf::Color &AButton::getTextColor() const
{
    return (m_textColor);
}

const sf::Color &AButton::getTextHoverColor() const
{
    return (m_textHoverColor);
}

const AButton::HorizontalAlign &AButton::getHorizontalAlign() const
{
    return (m_horizontalAlign);
}

const AButton::VerticalAlign &AButton::getVerticalAlign() const
{
    return (m_verticalAlign);
}

const std::function<void()> &AButton::getCallback() const
{
    return (m_callback);
}

const float &AButton::getCooldown() const
{
    return (m_cooldown);
}

bool AButton::getState() const
{
    return (m_isClicked);
}

void AButton::setState(bool state)
{
    m_isClicked = state;
}

void AButton::deleteButton(IButton &button)
{
    button.getShape().setSize(sf::Vector2f(0, 0));
    button.getShape().setPosition(sf::Vector2f(0, 0));
    button.getShape().setFillColor(sf::Color::Transparent);
    button.getShape().setOutlineColor(sf::Color::Transparent);
    button.getShape().setOutlineThickness(0);
    button.getText().setString("");
    button.getText().setCharacterSize(0);
    button.getText().setPosition(sf::Vector2f(0, 0));
    button.getText().setFillColor(sf::Color::Transparent);
    button.getText().setOutlineColor(sf::Color::Transparent);
    button.getText().setOutlineThickness(0);
    button.setTextColor(sf::Color::Transparent);
    button.setTextHoverColor(sf::Color::Transparent);
    button.setButtonColor(sf::Color::Transparent);
    button.setButtonHoverColor(sf::Color::Transparent);
    button.setButtonOutlineColor(sf::Color::Transparent);
    button.setButtonHoverOutlineColor(sf::Color::Transparent);
    button.setCallback(nullptr);
    button.setState(false);
}
