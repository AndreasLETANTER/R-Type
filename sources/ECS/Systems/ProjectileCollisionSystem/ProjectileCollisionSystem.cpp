/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileCollisionSystem
*/

#include "ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.hpp"


ProjectileCollisionSystem ProjectileCollisionSystem::operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Collision> &collisions, SparseArray<Component::Health> &healths, SparseArray<Component::Score> &scores)
{
    (void)scores;
    for (size_t i = 0; i < projectiles.size() && i < collisions.size(); i++) {
        auto &projectile = projectiles[i];
        auto &collision = collisions[i];

        if (projectile.has_value() && collision.has_value()) {
            if (collision.value().entities_in_collision.size() > 0) {
                auto &score = scores[projectile.value().shooterId];
                if ((healths.size() < collision.value().entities_in_collision[0] || healths.size() < registry.entity_from_index(i))) {
                    registry.kill_entity(registry.entity_from_index(i));
                    score.value().score += 5;
                    std::cout << "Score: " << score.value().score << std::endl;
                    continue;
                }
                auto &health = healths[collision.value().entities_in_collision[0]];
                if (health.has_value()) {
                    health.value().health -= projectile.value().damage;
                    score.value().score += 3;
                    std::cout << "Score after hitting: " << score.value().score << std::endl;
                }
                registry.kill_entity(registry.entity_from_index(i));
            }
        }
    }
    return *this;
}
