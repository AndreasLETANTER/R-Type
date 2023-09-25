/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** AutoMove
*/

#pragma once
#include "Position.hpp"

namespace Component {
    class AutoMove {
        public:
            Component::Position start;
            Component::Position end;
            inline AutoMove(Component::Position start, Component::Position end) { this->start = start; this->end = end; };
    };
}
