/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Shoot
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace Component {
    /**
     * @brief The Shoot class represents the ability of an entity to shoot.
     */
    class Shoot {
        public:
            /**
             * @brief Construct a new Shoot object with default values.
             */
            Shoot() = default;
            bool canShoot; /**< A boolean indicating whether the entity can shoot or not. */
            std::string bulletSpriteName; /**< The name of the bullet sprite. */
            sf::Time lastShot; /**< The time when the entity last shot. */
            sf::Time shootDelay; /**< The delay between each shot. */
            size_t damage; /**< The damage of the bullet. */
            sf::Clock *clock; /**< A pointer to the clock used to measure time. */
            /**
             * @brief Construct a new Shoot object with specified values.
             * 
             * @param canShoot A boolean indicating whether the entity can shoot or not.
             * @param clock A pointer to the clock used to measure time.
             * @param shootDelay The delay between each shot.
             * @param bulletSpriteName The name of the bullet sprite.
             */
            inline Shoot(bool canShoot, sf::Clock *clock, sf::Time shootDelay, size_t damage, std::string bulletSpriteName) { this->canShoot = canShoot; this->clock = clock; this->shootDelay = shootDelay; this->lastShot = clock->getElapsedTime(); this->bulletSpriteName = bulletSpriteName; this->damage = damage; }
    };
}
