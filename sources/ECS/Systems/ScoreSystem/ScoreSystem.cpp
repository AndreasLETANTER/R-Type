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
        if (score.has_value()) {
            sf::Time elapsedTime = score.value().clock->getElapsedTime() - score.value().lastScoreIncrease;
            if (elapsedTime >= sf::seconds(1)) {
                score.value().score += 1;
                score.value().lastScoreIncrease = score.value().clock->getElapsedTime();
            }
        }
    }
    return *this;
}
