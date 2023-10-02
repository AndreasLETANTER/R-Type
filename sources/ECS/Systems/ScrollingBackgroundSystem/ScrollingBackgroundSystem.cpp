/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ScrollingBackgroundSystem
*/

#include "ScrollingBackgroundSystem.hpp"

ScrollingBackgroundSystem ScrollingBackgroundSystem::operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::ScrollingBackground> &scrollingBackgrounds)
{
    (void) registry;
    for (size_t i = 0; i < positions.size() && i < scrollingBackgrounds.size(); i++) {
        auto &sb = scrollingBackgrounds[i];
        auto &pos = positions[i];
        if (sb.has_value() && pos.has_value()) {
            pos.value().x -= 0.5;
            if (pos.value().x <= sb.value().offsetLimit.x) {
                std::cout << "pos.value().x: " << pos.value().x << std::endl;
                std::cout << "sb.value().offsetLimit.x: " << sb.value().offsetLimit.x << std::endl;
                pos.value().x = sb.value().startingPos.x + (pos.value().x - sb.value().offsetLimit.x);
            }
        }
    }
    return *this;
}
