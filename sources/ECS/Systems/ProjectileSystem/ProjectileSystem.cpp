/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ProjectileSystem
*/

#include "ECS/Systems/ProjectileSystem/ProjectileSystem.hpp"

#include <cmath>

ProjectileSystem ProjectileSystem::operator()(Registry &registry, SparseArray<Component::Projectile> &projectiles, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities)
{
    for (size_t i = 0; i < projectiles.size() && i < positions.size() && i < velocities.size(); i++)
    {
        auto &projectile = projectiles[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];

        if (projectile.has_value() && pos.has_value() && vel.has_value()) {
            sf::Vector2f direction = {
                static_cast<float>(projectile.value().end.x - projectile.value().start.x),
                static_cast<float>(projectile.value().end.y - projectile.value().start.y)
            };
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            direction.x /= length;
            direction.y /= length;
            pos.value().x += static_cast<int>(direction.x * static_cast<float>(projectile.value().speed));
            pos.value().y += static_cast<int>(direction.y * static_cast<float>(projectile.value().speed));

            if ((direction.x > 0 && pos.value().x > projectile.value().end.x) ||
                (direction.x < 0 && pos.value().x < projectile.value().end.x) ||
                (direction.y > 0 && pos.value().y > projectile.value().end.y) ||
                (direction.y < 0 && pos.value().y < projectile.value().end.y)) {
                registry.kill_entity(registry.entity_from_index(i));
            }
        }
    }
    return *this;
}
