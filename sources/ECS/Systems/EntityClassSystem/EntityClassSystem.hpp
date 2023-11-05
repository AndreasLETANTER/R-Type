/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** EntityClassSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/EntityClass.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Health.hpp"
#include "ECS/Components/Shoot.hpp"

/**
 * @brief The EntityClassSystem class handles the stats of each entity class.
 */
class EntityClassSystem {
    public:
        EntityClassSystem() = default;
        ~EntityClassSystem() = default;

        /**
         * @brief Applies the EntityClassSystem on the given registry and component arrays.
         *
         * @param registry The registry to apply the system on.
         * @param entityclasses The array of EntityClass components.
         * @param shoots The array of Shoot components.
         * @param healths The array of Health components.
         * @param velocities The array of Velocity components.
         * @return EntityClassSystem The updated EntityClassSystem.
         */
        EntityClassSystem operator()(Registry &registry, SparseArray<Component::EntityClass> &entityclasses, SparseArray<Component::Shoot> &shoots, SparseArray<Component::Health> &healths, SparseArray<Component::Velocity> &velocities);
};
