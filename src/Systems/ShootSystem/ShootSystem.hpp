/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ShootSystem
*/

#pragma once

#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Position.hpp"
#include "../../Components/Drawable.hpp"
#include "../../Components/Velocity.hpp"
#include "../../Components/Projectile.hpp"
#include "../../Components/Shoot.hpp"

/**
 * @brief The ShootSystem class handles the shooting of entities in the game.
 */
class ShootSystem {
    public:
        ShootSystem() = default;
        ~ShootSystem() = default;
        ShootSystem operator()(Registry &registry, SparseArray<Component::Shoot> &shoots, SparseArray<Component::Position> &positions, SparseArray<Component::Drawable> &drawable);
};
