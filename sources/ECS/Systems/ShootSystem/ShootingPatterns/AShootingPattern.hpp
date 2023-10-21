/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AShootingPattern
*/

#pragma once

#include "ECS/Systems/ShootSystem/ShootingPatterns/IShootingPattern.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Projectile.hpp"
#include "ECS/Components/Collision.hpp"

namespace Component {
    class Shoot;
    class Position;
    class Drawable;
    class Velocity;
    class Projectile;
    class Collision;
}

class AShootingPattern : public IShootingPattern {
    public:
        virtual ~AShootingPattern() = default;
        virtual void shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, Component::Drawable &draw) = 0;
        void createProjectile(Registry &registry, Component::Drawable &draw, std::string bulletSpriteName, Component::Position initialPos, Component::Position endPos, size_t damage);
};
