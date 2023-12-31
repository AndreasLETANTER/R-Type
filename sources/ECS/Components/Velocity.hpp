/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Velocity
*/

#pragma once

namespace Component {
    /**
     * @brief The Velocity class represents the velocity of an entity in a 2D space.
     */
    class Velocity {
        public:
            Velocity() = default;

            double vx;
            double vy;
            int speed;

            /**
             * @brief Constructor for Velocity class.
             *
             * @param vx The velocity on the x-axis.
             * @param vy The velocity on the y-axis.
             * @param speed The speed of the entity.
             */
            inline Velocity(double vx, double vy, int speed) { this->vx = vx; this->vy = vy; this->speed = speed; }
    };
}
