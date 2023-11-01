/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileCollisionSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Collision.hpp"
#include "ECS/Components/Projectile.hpp"
#include "ECS/Components/Health.hpp"
#include "ECS/Components/EntityClass.hpp"
#include "ECS/Components/Score.hpp"
#include "ECS/Components/Group.hpp"

/**
 * @brief The ProjectileSystem class handles the logic for updating the position of projectiles in the game.
 */
class ProjectileCollisionSystem {
    public:
        ProjectileCollisionSystem() = default;
        ~ProjectileCollisionSystem() = default;
        ProjectileCollisionSystem operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Collision> &collisions, SparseArray<Component::Health> &healths, SparseArray<Component::Score> &scores, SparseArray<Component::Group> &groups);
};
