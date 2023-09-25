/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileSystem
*/

#pragma once
#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Position.hpp"
#include "../../Components/Drawable.hpp"
#include "../../Components/Velocity.hpp"
#include "../../Components/Projectile.hpp"

class ProjectileSystem {
    public:
        ProjectileSystem() = default;
        ~ProjectileSystem() = default;
        ProjectileSystem operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities);

    protected:
    private:
};
