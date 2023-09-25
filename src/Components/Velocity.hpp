/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Velocity
*/

#pragma once

namespace Component {
    class Velocity {
        public:
            Velocity() = default;
            double vx;
            double vy;
            inline Velocity(double vx, double vy) { this->vx = vx; this->vy = vy; }
    };
}
