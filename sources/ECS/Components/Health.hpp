/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Health
*/

#pragma once

namespace Component {
    /**
     * @brief This component is used to represent the health of an entity.
     */
    class Health {
        public:
            Health() = default;
            int health;

            /**
             * @brief Constructor for Health class.
             *
             * @param health The health of the entity.
             */
            inline Health(int health) { this->health = health; }
    };
}
