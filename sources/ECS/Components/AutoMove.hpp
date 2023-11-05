/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** AutoMove
*/

#pragma once
#include "ECS/Components/Position.hpp"
#include <SFML/Graphics.hpp>

namespace Component {
    /**
     * @brief Component that represents an entity's automatic movement from a start position to an end position.
     */
    class AutoMove {
        public:
            Component::Position start; /**< The starting position of the entity. */
            Component::Position end; /**< The ending position of the entity. */
            double circleCount; /**< The amount of circles to be browsed by the entity*/
            double browsedDistance; /**< The distance browsed by the entity*/
            double speed; /**< The movement speed of the entity*/
            int shapeIndex; /**< The index of the shape to be browsed by the entity*/
            bool isEntityMovingForward; /**< The direction of the entity*/
            bool isEntityMoving; /**< The direction of the entity*/
            sf::Time lastMove; /**< The last time the entity moved*/
            sf::Clock *clock; /**< A pointer to the clock used to measure time. */
            /**
             * @brief Constructor for AutoMove component.
             * @param start The starting position of the entity.
             * @param end The ending position of the entity.
             */
            inline AutoMove(Component::Position start, Component::Position end, double circleCount, double speed, sf::Clock *clock) { this->start = start; this->end = end; this->circleCount = circleCount; this->speed = speed; this->browsedDistance = 0.0f; this->shapeIndex = 0; this->isEntityMovingForward = true; this->isEntityMoving = false; this->clock = clock; this->lastMove = this->clock->getElapsedTime(); };
    };
}
