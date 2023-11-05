/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** PowerUpSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/EntityClass.hpp"
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

        /**
         * @brief Applies power-ups to entities in the game.
         *
         * @param registry The registry containing all entities and their components.
         * @param entityclasses The sparse array of entity classes.
         * @param controllables The sparse array of controllable components.
         * @param collisions The sparse array of collision components.
         * @param powerups The sparse array of power-up components.
         * @return PowerUpSystem The updated power-up system.
         */
        PowerUpSystem operator()(Registry &registry, SparseArray<Component::EntityClass> &entityclasses, SparseArray<Component::Controllable> &controllables, SparseArray<Component::Collision> &collisions, SparseArray<Component::PowerUp> &powerups);
};
