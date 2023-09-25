/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Controllable
*/

#pragma once

namespace Component {
    class Controllable {
        public:
            bool status;
            inline Controllable(bool status) { this->status = status; }
    };
}
