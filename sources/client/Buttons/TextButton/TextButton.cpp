/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** TextButton
*/

#include "client/Buttons/TextButton/TextButton.hpp"
#include "TextButton.hpp"

#include <iostream>

TextButton &TextButton::setButtonPosition(const sf::Vector2f &position)
{
    m_buttonPosition = position;
    m_shape.setPosition(m_buttonPosition);

    return (*this);
}

TextButton &TextButton::setButtonSize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio)
{
    m_buttonSize = sf::Vector2f(windowSize.x / buttonRatio.x,
        windowSize.y / buttonRatio.y);
    m_shape.setSize(m_buttonSize);
    return (*this);
}

TextButton &TextButton::setButtonColor(const sf::Color &color)
{
    m_buttonColor = color;
    return (*this);
}

TextButton &TextButton::setButtonOutlineColor(const sf::Color &outlineColor)
{
    m_buttonOutlineColor = outlineColor;
    return (*this);
}

TextButton &TextButton::setButtonOutlineThickness(const int &outlineThickness)
{
    m_shape.setOutlineThickness(outlineThickness);
    return (*this);
}

TextButton &TextButton::setButtonHoverColor(const sf::Color &hoverColor)
{
    m_buttonHoverColor = hoverColor;
    return (*this);
}

TextButton &TextButton::setButtonHoverOutlineColor(const sf::Color &hoverOutlineColor)
{
    m_buttonHoverOutlineColor = hoverOutlineColor;
    return (*this);
}

TextButton &TextButton::setTextString(const std::string &text)
{
    m_text.setString(text);
    return (*this);
}

std::string TextButton::getTextString() const
{
    return (m_text.getString());
}

TextButton &TextButton::setTextFont(const sf::Font &font)
{
    m_text.setFont(font);
    return (*this);
}

TextButton &TextButton::setTextSize(const sf::Vector2u &windowSize, const float &textRatio)
{
    m_textSize = windowSize.y / textRatio;
    m_text.setCharacterSize(m_textSize);
    return (*this);
}

int TextButton::getTextSize() const
{
    return (m_text.getCharacterSize());
}

TextButton &TextButton::setTextPosition(const TextButton::HorizontalAlign &horizontalAlign,
    const TextButton::VerticalAlign &verticalAlign)
{
    sf::FloatRect buttonBounds = this->m_shape.getGlobalBounds();
    sf::FloatRect textBounds = this->m_text.getLocalBounds();
    float x, y = 0;

    if (horizontalAlign == TextButton::LEFT) {
        x = buttonBounds.left;
    } else if (horizontalAlign == TextButton::CENTER) {
        x = buttonBounds.left + (buttonBounds.width - textBounds.width) / 2.0f - textBounds.left;
    } else {
        x = buttonBounds.left + buttonBounds.width - textBounds.width - textBounds.left;
    }

    if (verticalAlign == TextButton::TOP) {
        y = buttonBounds.top;
    } else if (verticalAlign == TextButton::MIDDLE) {
        y = buttonBounds.top + (buttonBounds.height - textBounds.height) / 2.0f - textBounds.top;
    } else {
        y = buttonBounds.top + buttonBounds.height - textBounds.height - textBounds.top;
    }
    m_horizontalAlign = horizontalAlign;
    m_verticalAlign = verticalAlign;
    this->m_text.setPosition(x, y);
    return (*this);
}

TextButton &TextButton::setTextColor(const sf::Color &color)
{
    m_textColor = color;
    return (*this);
}

TextButton &TextButton::setTextHoverColor(const sf::Color &hoverColor)
{
    m_textHoverColor = hoverColor;
    return (*this);
}

TextButton &TextButton::setCallback(std::function<void()> callback)
{
    m_callback = callback;
    return (*this);
}

void TextButton::draw(sf::RenderWindow &window)
{
    window.draw(m_shape);
}

void TextButton::update(sf::RenderWindow &window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (mousePosition.x >= m_buttonPosition.x && mousePosition.x <= m_buttonPosition.x + m_buttonSize.x &&
        mousePosition.y >= m_buttonPosition.y && mousePosition.y <= m_buttonPosition.y + m_buttonSize.y) {
        m_shape.setFillColor(m_buttonHoverColor);
        m_shape.setOutlineColor(m_buttonHoverOutlineColor);
        m_text.setFillColor(m_textHoverColor);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_callback != nullptr)
            m_callback();
    } else {
        m_shape.setFillColor(m_buttonColor);
        m_shape.setOutlineColor(m_buttonOutlineColor);
        m_text.setFillColor(m_textColor);
    }
}

void TextButton::resize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio, const sf::Vector2f &buttonPosition, const int &textRatio)
{
    this->setButtonSize(windowSize, buttonRatio)
    .setButtonPosition(buttonPosition)
    .setTextSize(windowSize, textRatio)
    .setTextPosition(m_horizontalAlign, m_verticalAlign);
}

void TextButton::deleteButton(TextButton & button)
{
    button.m_shape.setSize(sf::Vector2f(0, 0));
    button.m_shape.setPosition(sf::Vector2f(0, 0));
    button.m_shape.setFillColor(sf::Color::Transparent);
    button.m_shape.setOutlineColor(sf::Color::Transparent);
    button.m_shape.setOutlineThickness(0);
    button.m_text.setString("");
    button.m_text.setCharacterSize(0);
    button.m_text.setPosition(sf::Vector2f(0, 0));
    button.m_text.setFillColor(sf::Color::Transparent);
    button.m_text.setOutlineColor(sf::Color::Transparent);
    button.m_text.setOutlineThickness(0);
    button.m_textColor = sf::Color::Transparent;
    button.m_textHoverColor = sf::Color::Transparent;
    button.m_buttonColor = sf::Color::Transparent;
    button.m_buttonHoverColor = sf::Color::Transparent;
    button.m_buttonOutlineColor = sf::Color::Transparent;
    button.m_buttonHoverOutlineColor = sf::Color::Transparent;
    button.m_callback = nullptr;
    button.m_isClicked = false;
}
