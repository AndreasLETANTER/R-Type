/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** PowerUpTypeFactory
*/

#pragma once


#include "APowerUpType.hpp"
#include "AttackSpeedType.hpp"
#include "DamageType.hpp"
#include "HealthType.hpp"
#include "SpeedType.hpp"
#include "ECS/Components/PowerUp.hpp"

/**
 * @brief Factory class for creating PowerUpType objects.
 */
class PowerUpTypeFactory {
    public:
        /**
         * @brief Creates a PowerUpType object of the specified type.
         * 
         * @param type The type of PowerUpType object to create.
         * @return std::unique_ptr<APowerUpType> A unique pointer to the created PowerUpType object.
         */
        static std::unique_ptr<APowerUpType> createPowerUpType(PowerUpType type);
};
