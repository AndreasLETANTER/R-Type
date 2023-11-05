/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** CollisionSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Collision.hpp"

/**
 * @brief The CollisionSystem class handles the collision detection and resolution for entities with a Position and Collision component.
 */
class CollisionSystem {
    public:
        CollisionSystem() = default;
        ~CollisionSystem() = default;

        /**
         * @brief CollisionSystem functor that takes a registry, positions and collisions arrays as arguments and returns a CollisionSystem object.
         *
         * @param registry The registry object that contains all entities and their components.
         * @param positions The SparseArray of Position components.
         * @param collisions The SparseArray of Collision components.
         * @return CollisionSystem The CollisionSystem object.
         */
        CollisionSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Collision> &collisions);
};
