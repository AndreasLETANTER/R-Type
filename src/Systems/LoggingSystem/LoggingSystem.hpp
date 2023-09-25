/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** LoggingSystem
*/

#pragma once

#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Position.hpp"
#include "../../Components/Velocity.hpp"

class LoggingSystem {
    public:
        LoggingSystem() = default;
        ~LoggingSystem() = default;
        LoggingSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities);

    protected:
    private:
};
