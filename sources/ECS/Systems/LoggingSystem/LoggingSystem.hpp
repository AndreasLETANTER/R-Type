/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** LoggingSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Velocity.hpp"

/**
 * @brief The LoggingSystem class is responsible for logging the positions and velocities of entities in the game.
 */
class LoggingSystem {
    public:
        LoggingSystem() = default;
        ~LoggingSystem() = default;

        /**
         * @brief Calls the LoggingSystem with the given registry, positions and velocities.
         *
         * @param registry The registry to use.
         * @param positions The positions to use.
         * @param velocities The velocities to use.
         * @return LoggingSystem The LoggingSystem.
         */
        LoggingSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities);
};
