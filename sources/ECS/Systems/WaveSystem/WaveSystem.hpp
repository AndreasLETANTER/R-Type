/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** WaveSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Drawable.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Projectile.hpp"
#include "ECS/Components/Health.hpp"

/**
 * @brief The ProjectileSystem class handles the logic for updating the position of projectiles in the game.
 */
class WaveSystem {
    public:
        WaveSystem() = default;
        ~WaveSystem() = default;
        WaveSystem operator()(Registry &registry);
};
