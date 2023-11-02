/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Button
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "client/Buttons/AButton/AButton.hpp"

class Button : public AButton {
    public:
        void update(sf::RenderWindow &window) override;
};
