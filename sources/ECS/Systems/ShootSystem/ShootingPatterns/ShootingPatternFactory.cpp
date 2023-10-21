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
        case WAVE:
            return std::make_unique<WaveShootingPattern>();
        default:
            return std::make_unique<LinearShootingPattern>();
    }
}
