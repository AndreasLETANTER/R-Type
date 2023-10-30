/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** PowerUp
*/

#pragma once

#include <SFML/Graphics.hpp>

enum PowerUpType {
    Speed,
    Health,
    AttackSpeed,
    Damage
};

namespace Component {
    /**
     * @brief The PowerUp class represents the ability of an entity to PowerUp.
     */
    class PowerUp {
        public:
            /**
             * @brief Construct a new PowerUp object with default values.
             */
            PowerUp() = default;

            sf::Time delayBeforeDispawn;

            PowerUpType type;

            int stat;
            
            sf::Clock *clock; /**< A pointer to the clock used to measure time. */

            inline PowerUp(sf::Time delayBeforeDispawn, PowerUpType type, sf::Clock *clock, int stat) { this->delayBeforeDispawn = delayBeforeDispawn; this->type = type; this->clock = clock; this->stat = stat;}
    };
}
