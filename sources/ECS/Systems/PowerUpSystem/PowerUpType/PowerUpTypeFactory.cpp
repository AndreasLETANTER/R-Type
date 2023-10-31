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
    }
}