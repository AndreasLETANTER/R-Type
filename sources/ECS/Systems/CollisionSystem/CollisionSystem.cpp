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

        for (size_t j = 0; j < positions.size() && j < collisions.size(); j++) {
            auto &pos2 = positions[j];
            auto &col2 = collisions[j];
            sf::IntRect rect2(pos2.value().x, pos2.value().y, pos2.value().x + col2.value().width, pos2.value().y + col2.value().height);

            if (i != j && col.has_value() && col2.has_value() && rect1.intersects(rect2)) {
                std::cout << "Collision detected" << std::endl;
            }
        }
    }
    return *this;
}