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

class PowerUpTypeFactory {
    public:
        static std::unique_ptr<APowerUpType> createPowerUpType(PowerUpType type);
};

