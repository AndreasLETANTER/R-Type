/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Shoot
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "ECS/Systems/ShootSystem/ShootingPatterns/IShootingPattern.hpp"

enum ShootingPattern {
    LINEAR,
    SPREAD,
    SPIRAL,
    CIRCULAR,
    WAVE,
    RANDOM,
    LASER
};

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
            ShootingPattern pattern; /**< The shooting pattern of the entity. */
            std::string bulletSpriteName; /**< The name of the bullet sprite. */
            int direction; /**< The direction of the bullet. */
            int offsetLimit; /**< The offset limit of the bullet. */
            sf::Time lastShot; /**< The time when the entity last shot. */
            sf::Time shootDelay; /**< The delay between each shot. */
            size_t damage; /**< The damage of the bullet. */
            sf::Clock *clock; /**< A pointer to the clock used to measure time. */

            /**
             * @brief The ID of the player controlling the entity.
             */
            unsigned int playerId;

            /**
             * @brief The key pressed by the player controlling the entity.
             */
            sf::Keyboard::Key keyPressed = sf::Keyboard::Unknown;

            /**
             * @brief Construct a new Shoot object with specified values.
             *
             * @param canShoot A boolean indicating whether the entity can shoot or not.
             * @param clock A pointer to the clock used to measure time.
             * @param shootDelay The delay between each shot.
             * @param bulletSpriteName The name of the bullet sprite.
             */
            inline Shoot(unsigned int playerId, bool canShoot, ShootingPattern pattern, sf::Clock *clock, sf::Time shootDelay, size_t damage, std::string bulletSpriteName, int direction, int offsetLimit) { this->canShoot = canShoot; this->pattern = pattern; this->clock = clock; this->shootDelay = shootDelay; this->lastShot = clock->getElapsedTime(); this->bulletSpriteName = bulletSpriteName; this->damage = damage; this->playerId = playerId; this->direction = direction; this->offsetLimit = offsetLimit; }
    };
}
