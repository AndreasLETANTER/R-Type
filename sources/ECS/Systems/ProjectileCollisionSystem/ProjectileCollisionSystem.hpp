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

        /**
         * @brief Handles collision between projectiles and entities with health and/or score components.
         *
         * @param registry The ECS registry.
         * @param projectiles The sparse array of projectile components.
         * @param collisions The sparse array of collision components.
         * @param healths The sparse array of health components.
         * @param scores The sparse array of score components.
         * @param groups The sparse array of group components.
         * @return ProjectileCollisionSystem The updated projectile collision system.
         */
        ProjectileCollisionSystem operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Collision> &collisions, SparseArray<Component::Health> &healths, SparseArray<Component::Score> &scores, SparseArray<Component::Group> &groups);
};
