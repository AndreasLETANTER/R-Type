/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** IButton
*/

#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

class IButton {
    public:
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

        IButton() = default;
        ~IButton() = default;

        /// @brief Draw the button
        /// @param window The window where the button will be drawn
        virtual void draw(sf::RenderWindow &window) = 0;

        /// @brief Update the button
        /// @param window The window where the button will be updated
        virtual void update(sf::RenderWindow &window) = 0;

        /// @brief Resize the button
        /// @param windowSize The size of the window
        /// @param buttonRatio The ratio to apply to the window size for the button
        /// @param buttonPosition The position wanted for the button
        /// @param textRatio The ratio to apply to the window size for the text
        virtual void resize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio,
            const sf::Vector2f &buttonPosition, const int &textRatio) = 0;

        /// @brief Set the position of the button
        /// @param position The position wanted for the button
        /// @return The object with the new position
        virtual IButton &setButtonPosition(const sf::Vector2f &position) = 0;

        /// @brief Set the size of the button
        /// @param windowSize The size of the window
        /// @param buttonRatio The ratio to apply to the window size
        /// @return The object with the new size
        virtual IButton &setButtonSize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio) = 0;

        /// @brief Set the color of the button
        /// @param color The color wanted for the button
        /// @return The object with the new color
        virtual IButton &setButtonColor(const sf::Color &color) = 0;

        /// @brief Set the outline color of the button
        /// @param outlineColor The outline color wanted for the button
        /// @return The object with the new outline color
        virtual IButton &setButtonOutlineColor(const sf::Color &outlineColor) = 0;

        /// @brief Set the outline thickness of the button
        /// @param outlineThickness The outline thickness wanted for the button
        /// @return The object with the new outline thickness
        virtual IButton &setButtonOutlineThickness(const int &outlineThickness) = 0;

        /// @brief Set the hover color of the button
        /// @param hoverColor The hover color wanted for the button
        /// @return The object with the new hover color
        virtual IButton &setButtonHoverColor(const sf::Color &hoverColor) = 0;

        /// @brief Set the hover outline color of the button
        /// @param hoverOutlineColor The hover outline color wanted for the button
        /// @return The object with the new hover outline color
        virtual IButton &setButtonHoverOutlineColor(const sf::Color &hoverOutlineColor) = 0;

        /// @brief Set the string of the text
        /// @param text The string wanted for the text
        /// @return The object with the text with the new string
        virtual IButton &setTextString(const std::string &text) = 0;

        /// @brief Set the font of the text
        /// @param font The font wanted for the text
        /// @return The object with the text with the new font
        virtual IButton &setTextFont(const sf::Font &font) = 0;

        /// @brief Set the size of the text
        /// @param windowSize The size of the window
        /// @param textRatio The ratio to apply to the window size
        /// @return The object with the text resized
        virtual IButton &setTextSize(const sf::Vector2u &windowSize, const float &textRatio) = 0;

        /// @brief Set the position of the text
        /// @param horizontalAlign The horizontal alignment of the text
        /// @param verticalAlign The vertical alignment of the text
        /// @return The object with the text with the new position
        virtual IButton &setTextPosition(const HorizontalAlign &horizontalAlign,
            const VerticalAlign &verticalAlign) = 0;

        /// @brief Set the color of the text
        /// @param color The color wanted for the text
        /// @return The object with the text with the new color
        virtual IButton &setTextColor(const sf::Color &color) = 0;

        /// @brief Set the hover color of the text
        /// @param hoverColor The hover color wanted for the text
        /// @return The object with the text with the new hover color
        virtual IButton &setTextHoverColor(const sf::Color &hoverColor) = 0;

        /// @brief Set the callback of the button
        /// @param callback The callback wanted for the button
        /// @return The object with the new callback
        virtual IButton &setCallback(const std::function<void()> &callback) = 0;

        /// @brief Get the shape of the button
        /// @return The shape of the button
        virtual const sf::RectangleShape &getShape() const = 0;

        /// @brief Get the position of the button
        /// @return The position of the button
        virtual const sf::Vector2f &getButtonPosition() const = 0;

        /// @brief Get the size of the button
        /// @return The size of the button
        virtual const sf::Vector2f &getButtonSize() const = 0;

        /// @brief Get the color of the button
        /// @return The color of the button
        virtual const sf::Color &getButtonColor() const = 0;

        /// @brief Get the outline color of the button
        /// @return The outline color of the button
        virtual const sf::Color &getButtonOutlineColor() const = 0;

        /// @brief Get the hover color of the button
        /// @return The hover color of the button
        virtual const sf::Color &getButtonHoverColor() const = 0;

        /// @brief Get the hover outline color of the button
        /// @return The hover outline color of the button
        virtual const sf::Color &getButtonHoverOutlineColor() const = 0;

        /// @brief Get the text of the button
        /// @return The text of the button
        virtual const sf::Text &getText() const = 0;

        /// @brief Get the color of the text
        /// @return The color of the text
        virtual const sf::Color &getTextColor() const = 0;

        /// @brief Get the hover color of the text
        /// @return The hover color of the text
        virtual const sf::Color &getTextHoverColor() const = 0;

        /// @brief Get the horizontal alignment of the text
        /// @return The horizontal alignment of the text
        virtual const HorizontalAlign &getHorizontalAlign() const = 0;

        /// @brief Get the vertical alignment of the text
        /// @return The vertical alignment of the text
        virtual const VerticalAlign &getVerticalAlign() const = 0;

        /// @brief Get the callback of the button
        /// @return The callback of the button
        virtual const std::function<void()> &getCallback() const = 0;
};
