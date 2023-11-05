/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** CooldownButton
*/

#pragma once

#include "client/Buttons/AButton/AButton.hpp"

/**
 * @brief CooldownButton class, used to create a cooldown button
 */
class CooldownButton: public AButton {
    public:
        /**
         * @brief Updates the cooldown button's state and appearance.
         *
         * @param window The SFML window to render the button on.
         */
        void update(sf::RenderWindow &window) override;
    private:
        sf::Clock m_clock;
        bool m_isCooldownPassed = false;
        float m_timeLeft = 0;
        bool m_buttonWasClicked = false;
};

