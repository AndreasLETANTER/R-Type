/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** AutoMoveSystem
*/

#pragma once

#include <cmath>
#include <memory>
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
        void moveInSinusoidalPattern(std::optional<Component::Position> &pos, int dx, int dy);
        void moveInSemiCirclePattern(std::optional<Component::Position> &entityPos, double &angle);
        Component::Position getNewPos(int x, int y, double angle);
        double getAngleFromCos(int adjacent, int hypotenuse);
        double getAngleFromSin(int opposite, int hypotenuse);
};
