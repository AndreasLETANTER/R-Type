/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Projectile
*/

#include "Position.hpp"
#include "Velocity.hpp"
#include <SFML/Graphics.hpp>

#pragma once

namespace Component {
    class Projectile {
        public:
            Projectile() = default;
            Component::Position end;
            size_t speed;
            inline Projectile(Component::Position end, size_t speed) { this->end = end; this->speed = speed; }
    };
}
