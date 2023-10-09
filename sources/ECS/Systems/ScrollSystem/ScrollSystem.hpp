/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ScrollSystem
*/

#pragma once

#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Scroll.hpp"

/**
 * @class ScrollSystem
 * @brief Class representing the system for scrolling background.
 */
class ScrollSystem {
    public:
        /**
         * @brief Default constructor for ScrollSystem.
         */
        ScrollSystem() = default;

        /**
         * @brief Default destructor for ScrollSystem.
         */
        ~ScrollSystem() = default;

        /**
         * @brief Overloaded function call operator for ScrollSystem.
         * @param registry The registry object.
         * @param positions The positions of the object.
         * @param Scrolls The sparse array of scrolling background components.
         * @return ScrollSystem object.
         */
        ScrollSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Scroll> &Scrolls);
};
