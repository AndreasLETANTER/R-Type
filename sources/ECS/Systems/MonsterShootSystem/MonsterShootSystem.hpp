/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ShootSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Drawable.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Projectile.hpp"
#include "ECS/Components/MonsterShoot.hpp"
#include "ECS/Components/Collision.hpp"

/**
 * @brief The ShootSystem class handles the shooting of entities in the game.
 */
class MonsterShootSystem {
    public:
        MonsterShootSystem() = default;
        ~MonsterShootSystem() = default;
        MonsterShootSystem operator()(Registry &registry, SparseArray<Component::MonsterShoot> &shoots, SparseArray<Component::Position> &positions, SparseArray<Component::Drawable> &drawable);
};
