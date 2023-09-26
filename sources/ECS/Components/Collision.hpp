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
    class Collision {
        public:
            std::vector<Entity> entities_in_collision;
            int height;
            int width;
            inline Collision(int height, int width) { this->height = height; this->width = width; }
    };
}
