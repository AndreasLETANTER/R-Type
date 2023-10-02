/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Drawable.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Projectile.hpp"

/**
 * @brief The ProjectileSystem class handles the logic for updating the position of projectiles in the game.
 */
class ProjectileSystem {
    public:
        ProjectileSystem() = default;
        ~ProjectileSystem() = default;
        ProjectileSystem operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities);
};
