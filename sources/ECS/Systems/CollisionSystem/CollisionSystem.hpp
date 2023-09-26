/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** CollisionSystem
*/

#pragma once

#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Position.hpp"
#include "../../Components/Collision.hpp"

/**
 * @brief The CollisionSystem class handles the collision detection and resolution for entities with a Position and Collision component.
 */
class CollisionSystem {
    public:
        CollisionSystem() = default;
        ~CollisionSystem() = default;

        CollisionSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Collision> &collisions);
};