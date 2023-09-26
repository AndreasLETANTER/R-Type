/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** PositionSystem
*/

#include "PositionSystem.hpp"
#include <iostream>

PositionSystem PositionSystem::operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities)
{
    (void) registry;
    for (size_t i = 0; i < positions.size() && i < velocities.size(); ++i)
    {
        auto &pos = positions[i];
        auto &vel = velocities[i];

        if (pos.has_value() && vel.has_value()) {
            pos.value().x += vel.value().vx;
            pos.value().y += vel.value().vy;
            vel.value().vx = 0;
            vel.value().vy = 0;
        }
    }
    return *this;
}