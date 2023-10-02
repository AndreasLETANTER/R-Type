/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** TextButton
*/

#include "client/Buttons/TextButton/TextButton.hpp"

TextButton TextButton::setButtonPosition(const sf::Vector2f &position)
{
    m_buttonPosition = position;
    return (*this);
}

TextButton TextButton::setButtonSize(const sf::Vector2f &size)
{
    m_buttonSize = size;
    return (*this);
}

TextButton TextButton::setButtonColor(const sf::Color &color)
{
    m_buttonColor = color;
    return (*this);
}

TextButton TextButton::setButtonOutlineColor(const sf::Color &outlineColor)
{
    m_buttonOutlineColor = outlineColor;
    return (*this);
}

TextButton TextButton::setButtonOutlineThickness(const int &outlineThickness)
{
    m_buttonOutlineThickness = outlineThickness;
    return (*this);
}

TextButton TextButton::setButtonHoverColor(const sf::Color &hoverColor)
{
    m_buttonHoverColor = hoverColor;
    return (*this);
}

TextButton TextButton::setButtonHoverOutlineColor(const sf::Color &hoverOutlineColor)
{
    m_buttonHoverOutlineColor = hoverOutlineColor;
    return (*this);
}

TextButton TextButton::setTextString(const std::string &text)
{
    m_textString = text;
    return (*this);
}

TextButton TextButton::setTextFont(const sf::Font &font)
{
    m_textFont = font;
    return (*this);
}

TextButton TextButton::setTextSize(const int &size)
{
    m_textSize = size;
    return (*this);
}

TextButton TextButton::setTextColor(const sf::Color &color)
{
    m_textColor = color;
    return (*this);
}

TextButton TextButton::setTextHoverColor(const sf::Color &hoverColor)
{
    m_textHoverColor = hoverColor;
    return (*this);
}

TextButton TextButton::setCallback(void (*callback)())
{
    m_callback = callback;
    return (*this);
}

void TextButton::draw(sf::RenderWindow &window)
{
    window.draw(m_shape);
    window.draw(m_text);
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
