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
