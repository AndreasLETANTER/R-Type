/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileSystem
*/

#include "ProjectileSystem.hpp"

ProjectileSystem ProjectileSystem::operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities)
{
    (void)registry;
    for (size_t i = 0; i < projectiles.size() && i < positions.size() && i < velocities.size(); i++)
    {
        auto &projectile = projectiles[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];
        if (projectile.has_value() && pos.has_value() && vel.has_value()) {
            if (pos.value().x < projectile.value().end.x) {
                vel.value().vx = projectile.value().speed;
            } else {
                registry.kill_entity(registry.entity_from_index(i));
            }
        }
    }
    return *this;
}