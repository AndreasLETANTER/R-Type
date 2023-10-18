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
            sf::Clock *clock;
            sf::Time lastTime;
            int pausePosX;
            sf::Time pauseTime;

            /**
             * @brief Construct a new Scrolling Background object.
             * @param offsetLimit The width limit of the background.
             */
            inline Scroll(Component::Position startingPos, Component::Position offsetLimit, sf::Clock *clock, int pausePosX, sf::Time pauseTime) { this->startingPos = startingPos, this->offsetLimit = offsetLimit, this->clock = clock, this->lastTime = clock->getElapsedTime(), this->pausePosX = pausePosX, this->pauseTime = pauseTime; };
    };
}
