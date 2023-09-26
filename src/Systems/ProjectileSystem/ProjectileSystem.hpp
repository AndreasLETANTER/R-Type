/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileSystem
*/

#pragma once
#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Position.hpp"
#include "../../Components/Drawable.hpp"
#include "../../Components/Velocity.hpp"
#include "../../Components/Projectile.hpp"

/**
 * @brief The ProjectileSystem class handles the logic for updating the position of projectiles in the game.
 */
class ProjectileSystem {
    public:
        ProjectileSystem() = default;
        ~ProjectileSystem() = default;
        ProjectileSystem operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities);
};
