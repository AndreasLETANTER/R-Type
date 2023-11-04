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
    WHIRLWIND,
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
            bool canShoot;
            ShootingPattern pattern;
            std::string bulletSpriteName;
            int direction;
            int offsetLimit;
            sf::Time lastShot;
            sf::Time shootDelay;
            size_t damage;
            sf::Clock *clock;
            unsigned int playerId;
            std::map<sf::Keyboard::Key, bool> m_keyMapState = {
                {sf::Keyboard::Z, false},
                {sf::Keyboard::S, false},
                {sf::Keyboard::Q, false},
                {sf::Keyboard::D, false},
                {sf::Keyboard::Space, false}
            };

            /**
             * @brief Construct a new Shoot object with specified values.
             *
             * @param playerId The ID of the player controlling the entity.
             * @param canShoot A boolean indicating whether the entity can shoot or not.
             * @param pattern The shooting pattern of the entity.
             * @param clock A pointer to the clock used to measure time.
             * @param shootDelay The delay between each shot.
             * @param damage The damage of the bullet.
             * @param bulletSpriteName The name of the bullet sprite.
             * @param direction The direction of the bullet.
             * @param offsetLimit The offset limit of the bullet.
             */
            inline Shoot(unsigned int playerId, bool canShoot, ShootingPattern pattern, sf::Clock *clock, sf::Time shootDelay, size_t damage, std::string bulletSpriteName, int direction, int offsetLimit) { this->canShoot = canShoot; this->pattern = pattern; this->clock = clock; this->shootDelay = shootDelay; this->lastShot = clock->getElapsedTime(); this->bulletSpriteName = bulletSpriteName; this->damage = damage; this->playerId = playerId; this->direction = direction; this->offsetLimit = offsetLimit; }
    };
}
