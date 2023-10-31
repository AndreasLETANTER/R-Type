/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HealthSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Health.hpp"
#include "ECS/Components/Group.hpp"
#include "ECS/Components/Collision.hpp"
#include "ECS/Components/PowerUp.hpp"

/**
 * @brief The HealthSystem class handles the logic for updating the health of entities in the game.
 */
class HealthSystem {
    public:
        HealthSystem() = default;
        ~HealthSystem() = default;
        HealthSystem operator()(Registry &registry, SparseArray<Component::Health> &healths, SparseArray<Component::Position> &positions);
};
