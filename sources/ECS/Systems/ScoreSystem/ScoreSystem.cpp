/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ScoreSystem
*/

#include "ECS/Systems/ScoreSystem/ScoreSystem.hpp"

ScoreSystem ScoreSystem::operator()(Registry &registry, SparseArray<Component::Score> &scores)
{
    (void) registry;
    for (size_t i = 0; i < scores.size(); ++i)
    {
        auto &score = scores[i];
    }
    return *this;
}
