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

/**
 * @brief The LoggingSystem class is responsible for logging the positions and velocities of entities in the game.
 */
class LoggingSystem {
    public:
        LoggingSystem() = default;
        ~LoggingSystem() = default;
        LoggingSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities);
};
