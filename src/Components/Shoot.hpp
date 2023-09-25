/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Shoot
*/

#pragma once

namespace Component {
    class Shoot {
        public:
            Shoot() = default;
            bool canShoot;
            sf::Time lastShot;
            sf::Time shootDelay;
            sf::Clock *clock;
            inline Shoot(bool canShoot, sf::Clock *clock, sf::Time shootDelay) { this->canShoot = canShoot; this->clock = clock; this->shootDelay = shootDelay; this->lastShot = clock->getElapsedTime();}
    };
}
