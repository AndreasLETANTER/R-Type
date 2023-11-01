/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** TextButton
*/

#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

#include "client/Buttons/AButton/AButton.hpp"

/// @brief Class to create fully customizable text buttons
class TextButton : public AButton {
    public:
        void update(sf::RenderWindow &window) override;
};
