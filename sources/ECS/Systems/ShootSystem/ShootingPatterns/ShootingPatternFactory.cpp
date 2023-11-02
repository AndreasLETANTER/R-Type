/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ShootingPatternFactory
*/

#include "ShootingPatternFactory.hpp"

std::unique_ptr<AShootingPattern> ShootingPatternFactory::createShootingPattern(ShootingPattern pattern)
{
    switch (pattern) {
        case LINEAR:
            return std::make_unique<LinearShootingPattern>();
        case SPREAD:
            return std::make_unique<SpreadShootingPattern>();
        case CIRCULAR:
            return std::make_unique<CircularShootingPattern>();
        case WAVE:
            return std::make_unique<WaveShootingPattern>();
        case WHIRLWIND:
            return std::make_unique<WhirlwindShootingPattern>();
        default:
            return std::make_unique<LinearShootingPattern>();
    }
}
