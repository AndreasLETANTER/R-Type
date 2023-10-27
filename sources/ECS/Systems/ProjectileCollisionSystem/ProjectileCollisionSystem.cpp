/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileCollisionSystem
*/

#include "ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.hpp"


ProjectileCollisionSystem ProjectileCollisionSystem::operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Collision> &collisions, SparseArray<Component::Health> &healths, SparseArray<Component::Score> &scores, SparseArray<Component::Group> &groups)
{
    (void)scores;
    for (size_t i = 0; i < projectiles.size() && i < collisions.size(); i++) {
        auto &projectile = projectiles[i];
        auto &collision = collisions[i];

        if (projectile.has_value() && collision.has_value()) {
            if (i < groups.size() && groups[i].has_value() && groups[collision.value().entities_in_collision[0]].has_value()) {
                if (groups[i].value().groupId == groups[collision.value().entities_in_collision[0]].value().groupId) {
                    continue;
                }
            }
            if (collision.value().entities_in_collision.size() > 0) {
                if ((healths.size() < collision.value().entities_in_collision[0] || healths.size() < registry.entity_from_index(i))) {
                    registry.kill_entity(registry.entity_from_index(i));
                    continue;
                }
                auto &health = healths[collision.value().entities_in_collision[0]];
                if (health.has_value()) {
                    health.value().health -= projectile.value().damage;
                    if (projectile.value().shooterId >= 1 && projectile.value().shooterId <= 4) {
                        auto &score = scores[projectile.value().shooterId + 1];
                        score.value().score += 100;
                    }
                }
                registry.kill_entity(registry.entity_from_index(i));
            }
        }
    }
    return *this;
}
