/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** EntityClassSystem
*/

#include "EntityClassSystem.hpp"

EntityClassSystem EntityClassSystem::operator()(Registry &registry, SparseArray<Component::EntityClass> &entityclasses, SparseArray<Component::Shoot> &shoots, SparseArray<Component::Health> &healths, SparseArray<Component::Velocity> &velocities)
{
    (void) registry;
    for (size_t i = 0; i < entityclasses.size(); i++) {
        auto &shoot = shoots[i];
        auto &health = healths[i];
        auto &velocity = velocities[i];

        if (entityclasses[i].has_value()) {
            shoot.value().pattern = entityclasses[i].value().shootingPattern;
            shoot.value().damage = entityclasses[i].value().damage;
            shoot.value().shootDelay = sf::Time(sf::milliseconds(entityclasses[i].value().shootingDelay));
            health.value().health = entityclasses[i].value().health;
            velocity.value().speed = entityclasses[i].value().speed;
        }
    }
    return *this;
}
