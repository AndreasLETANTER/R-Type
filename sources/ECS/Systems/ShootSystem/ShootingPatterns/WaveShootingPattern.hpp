/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** WaveShootingPattern
*/

#pragma once

#include "ECS/Systems/ShootSystem/ShootingPatterns/AShootingPattern.hpp"

class WaveShootingPattern : public AShootingPattern {
    public:
        void shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, Component::Drawable &draw) override;
};
