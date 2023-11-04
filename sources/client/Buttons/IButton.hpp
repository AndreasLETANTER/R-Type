/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** IButton
*/

#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

/**
 * @brief Interface to create buttons
 */
class IButton {
    public:
        enum HorizontalAlign {
            LEFT,
            CENTER,
            RIGHT
        };
        enum VerticalAlign {
            TOP,
            MIDDLE,
            BOTTOM
        };

        IButton() = default;
        ~IButton() = default;

        /**
         * @brief Draw Button object
         *
         * @param window window where the button will be drawn
         */
        virtual void draw(sf::RenderWindow &window) = 0;

        /**
         * @brief Updates the button's state and appearance.
         *
         * @param window The SFML window to render the button on.
         */
        virtual void update(sf::RenderWindow &window) = 0;

        /**
         * @brief Resizes the button according to the window size, button ratio, button position and text ratio.
         *
         * @param windowSize The size of the window.
         * @param buttonRatio The ratio of the button size to the window size.
         * @param buttonPosition The position of the button relative to the window.
         * @param textRatio The ratio of the text size to the button size.
         */
        virtual void resize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio,
            const sf::Vector2f &buttonPosition, const int &textRatio) = 0;

        /**
         * @brief Sets the position of the button.
         *
         * @param position The new position of the button.
         * @return A reference to the button instance.
         */
        virtual IButton &setButtonPosition(const sf::Vector2f &position) = 0;

        /**
         * @brief Sets the size of the button based on the given window size and button ratio.
         *
         * @param windowSize The size of the window.
         * @param buttonRatio The ratio of the button size to the window size.
         * @return A reference to the button object.
         */
        virtual IButton &setButtonSize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio) = 0;

        /**
         * @brief Sets the color of the button.
         *
         * @param color The new color of the button.
         * @return A reference to the button.
         */
        virtual IButton &setButtonColor(const sf::Color &color) = 0;

        /**
         * @brief Sets the outline color of the button.
         *
         * @param outlineColor The new color of the button outline.
         * @return A reference to the button instance.
         */
        virtual IButton &setButtonOutlineColor(const sf::Color &outlineColor) = 0;

        /**
         * @brief Sets the thickness of the outline of the button.
         *
         * @param outlineThickness The thickness of the outline.
         * @return A reference to the button instance.
         */
        virtual IButton &setButtonOutlineThickness(const int &outlineThickness) = 0;

        /**
         * @brief Sets the color of the button when the mouse hovers over it.
         *
         * @param hoverColor The color to set.
         * @return A reference to the button object.
         */
        virtual IButton &setButtonHoverColor(const sf::Color &hoverColor) = 0;

        /**
         * @brief Sets the color of the button's outline when the mouse hovers over it.
         *
         * @param hoverOutlineColor The color to set the hover outline to.
         * @return A reference to the button instance.
         */
        virtual IButton &setButtonHoverOutlineColor(const sf::Color &hoverOutlineColor) = 0;

        /**
         * @brief Sets the text string of the button.
         *
         * @param text The new text string to set.
         * @return A reference to the button instance.
         */
        virtual IButton &setTextString(const std::string &text) = 0;

        /**
         * @brief Sets the font of the text displayed on the button.
         *
         * @param font The font to set.
         * @return A reference to the button.
         */
        virtual IButton &setTextFont(const sf::Font &font) = 0;

        /**
         * @brief Sets the size of the text displayed on the button.
         *
         * @param windowSize The size of the window in which the button is displayed.
         * @param textRatio The ratio of the text size to the button size.
         * @return A reference to the button object.
         */
        virtual IButton &setTextSize(const sf::Vector2u &windowSize, const float &textRatio) = 0;

        /**
         * @brief Sets the position of the text within the button.
         *
         * @param horizontalAlign The horizontal alignment of the text.
         * @param verticalAlign The vertical alignment of the text.
         * @return A reference to the button instance.
         */
        virtual IButton &setTextPosition(const HorizontalAlign &horizontalAlign,
            const VerticalAlign &verticalAlign) = 0;

        /**
         * @brief Sets the text color of the button.
         *
         * @param color The new color of the text.
         * @return A reference to the button instance.
         */
        virtual IButton &setTextColor(const sf::Color &color) = 0;

        /**
         * @brief Sets the color of the text when the button is hovered over.
         *
         * @param hoverColor The color to set the text to when the button is hovered over.
         * @return A reference to the button instance.
         */
        virtual IButton &setTextHoverColor(const sf::Color &hoverColor) = 0;

        /**
         * @brief Sets the callback function to be called when the button is clicked.
         *
         * @param callback The function to be called when the button is clicked.
         * @return A reference to the button instance.
         */
        virtual IButton &setCallback(const std::function<void()> &callback) = 0;

        /**
         * @brief Sets the cooldown time for the button.
         *
         * @param cooldown The cooldown time in seconds.
         * @return A reference to the button instance.
         */
        virtual IButton &setCooldown(const float &cooldown) = 0;

        /**
         * @brief Returns a reference to the button's shape.
         *
         * @return sf::RectangleShape& A reference to the button's shape.
         */
        virtual sf::RectangleShape &getShape() = 0;

        /**
         * @brief Returns the position of the button.
         *
         * @return The position of the button as a constant reference to a sf::Vector2f object.
         */
        virtual const sf::Vector2f &getButtonPosition() const = 0;

        /**
         * @brief Returns the size of the button.
         *
         * @return The size of the button as a constant reference to a sf::Vector2f object.
         */
        virtual const sf::Vector2f &getButtonSize() const = 0;

        /**
         * @brief Returns the color of the button.
         *
         * @return const sf::Color& The color of the button.
         */
        virtual const sf::Color &getButtonColor() const = 0;

        /**
         * @brief Returns the outline color of the button.
         *
         * @return The outline color of the button.
         */
        virtual const sf::Color &getButtonOutlineColor() const = 0;

        /**
         * @brief Returns the color of the button when the mouse is hovering over it.
         *
         * @return The color of the button when the mouse is hovering over it.
         */
        virtual const sf::Color &getButtonHoverColor() const = 0;

        /**
         * @brief Returns the color of the button's outline when the mouse hovers over it.
         *
         * @return The color of the button's hover outline.
         */
        virtual const sf::Color &getButtonHoverOutlineColor() const = 0;

        /**
         * @brief Returns a reference to the text object associated with the button.
         *
         * @return sf::Text& A reference to the text object.
         */
        virtual sf::Text &getText() = 0;

        /**
         * @brief Returns the text color of the button.
         *
         * @return The text color of the button.
         */
        virtual const sf::Color &getTextColor() const = 0;

        /**
         * @brief Gets the color of the text when the button is hovered over.
         *
         * @return The color of the text when the button is hovered over.
         */
        virtual const sf::Color &getTextHoverColor() const = 0;

        /**
         * @brief Returns the horizontal alignment of the button.
         *
         * @return The horizontal alignment of the button.
         */
        virtual const HorizontalAlign &getHorizontalAlign() const = 0;

        /**
         * @brief Returns the vertical alignment of the button.
         *
         * @return The vertical alignment of the button.
         */
        virtual const VerticalAlign &getVerticalAlign() const = 0;

        /**
         * @brief Returns the callback function associated with the button.
         *
         * @return The callback function associated with the button.
         */
        virtual const std::function<void()> &getCallback() const = 0;

        /**
         * @brief Returns the cooldown of the button.
         *
         * @return const float& The cooldown of the button.
         */
        virtual const float &getCooldown() const = 0;

        /**
         * @brief Get the current state of the button.
         *
         * @return true if the button is currently pressed, false otherwise.
         */
        virtual bool getState() const = 0;

        /**
         * @brief Sets the state of the button.
         *
         * @param state The new state of the button.
         */
        virtual void setState(bool state) = 0;

        /**
         * @brief Removes a button from the button container.
         *
         * @param button The button to remove.
         */
        virtual void deleteButton(IButton &button) = 0;
};
