/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Button
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "client/Buttons/AButton/AButton.hpp"

/**
 * @brief Button class, used to create a button
 */
class Button : public AButton {
    public:
        /**
         * @brief update the button
         *
         * @param window
         */
        void update(sf::RenderWindow &window) override;
};
