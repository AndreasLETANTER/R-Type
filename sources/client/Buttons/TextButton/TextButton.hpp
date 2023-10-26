/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** TextButton
*/

#pragma once

#include <functional>
#include <SFML/Graphics.hpp>
#include <iostream>

/// @brief Class to create fully customizable text buttons
class TextButton {
    public:
        /// @brief Constructor of TextButton
        TextButton() = default;
        TextButton(const TextButton &textButton) = delete;

        /// @brief Enum to set the horizontal alignment of the text
        enum HorizontalAlign {
            LEFT,
            CENTER,
            RIGHT
        };
        /// @brief Enum to set the vertical alignment of the text
        enum VerticalAlign {
            TOP,
            MIDDLE,
            BOTTOM
        };

        /// @brief Set the position of the button
        /// @param position The position wanted for the button
        /// @return The object with the new position
        TextButton &setButtonPosition(const sf::Vector2f &position);

        /// @brief Set the size of the button
        /// @param windowSize The size of the window
        /// @param buttonRatio The ratio to apply to the window size
        /// @return The object with the new size
        TextButton &setButtonSize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio);



        /// @brief Set the color of the button
        /// @param color The color wanted for the button
        /// @return The object with the new color
        TextButton &setButtonColor(const sf::Color &color);

        /// @brief Set the outline color of the button
        /// @param outlineColor The outline color wanted for the button
        /// @return The object with the new outline color
        TextButton &setButtonOutlineColor(const sf::Color &outlineColor);

        /// @brief Set the outline thickness of the button
        /// @param outlineThickness The outline thickness wanted for the button
        /// @return The object with the new outline thickness
        TextButton &setButtonOutlineThickness(const int &outlineThickness);

        /// @brief Set the hover color of the button
        /// @param hoverColor The hover color wanted for the button
        /// @return The object with the new hover color
        TextButton &setButtonHoverColor(const sf::Color &hoverColor);

        /// @brief Set the hover outline color of the button
        /// @param hoverOutlineColor The hover outline color wanted for the button
        /// @return The object with the new hover outline color
        TextButton &setButtonHoverOutlineColor(const sf::Color &hoverOutlineColor);

        /// @brief Set the string of the text
        /// @param text The string wanted for the text
        /// @return The object with the text with the new string
        TextButton &setTextString(const std::string &text);

        /// @brief Get the string of the text
        /// @return The string of the text
        std::string getTextString() const;

        /// @brief Set the font of the text
        /// @param font The font wanted for the text
        /// @return The object with the text with the new font
        TextButton &setTextFont(const sf::Font &font);

        /// @brief Set the size of the text
        /// @param windowSize The size of the window
        /// @param textRatio The ratio to apply to the window size
        /// @return The object with the text resized
        TextButton &setTextSize(const sf::Vector2u &windowSize, const float &textRatio);

        /// @brief Get the size of the text
        /// @return The size of the text
        int getTextSize() const;

        /// @brief Set the position of the text
        /// @param horizontalAlign The horizontal alignment of the text
        /// @param verticalAlign The vertical alignment of the text
        /// @return The object with the text with the new position
        TextButton& setTextPosition(const TextButton::HorizontalAlign &horizontalAlign,
            const TextButton::VerticalAlign &verticalAlign);

        /// @brief Set the color of the text
        /// @param color The color wanted for the text
        /// @return The object with the text with the new color
        TextButton &setTextColor(const sf::Color &color);

        /// @brief Set the hover color of the text
        /// @param hoverColor The hover color wanted for the text
        /// @return The object with the text with the new hover color
        TextButton &setTextHoverColor(const sf::Color &hoverColor);

        /// @brief Set the callback of the button
        /// @param callback The callback wanted for the button
        /// @return The object with the new callback
        TextButton &setCallback(std::function<void()> callback);

        /// @brief Draw the button
        /// @param window The window where the button will be drawn
        void draw(sf::RenderWindow &window);

        /// @brief Update the button
        /// @param window The window where the button will be updated
        void update(sf::RenderWindow &window);

        /// @brief Resize the button
        /// @param windowSize The size of the window
        /// @param buttonRatio The ratio to apply to the window size for the button
        /// @param buttonPosition The position wanted for the button
        /// @param textRatio The ratio to apply to the window size for the text
        void resize(const sf::Vector2u &windowSize,
            const sf::Vector2f &buttonRatio,
            const sf::Vector2f &buttonPosition, const int &textRatio);

        /// @brief Get the state of the button
        /// @return The state of the button
        bool getState() const {
            std::cout << m_isClicked << std::endl;
            return m_isClicked; };

        /// @brief Set the state of the button
        /// @param state The state wanted for the buttontcpPortButton
        void setState(bool state) {
            std::cout << "changed to " <<m_isClicked << std::endl;
        m_isClicked = state; };

    private:
        sf::RectangleShape m_shape = sf::RectangleShape();
        sf::Vector2f m_buttonPosition = sf::Vector2f(0, 0);
        sf::Vector2f m_buttonSize = sf::Vector2f(0, 0);
        sf::Color m_buttonColor = sf::Color::White;
        sf::Color m_buttonOutlineColor = sf::Color::White;
        sf::Color m_buttonHoverColor = sf::Color::White;
        sf::Color m_buttonHoverOutlineColor = sf::Color::White;

        sf::Text m_text = sf::Text();
        int m_textSize = 0;
        bool m_isClicked = false;
        sf::Color m_textColor = sf::Color::White;
        sf::Color m_textHoverColor = sf::Color::White;
        TextButton::HorizontalAlign m_horizontalAlign = TextButton::CENTER;
        TextButton::VerticalAlign m_verticalAlign = TextButton::MIDDLE;

        std::function<void()> m_callback = [](){};
};
