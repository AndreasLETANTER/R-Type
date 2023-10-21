/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** SpreadShootingPattern
*/

#pragma once

#include "ECS/Systems/ShootSystem/ShootingPatterns/IShootingPattern.hpp"

class SpreadShootingPattern : public IShootingPattern {
    public:
        void shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, Component::Drawable &draw) override;
};
