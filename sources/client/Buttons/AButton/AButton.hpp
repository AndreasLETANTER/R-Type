/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** AButton
*/

#pragma once

#include "client/Buttons/IButton.hpp"

/**
 * @brief AButton class, used to create a button
 */
class AButton : public IButton {
    public:
        /**
         * @brief Draw AButton object
         *
         * @param window window where the button will be drawn
         */
        void draw(sf::RenderWindow &window) override;

        /**
         * @brief Resizes the button according to the window size, button ratio, button position and text ratio.
         *
         * @param windowSize The size of the window.
         * @param buttonRatio The ratio of the button size to the window size.
         * @param buttonPosition The position of the button relative to the window.
         * @param textRatio The ratio of the text size to the button size.
         */
        void resize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio,
            const sf::Vector2f &buttonPosition, const int &textRatio) override;

        /**
         * @brief Sets the position of the button.
         *
         * @param position The new position of the button.
         * @return A reference to the button instance.
         */
        IButton &setButtonPosition(const sf::Vector2f &position) override;

        /**
         * @brief Sets the size of the button based on the given window size and button ratio.
         *
         * @param windowSize The size of the window.
         * @param buttonRatio The ratio of the button size to the window size.
         * @return A reference to the button object.
         */
        IButton &setButtonSize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio) override;

        /**
         * @brief Sets the color of the button.
         *
         * @param color The new color of the button.
         * @return A reference to the button.
         */
        IButton &setButtonColor(const sf::Color &color) override;

        /**
         * @brief Sets the outline color of the button.
         *
         * @param outlineColor The new color of the button outline.
         * @return A reference to the button instance.
         */
        IButton &setButtonOutlineColor(const sf::Color &outlineColor) override;

        /**
         * @brief Sets the thickness of the outline of the button.
         *
         * @param outlineThickness The thickness of the outline.
         * @return A reference to the button instance.
         */
        IButton &setButtonOutlineThickness(const int &outlineThickness) override;

        /**
         * @brief Sets the color of the button when the mouse hovers over it.
         *
         * @param hoverColor The color to set.
         * @return A reference to the button object.
         */
        IButton &setButtonHoverColor(const sf::Color &hoverColor) override;

        /**
         * @brief Sets the color of the button's outline when the mouse hovers over it.
         *
         * @param hoverOutlineColor The color to set the hover outline to.
         * @return A reference to the button instance.
         */
        IButton &setButtonHoverOutlineColor(const sf::Color &hoverOutlineColor) override;

        /**
         * @brief Sets the text string of the button.
         *
         * @param text The new text string to set.
         * @return A reference to the button instance.
         */
        IButton &setTextString(const std::string &text) override;

        /**
         * @brief Sets the font of the text displayed on the button.
         *
         * @param font The font to set.
         * @return A reference to the button.
         */
        IButton &setTextFont(const sf::Font &font) override;

        /**
         * @brief Sets the size of the text displayed on the button.
         *
         * @param windowSize The size of the window in which the button is displayed.
         * @param textRatio The ratio of the text size to the button size.
         * @return A reference to the button object.
         */
        IButton &setTextSize(const sf::Vector2u &windowSize, const float &textRatio) override;

        /**
         * @brief Sets the position of the text within the button.
         *
         * @param horizontalAlign The horizontal alignment of the text.
         * @param verticalAlign The vertical alignment of the text.
         * @return A reference to the button instance.
         */
        IButton &setTextPosition(const HorizontalAlign &horizontalAlign,
            const VerticalAlign &verticalAlign) override;

        /**
         * @brief Sets the text color of the button.
         *
         * @param color The new color of the text.
         * @return A reference to the button instance.
         */
        IButton &setTextColor(const sf::Color &color) override;

        /**
         * @brief Sets the color of the text when the button is hovered over.
         *
         * @param hoverColor The color to set the text to when the button is hovered over.
         * @return A reference to the button instance.
         */
        IButton &setTextHoverColor(const sf::Color &hoverColor) override;

        /**
         * @brief Sets the callback function to be called when the button is clicked.
         *
         * @param callback The function to be called when the button is clicked.
         * @return A reference to the button instance.
         */
        IButton &setCallback(const std::function<void()> &callback) override;

        /**
         * @brief Sets the cooldown time for the button.
         *
         * @param cooldown The cooldown time in seconds.
         * @return A reference to the button instance.
         */
        IButton &setCooldown(const float &cooldown) override;

        /**
         * @brief Returns a reference to the button's shape.
         *
         * @return sf::RectangleShape& A reference to the button's shape.
         */
        sf::RectangleShape &getShape() override;

        /**
         * @brief Returns the position of the button.
         *
         * @return The position of the button as a constant reference to a sf::Vector2f object.
         */
        const sf::Vector2f &getButtonPosition() const override;

        /**
         * @brief Returns the size of the button.
         *
         * @return The size of the button as a constant reference to a sf::Vector2f object.
         */
        const sf::Vector2f &getButtonSize() const override;

        /**
         * @brief Returns the color of the button.
         *
         * @return const sf::Color& The color of the button.
         */
        const sf::Color &getButtonColor() const override;

        /**
         * @brief Returns the outline color of the button.
         *
         * @return The outline color of the button.
         */
        const sf::Color &getButtonOutlineColor() const override;

        /**
         * @brief Returns the color of the button when the mouse is hovering over it.
         *
         * @return The color of the button when the mouse is hovering over it.
         */
        const sf::Color &getButtonHoverColor() const override;

        /**
         * @brief Returns the color of the button's outline when the mouse hovers over it.
         *
         * @return The color of the button's hover outline.
         */
        const sf::Color &getButtonHoverOutlineColor() const override;

        /**
         * @brief Returns a reference to the text object associated with the button.
         *
         * @return sf::Text& A reference to the text object.
         */
        sf::Text &getText() override;

        /**
         * @brief Returns the text color of the button.
         *
         * @return The text color of the button.
         */
        const sf::Color &getTextColor() const override;

        /**
         * @brief Gets the color of the text when the button is hovered over.
         *
         * @return The color of the text when the button is hovered over.
         */
        const sf::Color &getTextHoverColor() const override;

        /**
         * @brief Returns the horizontal alignment of the button.
         *
         * @return The horizontal alignment of the button.
         */
        const HorizontalAlign &getHorizontalAlign() const override;

        /**
         * @brief Returns the vertical alignment of the button.
         *
         * @return The vertical alignment of the button.
         */
        const VerticalAlign &getVerticalAlign() const override;

        /**
         * @brief Returns the callback function associated with the button.
         *
         * @return The callback function associated with the button.
         */
        const std::function<void()> &getCallback() const override;

        /**
         * @brief Returns the cooldown of the button.
         *
         * @return const float& The cooldown of the button.
         */
        const float &getCooldown() const override;

        /**
         * @brief Get the current state of the button.
         *
         * @return true if the button is currently pressed, false otherwise.
         */
        bool getState() const override;

        /**
         * @brief Sets the state of the button.
         *
         * @param state The new state of the button.
         */
        void setState(bool state) override;

        /**
         * @brief Removes a button from the button container.
         *
         * @param button The button to remove.
         */
        void deleteButton(IButton &button) override;
    private:
        sf::RectangleShape m_shape = sf::RectangleShape();
        sf::Vector2f m_buttonPosition = sf::Vector2f(0, 0);
        sf::Vector2f m_buttonSize = sf::Vector2f(0, 0);
        sf::Color m_buttonColor = sf::Color::White;
        sf::Color m_buttonOutlineColor = sf::Color::White;
        sf::Color m_buttonHoverColor = sf::Color::White;
        sf::Color m_buttonHoverOutlineColor = sf::Color::White;

        sf::Text m_text = sf::Text();
        sf::Color m_textColor = sf::Color::White;
        sf::Color m_textHoverColor = sf::Color::White;
        HorizontalAlign m_horizontalAlign = CENTER;
        VerticalAlign m_verticalAlign = MIDDLE;

        std::function<void()> m_callback = [](){};
        float m_cooldown = 0;
        bool m_isClicked = false;
};
