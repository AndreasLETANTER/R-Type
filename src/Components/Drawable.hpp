/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Drawable
*/

#pragma once
#include <SFML/Graphics.hpp>

namespace Component {
    typedef struct Drawable {
        sf::Sprite sprite;
        sf::RenderWindow *window;
        inline Drawable(sf::Sprite sprite, sf::RenderWindow *window) { this->sprite = sprite; this->window = window; }
    } Drawable;
}
