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
#include "ECS/Components/Shoot.hpp"
#include "ECS/Components/Collision.hpp"
#include "ECS/Components/Group.hpp"

/**
 * @brief The ShootSystem class handles the shooting of entities in the game.
 */
class ShootSystem {
    public:
        ShootSystem() = default;
        ~ShootSystem() = default;
        ShootSystem operator()(Registry &registry, SparseArray<Component::Shoot> &shoots, SparseArray<Component::Position> &positions, SparseArray<Component::Drawable> &drawable, SparseArray<Component::Group> &groups);
};
