/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** CooldownButton
*/

#pragma once

#include "client/Buttons/AButton/AButton.hpp"

class CooldownButton: public AButton {
    public:
        void update(sf::RenderWindow &window) override;
        IButton &setTextString(const std::string &text) override;
    private:
        sf::Clock m_clock;
        bool m_isCooldownPassed = false;
        float m_timeLeft = 0.0f;
        bool m_buttonWasClicked = false;
};

