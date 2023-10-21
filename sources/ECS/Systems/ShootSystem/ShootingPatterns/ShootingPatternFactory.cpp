/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ShootingPatternFactory
*/

#include "ShootingPatternFactory.hpp"

std::unique_ptr<IShootingPattern> ShootingPatternFactory::createShootingPattern(ShootingPattern pattern)
{
    switch (pattern) {
        case LINEAR:
            return std::make_unique<LinearShootingPattern>();
        default:
            return std::make_unique<LinearShootingPattern>();
    }
}
