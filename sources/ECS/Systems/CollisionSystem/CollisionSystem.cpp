/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** CollisionSystem
*/

#include "ECS/Systems/CollisionSystem/CollisionSystem.hpp"

CollisionSystem CollisionSystem::operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Collision> &collisions)
{
    (void)registry;
    for (size_t i = 0; i < positions.size() && i < collisions.size(); i++) {
        auto &pos = positions[i];
        auto &col = collisions[i];

        if (!(pos.has_value() && col.has_value())) {
            continue;
        }
        sf::IntRect rect1(pos.value().x, pos.value().y, col.value().width, col.value().height);
        col.value().entities_in_collision.clear();
        for (size_t j = 0; j < positions.size() && j < collisions.size(); j++) {
            auto &pos2 = positions[j];
            auto &col2 = collisions[j];

            if (!(pos2.has_value() && col2.has_value())) {
                continue;
            }
            sf::IntRect rect2(pos2.value().x, pos2.value().y, col2.value().width, col2.value().height);

            if (i != j && col.has_value() && col2.has_value() && rect1.intersects(rect2)) {
                if (std::count(col.value().entities_in_collision.begin(), col.value().entities_in_collision.end(), registry.entity_from_index(j)) > 0)
                    continue;
                col.value().entities_in_collision.push_back(registry.entity_from_index(j));
            }
        }
    }
    return *this;
}
