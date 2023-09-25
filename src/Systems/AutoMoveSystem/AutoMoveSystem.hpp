/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** AutoMoveSystem
*/

#pragma once
#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Position.hpp"
#include "../../Components/AutoMove.hpp"

class AutoMoveSystem {
    public:
        AutoMoveSystem() = default;
        ~AutoMoveSystem() = default;
        AutoMoveSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::AutoMove> &autoMoves);

    protected:
    private:
};
