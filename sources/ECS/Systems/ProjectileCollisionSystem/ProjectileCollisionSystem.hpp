/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileCollisionSystem
*/

#pragma once
#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Collision.hpp"
#include "../../Components/Projectile.hpp"
#include "../../Components/Health.hpp"

/**
 * @brief The ProjectileSystem class handles the logic for updating the position of projectiles in the game.
 */
class ProjectileCollisionSystem {
    public:
        ProjectileCollisionSystem() = default;
        ~ProjectileCollisionSystem() = default;
        ProjectileCollisionSystem operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Collision> &collisions, SparseArray<Component::Health> &healths);
};
