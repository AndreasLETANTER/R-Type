/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** LinearShootingPattern
*/

#pragma once

#include "ECS/Systems/ShootSystem/ShootingPatterns/IShootingPattern.hpp"

class LinearShootingPattern : public IShootingPattern {
    public:
        void shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, Component::Drawable &draw) override;
};
