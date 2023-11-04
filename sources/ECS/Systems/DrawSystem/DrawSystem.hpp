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

        /**
         * @brief Draws all entities with a Position and Drawable component.
         *
         * @param registry The ECS registry containing all entities and components.
         * @param positions The SparseArray containing all Position components.
         * @param drawables The SparseArray containing all Drawable components.
         * @return DrawSystem The updated DrawSystem.
         */
        DrawSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Drawable> &drawables);
};
