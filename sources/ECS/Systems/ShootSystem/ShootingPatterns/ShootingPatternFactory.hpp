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
#include "CircularShootingPattern.hpp"
#include "WaveShootingPattern.hpp"

/**
 * @brief Class representing a shooting pattern factory.
 */
class ShootingPatternFactory {
    public:
        /**
         * @brief Creates a shooting pattern.
         *
         * @param pattern The pattern to create.
         * @return std::unique_ptr<AShootingPattern> The created pattern.
         */
        static std::unique_ptr<AShootingPattern> createShootingPattern(ShootingPattern pattern);
};
