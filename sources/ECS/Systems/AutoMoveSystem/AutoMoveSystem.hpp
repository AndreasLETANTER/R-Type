/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** AutoMoveSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/AutoMove.hpp"

/**
 * @brief The AutoMoveSystem class is responsible for updating the position of entities with the AutoMove component.
 */
class AutoMoveSystem {
    public:
        AutoMoveSystem() = default;
        ~AutoMoveSystem() = default;
        AutoMoveSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::AutoMove> &autoMoves);
};
