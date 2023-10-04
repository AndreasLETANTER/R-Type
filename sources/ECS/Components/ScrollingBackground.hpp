/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ScrollingBackground
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Position.hpp"

namespace Component {
    /**
     * @brief Component representing a scrolling background.
     */
    class ScrollingBackground {
        public:
            Component::Position startingPos;
            Component::Position offsetLimit;

            /**
             * @brief Construct a new Scrolling Background object.
             * @param offsetLimit The width limit of the background.
             */
            inline ScrollingBackground(Component::Position startingPos, Component::Position offsetLimit) { this->startingPos = startingPos, this->offsetLimit = offsetLimit; };
    };
}
