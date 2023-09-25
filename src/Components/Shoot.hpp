/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Shoot
*/

#pragma once

namespace Component {
    class Shoot {
        public:
            Shoot() = default;
            bool canShoot;
            inline Shoot(bool canShoot) { this->canShoot = canShoot; }
    };
}
