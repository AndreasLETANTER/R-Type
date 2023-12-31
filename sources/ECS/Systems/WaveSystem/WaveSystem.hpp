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
#include "ECS/Components/EntityClass.hpp"
#include "ECS/Components/Collision.hpp"
#include "ECS/Components/AutoMove.hpp"
#include "ECS/Components/Scroll.hpp"
#include "ECS/Components/Group.hpp"

/**
 * @brief The ProjectileSystem class handles the logic for updating the position of projectiles in the game.
 */
class WaveSystem {
    public:
        WaveSystem() = default;
        ~WaveSystem() = default;

        /**
         * @brief Executes the WaveSystem on the given registry.
         *
         * @param registry The registry to execute the WaveSystem on.
         * @return WaveSystem The updated WaveSystem.
         */
        WaveSystem operator()(Registry &registry);
};
