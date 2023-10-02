/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** DrawSystem
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Drawable.hpp"

/**
 * @brief The DrawSystem class is responsible for rendering all the entities that have a drawable component and a position component.
 */
class DrawSystem {
    public:
        DrawSystem() = default;
        ~DrawSystem() = default;
        DrawSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Drawable> &drawables);
};
