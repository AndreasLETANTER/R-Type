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
        if (score.has_value() && score->clock) {
            sf::Time elapsedTime = score->clock->getElapsedTime() - score->lastScoreIncrease;
            if (elapsedTime >= sf::seconds(1)) {
                score->score += 50;
                score->lastScoreIncrease = score->clock->getElapsedTime();
            }
        }
    }
    return *this;
}
