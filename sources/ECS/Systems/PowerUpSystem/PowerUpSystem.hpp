/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** PowerUpSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Controllable.hpp"
#include "ECS/Components/Collision.hpp"
#include "ECS/Components/PowerUp.hpp"

/**
 * @brief The PowerUpSystem class handles the power ups of the game.
 */
class PowerUpSystem {
    public:
        PowerUpSystem() = default;
        ~PowerUpSystem() = default;
        PowerUpSystem operator()(Registry &registry, SparseArray<Component::Controllable> &controllables, SparseArray<Component::Collision> &collisions, SparseArray<Component::PowerUp> &powerups);
};
