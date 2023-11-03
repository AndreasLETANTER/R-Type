/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileCollisionSystem
*/

#include "ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.hpp"


ProjectileCollisionSystem ProjectileCollisionSystem::operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Collision> &collisions, SparseArray<Component::Health> &healths, SparseArray<Component::Score> &scores, SparseArray<Component::Group> &groups)
{
    for (size_t i = 0; i < projectiles.size() && i < collisions.size(); i++) {
        auto &projectile = projectiles[i];
        auto &collision = collisions[i];
        if (projectile.has_value() && collision.has_value()) {
            if (i < groups.size() && groups[i].has_value() && collision.value().entities_in_collision.size() > 0 && (groups.size() >= collision.value().entities_in_collision[0]) && groups[collision.value().entities_in_collision[0]].has_value()) {
                if (groups[i].value().groupId == groups[collision.value().entities_in_collision[0]].value().groupId || groups[i].value().groupId == 0 || groups[collision.value().entities_in_collision[0]].value().groupId == 0) {
                    continue;
                }
            }
            if (collision.value().entities_in_collision.size() > 0) {
                for (unsigned int j = 0; j < collision.value().entities_in_collision.size(); j++) {
                    if ((healths.size() < collision.value().entities_in_collision[j])) {
                        continue;
                    }
                    auto &health = healths[collision.value().entities_in_collision[j]];
                    if (health.has_value()) {
                        health.value().health -= projectile.value().damage;
                        if (projectile.value().shooterId >= 1 && projectile.value().shooterId <= 4) {
                            if ((int) scores.size() < projectile.value().shooterId + 1 || scores[projectile.value().shooterId + 1].has_value() == false) {
                                continue;
                            }
                            auto &score = scores[projectile.value().shooterId + 1];
                            score.value().score += 100;
                        }
                    }
                }
                registry.kill_entity(registry.entity_from_index(i));
            }
        }
    }
    return *this;
}
