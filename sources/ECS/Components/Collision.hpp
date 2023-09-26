/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Collision
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../EntityClass/Entity.hpp"

namespace Component {
    /**
     * @brief Component that represents a collision box for an entity.
     */
    class Collision {
        public:
            std::vector<Entity> entities_in_collision; /**< List of entities that are currently colliding with this collision box. */
            int height; /**< Height of the collision box. */
            int width; /**< Width of the collision box. */
            /**
             * @brief Construct a new Collision object with the given height and width.
             * 
             * @param height Height of the collision box.
             * @param width Width of the collision box.
             */
            inline Collision(int height, int width) { this->height = height; this->width = width; }
    };
}
