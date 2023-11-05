/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ScoreSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Score.hpp"

/**
 * @brief The ScoreSystem class handles the logic for updating the score of entities in the game.
 */
class ScoreSystem {
    public:
        ScoreSystem() = default;
        ~ScoreSystem() = default;

        /**
         * @brief Calculates the score of each player based on their current state and updates the score component accordingly.
         *
         * @param registry The registry containing all the entities and their components.
         * @param scores The sparse array containing the score components of all the players.
         * @return ScoreSystem The updated score system.
         */
        ScoreSystem operator()(Registry &registry, SparseArray<Component::Score> &scores);
};
