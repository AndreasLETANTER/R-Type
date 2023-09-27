/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HealthSystem
*/

#include "HealthSystem.hpp"

HealthSystem HealthSystem::operator()(Registry &registry, SparseArray<Component::Health> &healths)
{
    (void)registry;
    for (size_t i = 0; i < healths.size(); ++i)
    {
        auto &health = healths[i];

        if (health.has_value() && health.value().health <= 0) {
            registry.kill_entity(registry.entity_from_index(i));
        }
    }
    return *this;
}
