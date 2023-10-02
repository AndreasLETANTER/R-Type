/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** MonsterShoot
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace Component {
    /**
     * @brief The Shoot class represents the ability of an entity to shoot.
     */
    class MonsterShoot {
        public:
            /**
             * @brief Construct a new MonsterShoot object with default values.
             */
            MonsterShoot() = default;
            bool canShoot; /**< A boolean indicating whether the entity can shoot or not. */
            std::string bulletSpriteName; /**< The name of the bullet sprite. */
            sf::Time lastShot; /**< The time when the entity last shot. */
            sf::Time shootDelay; /**< The delay between each shot. */
            size_t damage; /**< The damage of the bullet. */
            sf::Clock *clock; /**< A pointer to the clock used to measure time. */
            /**
             * @brief Construct a new MonsterShoot object with specified values.
             * 
             * @param canShoot A boolean indicating whether the entity can shoot or not.
             * @param clock A pointer to the clock used to measure time.
             * @param shootDelay The delay between each shot.
             * @param bulletSpriteName The name of the bullet sprite.
             */
            inline MonsterShoot(bool canShoot, sf::Clock *clock, sf::Time shootDelay, size_t damage, std::string bulletSpriteName) { this->canShoot = canShoot; this->clock = clock; this->shootDelay = shootDelay; this->lastShot = clock->getElapsedTime(); this->bulletSpriteName = bulletSpriteName; this->damage = damage; }
    };
}
