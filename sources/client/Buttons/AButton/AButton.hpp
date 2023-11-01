/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** AButton
*/

#pragma once

#include "client/Buttons/IButton.hpp"

class AButton : public IButton {
    public:
        void draw(sf::RenderWindow &window) override;
        void resize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio,
            const sf::Vector2f &buttonPosition, const int &textRatio) override;

        IButton &setButtonPosition(const sf::Vector2f &position) override;
        IButton &setButtonSize(const sf::Vector2u &windowSize, const sf::Vector2f &buttonRatio) override;
        IButton &setButtonColor(const sf::Color &color) override;
        IButton &setButtonOutlineColor(const sf::Color &outlineColor) override;
        IButton &setButtonOutlineThickness(const int &outlineThickness) override;
        IButton &setButtonHoverColor(const sf::Color &hoverColor) override;
        IButton &setButtonHoverOutlineColor(const sf::Color &hoverOutlineColor) override;
        IButton &setTextString(const std::string &text) override;
        IButton &setTextFont(const sf::Font &font) override;
        IButton &setTextSize(const sf::Vector2u &windowSize, const float &textRatio) override;
        IButton &setTextPosition(const HorizontalAlign &horizontalAlign,
            const VerticalAlign &verticalAlign) override;
        IButton &setTextColor(const sf::Color &color) override;
        IButton &setTextHoverColor(const sf::Color &hoverColor) override;
        IButton &setCallback(const std::function<void()> &callback) override;
        IButton &setCooldown(const float &cooldown) override;

        sf::RectangleShape &getShape() override;
        const sf::Vector2f &getButtonPosition() const override;
        const sf::Vector2f &getButtonSize() const override;
        const sf::Color &getButtonColor() const override;
        const sf::Color &getButtonOutlineColor() const override;
        const sf::Color &getButtonHoverColor() const override;
        const sf::Color &getButtonHoverOutlineColor() const override;
        sf::Text &getText() override;
        const sf::Color &getTextColor() const override;
        const sf::Color &getTextHoverColor() const override;
        const HorizontalAlign &getHorizontalAlign() const override;
        const VerticalAlign &getVerticalAlign() const override;
        const std::function<void()> &getCallback() const override;
        const float &getCooldown() const override;
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
};