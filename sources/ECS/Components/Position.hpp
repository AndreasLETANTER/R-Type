/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Position
*/

#pragma once

namespace Component {
    /**
     * @brief This component is used to represent the position of an entity in 2D space.
     */
    class Position {
        public:
            /**
             * @brief Default constructor for Position class.
             */
            Position() = default;

            double x;
            double y;

            /**
             * @brief Constructor for Position class.
             *
             * @param x The x coordinate of the position.
             * @param y The y coordinate of the position.
             */
            inline Position(double x, double y) { this->x = x; this->y = y; }
    };
}
