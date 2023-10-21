/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ShootingPatternFactory
*/

#pragma once

#include "AShootingPattern.hpp"
#include "LinearShootingPattern.hpp"
#include "SpreadShootingPattern.hpp"
#include "WaveShootingPattern.hpp"

class ShootingPatternFactory {
    public:
        static std::unique_ptr<AShootingPattern> createShootingPattern(ShootingPattern pattern);
};
