/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** PositionSystem
*/

#pragma once
#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Velocity.hpp"

/**
 * @brief The PositionSystem class updates the position of entities based on their velocity.
 */
class PositionSystem {
    public:
        PositionSystem() = default;
        ~PositionSystem() = default;
        PositionSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities);
};
