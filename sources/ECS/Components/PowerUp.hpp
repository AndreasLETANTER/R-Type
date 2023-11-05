/**
 * @file PowerUp.hpp
 * @brief This file contains the declaration of the PowerUp component class.
 */

#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief The PowerUpType enum represents the different types of power-ups.
 */
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
            PowerUp() = default;

            sf::Time delayBeforeDispawn;
            sf::Time startTime;
            PowerUpType type;
            int stat;
            sf::Clock *clock;

            /**
             * @brief Construct a new PowerUp object with the given parameters.
             *
             * @param delayBeforeDispawn The time before the power-up disappears.
             * @param type The type of the power-up.
             * @param clock A pointer to the clock used to measure time.
             * @param stat The amount by which the power-up increases the entity's stat.
             */
            inline PowerUp(sf::Time delayBeforeDispawn, PowerUpType type, sf::Clock *clock, int stat) { this->delayBeforeDispawn = delayBeforeDispawn; this->type = type; this->clock = clock; this->stat = stat; startTime = clock->getElapsedTime();}
    };
}
