/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** OneUseButton
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "client/Buttons/AButton/AButton.hpp"

/**
 * @brief Class to create fully customizable text buttons
 */
class OneUseButton : public AButton {
    public:
        /**
         * @brief Updates the state of the OneUseButton.
         *
         * @param window The SFML RenderWindow to use for rendering.
         */
        void update(sf::RenderWindow &window) override;
    private:
        bool m_buttonWasClicked = false;
};
