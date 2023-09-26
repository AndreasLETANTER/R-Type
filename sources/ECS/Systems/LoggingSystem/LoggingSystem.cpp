/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** LoggingSystem
*/

#include "LoggingSystem.hpp"

LoggingSystem LoggingSystem::operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Velocity> &velocities)
{
    (void) registry;
    for (size_t i = 0; i < positions.size() && i < velocities.size(); ++i) {
        auto const &pos = positions[i];
        auto const &vel = velocities[i];

        if (pos.has_value() && vel.has_value()) {
            std::cerr << i << ": Position = { " << pos.value().x << ", " << pos.value().y << " } , Velocity = { " << vel.value().vx << ", " << vel.value().vy << " }" << std::endl;
        }
    }
    return *this;
}
