/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** TextButton
*/

#pragma once

#include <SFML/Graphics.hpp>

class TextButton {
    public:
        TextButton() = default;

        TextButton setButtonPosition(const sf::Vector2f &position);
        TextButton setButtonSize(const sf::Vector2f &size);
        TextButton setButtonColor(const sf::Color &color);
        TextButton setButtonOutlineColor(const sf::Color &outlineColor);
        TextButton setButtonOutlineThickness(const int &outlineThickness);
        TextButton setButtonHoverColor(const sf::Color &hoverColor);
        TextButton setButtonHoverOutlineColor(const sf::Color &hoverOutlineColor);

        TextButton setTextString(const std::string &text);
        TextButton setTextFont(const sf::Font &font);
        TextButton setTextSize(const int &size);
        TextButton setTextColor(const sf::Color &color);
        TextButton setTextHoverColor(const sf::Color &hoverColor);

        TextButton setCallback(void (*callback)());

        void draw(sf::RenderWindow &window);
        void update(sf::RenderWindow &window);
    private:
        sf::RectangleShape m_shape = sf::RectangleShape();
        sf::Vector2f m_buttonPosition = sf::Vector2f(0, 0);
        sf::Vector2f m_buttonSize = sf::Vector2f(0, 0);
        sf::Color m_buttonColor = sf::Color::White;
        sf::Color m_buttonOutlineColor = sf::Color::White;
        int m_buttonOutlineThickness = 0;
        sf::Color m_buttonHoverColor = sf::Color::White;
        sf::Color m_buttonHoverOutlineColor = sf::Color::White;

        sf::Text m_text = sf::Text();
        std::string m_textString = "";
        sf::Font m_textFont = sf::Font();
        int m_textSize = 0;
        sf::Color m_textColor = sf::Color::White;
        sf::Color m_textHoverColor = sf::Color::White;

        void (*m_callback)() = nullptr;
};
