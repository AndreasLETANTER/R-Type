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

        /**
         * @brief Executes the ProjectileSystem on the given registry and component arrays.
         *
         * @param registry The registry containing the entities and their components.
         * @param projectiles The array of Projectile components.
         * @param positions The array of Position components.
         * @param velocities The array of Velocity components.
         * @return ProjectileSystem The updated ProjectileSystem.
         */
        ProjectileSystem operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities);
};
