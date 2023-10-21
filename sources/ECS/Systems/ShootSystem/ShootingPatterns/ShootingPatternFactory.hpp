/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ShootingPatternFactory
*/

#pragma once

#include "LinearShootingPattern.hpp"

class ShootingPatternFactory {
    public:
        static std::unique_ptr<IShootingPattern> createShootingPattern(ShootingPattern pattern);
};
