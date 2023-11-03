/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** DrawSystem
*/

#include "ECS/Systems/DrawSystem/DrawSystem.hpp"

DrawSystem DrawSystem::operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Drawable> &drawables)
{
    (void)registry;
    for (size_t i = 0; i < drawables.size() && i < positions.size(); ++i) {
        auto &pos = positions[i];
        auto &dra = drawables[i];
        if (pos.has_value() && dra.has_value() && dra.value().spriteName == "SpaceBackground.png") {
            dra.value().sprite.setPosition(pos.value().x, pos.value().y);
            dra.value().window->draw(dra.value().sprite);
        }
    }
    for (size_t i = 0; i < drawables.size() && i < positions.size(); ++i) {
        auto &pos = positions[i];
        auto &dra = drawables[i];
        if (pos.has_value() && dra.has_value() && dra.value().spriteName != "SpaceBackground.png") {
            dra.value().sprite.setPosition(pos.value().x, pos.value().y);
            dra.value().window->draw(dra.value().sprite);
        }
    }
    return *this;
}
