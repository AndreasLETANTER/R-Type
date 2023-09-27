/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileCollisionSystem
*/

#include "ProjectileCollisionSystem.hpp"

ProjectileCollisionSystem ProjectileCollisionSystem::operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Collision> &collisions)
{
    for (size_t i = 0; i < projectiles.size() && i < collisions.size(); i++) {
        auto &projectile = projectiles[i];
        auto &collision = collisions[i];
        if (projectile.has_value() && collision.has_value()) {
            if (collision.value().entities_in_collision.size() > 0) {
                registry.kill_entity(registry.entity_from_index(collision.value().entities_in_collision[0]));
                registry.kill_entity(registry.entity_from_index(i));
            }
        }
    }
    return *this;
}
