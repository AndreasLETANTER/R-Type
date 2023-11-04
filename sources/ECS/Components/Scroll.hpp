/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Scroll
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Position.hpp"

namespace Component {
    /**
     * @brief Component representing a scrolling background.
     */
    class Scroll {
        public:
            Component::Position startingPos;
            Component::Position offsetLimit;
            int pausePosX;

            /**
             * @brief Construct a new Scrolling Background object.
             *
             * @param startingPos The starting position of the background.
             * @param offsetLimit The width limit of the background.
             * @param pausePosX The X position where the background should stop scrolling.
             */
            inline Scroll(Component::Position startingPos, Component::Position offsetLimit, int pausePosX) { this->startingPos = startingPos, this->offsetLimit = offsetLimit, this->pausePosX = pausePosX; };
    };
}
