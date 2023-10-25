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
        ScoreSystem operator()(Registry &registry, SparseArray<Component::Score> &scores);
};
