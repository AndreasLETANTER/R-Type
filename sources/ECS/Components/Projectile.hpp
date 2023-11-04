/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Projectile
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "ECS/Components/Position.hpp"
#include "ECS/Components/Velocity.hpp"

namespace Component {
    /**
     * @brief Projectile component class that represents a projectile in the game.
     */
    class Projectile {
        public:
            Projectile() = default;

            Component::Position start;
            Component::Position end;
            size_t speed;
            size_t damage;
            int shooterId;

            /**
             * @brief Constructor for Projectile class that initializes the end position and speed of the projectile.
             *
             * @param start The start position of the projectile.
             * @param end The end position of the projectile.
             * @param speed The speed of the projectile in pixels per second.
             * @param damage The damage of the projectile.
             * @param id The ID of the entity that shot the projectile.
             */
            inline Projectile(Component::Position start, Component::Position end, size_t speed, size_t damage, int id) { this->start = start; this->end = end; this->speed = speed; this->damage = damage; this->shooterId = id; }
    };
}
