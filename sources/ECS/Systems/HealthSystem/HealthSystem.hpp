/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HealthSystem
*/

#pragma once

#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Health.hpp"

/**
 * @brief The HealthSystem class handles the logic for updating the health of entities in the game.
 */
class HealthSystem {
    public:
        HealthSystem() = default;
        ~HealthSystem() = default;
        HealthSystem operator()(Registry &registry, SparseArray<Component::Health> &healths);
};
