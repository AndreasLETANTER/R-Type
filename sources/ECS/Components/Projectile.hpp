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
            /**
             * @brief Default constructor for Projectile class.
             */
            Projectile() = default;
            /**
             * @brief The start position of the projectile.
             */
            Component::Position start;
            /**
             * @brief The end position of the projectile.
             */
            Component::Position end;
            /**
             * @brief The speed of the projectile in pixels per second.
             */
            size_t speed;
            /**
             * @brief The damage of the projectile.
             */
            size_t damage;
            /**
             * @brief Constructor for Projectile class that initializes the end position and speed of the projectile.
             * @param end The end position of the projectile.
             * @param speed The speed of the projectile in pixels per second.
             * @param damage The damage of the projectile.
             */
            inline Projectile(Component::Position start, Component::Position end, size_t speed, size_t damage) { this->start = start; this->end = end; this->speed = speed; this->damage = damage; }
    };
}
