/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** AutoMove
*/

#pragma once
#include "ECS/Components/Position.hpp"

namespace Component {
    /**
     * @brief Component that represents an entity's automatic movement from a start position to an end position.
     */
    class AutoMove {
        public:
            Component::Position start; /**< The starting position of the entity. */
            Component::Position end; /**< The ending position of the entity. */
            /**
             * @brief Constructor for AutoMove component.
             * @param start The starting position of the entity.
             * @param end The ending position of the entity.
             */
            inline AutoMove(Component::Position start, Component::Position end) { this->start = start; this->end = end; };
    };
}
