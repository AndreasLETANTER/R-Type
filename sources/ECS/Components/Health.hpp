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
            /**
             * @brief Default constructor for Health class.
             */
            Health() = default;
            int health; /**< The health of the entity. */
            /**
             * @brief Constructor for Health class.
             * @param health The health of the entity.
             */
            inline Health(int health) { this->health = health; }
    };
}
