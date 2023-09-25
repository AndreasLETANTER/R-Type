/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Position
*/

#pragma once

namespace Component {
    class Position {
        public:
            Position() = default;
            double x;
            double y;
            inline Position(double x, double y) { this->x = x; this->y = y; }
    };
}
