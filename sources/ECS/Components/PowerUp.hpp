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
    Speed, /**< Increases the entity's speed. */
    Health, /**< Increases the entity's health. */
    AttackSpeed, /**< Increases the entity's attack speed. */
    Damage /**< Increases the entity's damage. */
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

            sf::Time delayBeforeDispawn; /**< The time before the power-up disappears. */

            sf::Time startTime; /**< The time when the power-up was spawned. */

            PowerUpType type; /**< The type of the power-up. */

            int stat; /**< The amount by which the power-up increases the entity's stat. */
            
            sf::Clock *clock; /**< A pointer to the clock used to measure time. */

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
