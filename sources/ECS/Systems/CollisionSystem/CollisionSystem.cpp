/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** CollisionSystem
*/

#include "CollisionSystem.hpp"

CollisionSystem CollisionSystem::operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Collision> &collisions)
{
    (void)registry;
    for (size_t i = 0; i < positions.size() && i < collisions.size(); i++) {
        auto &pos = positions[i];
        auto &col = collisions[i];
        sf::IntRect rect1(pos.value().x, pos.value().y, pos.value().x + col.value().width, pos.value().y + col.value().height);

        for (size_t j = i; j < positions.size() && j < collisions.size(); j++) {
            auto &pos2 = positions[j];
            auto &col2 = collisions[j];
            sf::IntRect rect2(pos2.value().x, pos2.value().y, col2.value().width, col2.value().height);

            if (i != j && col.has_value() && col2.has_value() && rect1.intersects(rect2)) {
                if (std::find(col.value().entities_in_collision.begin(), col.value().entities_in_collision.end(), registry.entity_from_index(j)) != col.value().entities_in_collision.end())
                    break;
                col.value().entities_in_collision.push_back(registry.entity_from_index(j));
                col2.value().entities_in_collision.push_back(registry.entity_from_index(i));
                break;
            }
        }
    }
    return *this;
}