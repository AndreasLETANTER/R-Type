/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ScrollSystem
*/

#include "ScrollSystem.hpp"

ScrollSystem ScrollSystem::operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Scroll> &scrolls)
{
    (void) registry;
    for (size_t i = 0; i < positions.size() && i < scrolls.size(); i++) {
        auto &sb = scrolls[i];
        auto &pos = positions[i];
        if (sb.has_value() && pos.has_value()) {
            if (pos.value().x == sb.value().pausePosX && sb.value().pausePosX != 0) {
                pos.value().x = sb.value().pausePosX;
            } else if (pos.value().x <= sb.value().offsetLimit.x) {
                pos.value().x = sb.value().startingPos.x + (pos.value().x - sb.value().offsetLimit.x);
            } else
                pos.value().x -= 0.5;
        }
    }
    return *this;
}
