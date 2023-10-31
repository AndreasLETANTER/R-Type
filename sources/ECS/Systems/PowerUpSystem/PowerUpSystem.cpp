/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** PowerUpSystem
*/

#include "ECS/Systems/PowerUpSystem/PowerUpSystem.hpp"

PowerUpSystem PowerUpSystem::operator()(Registry &registry, SparseArray<Component::Controllable> &controllables, SparseArray<Component::Collision> &collisions, SparseArray<Component::PowerUp> &powerups)
{
    for (size_t i = 0; i < powerups.size(); i++) {
        auto &powerup = powerups[i];
        auto &collision = collisions[i];

        if (powerup.has_value() && powerup.value().startTime + powerup.value().delayBeforeDispawn <= powerup.value().clock->getElapsedTime()) {
            registry.kill_entity(registry.entity_from_index(i));
            continue;
        }
        if (powerup.has_value() && collision.has_value()) {
            if (collision.value().entities_in_collision.size() > 0) {
                if (controllables.size() <= collision.value().entities_in_collision[0]) {
                    continue;
                }
                auto &controllable = controllables[collision.value().entities_in_collision[0]];
                if (controllable.has_value()) {
                    std::cout << "pdpdpdpdpd" << std::endl;
                    registry.kill_entity(registry.entity_from_index(i));
                }
            }
        }
    }
    return *this;
}
