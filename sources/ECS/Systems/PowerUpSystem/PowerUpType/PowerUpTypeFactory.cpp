/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** PowerUpTypeFactory
*/

#include "PowerUpTypeFactory.hpp"

std::unique_ptr<APowerUpType> PowerUpTypeFactory::createPowerUpType(PowerUpType type)
{
    switch (type) {
        case PowerUpType::AttackSpeed:
            return std::make_unique<AttackSpeedType>();
        case PowerUpType::Damage:
            return std::make_unique<DamageType>();
        case PowerUpType::Health:
            return std::make_unique<HealthType>();
        case PowerUpType::Speed:
            return std::make_unique<SpeedType>();
        default:
            throw std::runtime_error("Invalid power up type");
    }
}