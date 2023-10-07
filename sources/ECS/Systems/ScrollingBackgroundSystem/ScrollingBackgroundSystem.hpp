/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ScrollingBackgroundSystem
*/

#pragma once

#include "../../RegistryClass/Registry.hpp"
#include "../../Components/ScrollingBackground.hpp"

/**
 * @class ScrollingBackgroundSystem
 * @brief Class representing the system for scrolling background.
 */
class ScrollingBackgroundSystem {
    public:
        /**
         * @brief Default constructor for ScrollingBackgroundSystem.
         */
        ScrollingBackgroundSystem() = default;

        /**
         * @brief Default destructor for ScrollingBackgroundSystem.
         */
        ~ScrollingBackgroundSystem() = default;

        /**
         * @brief Overloaded function call operator for ScrollingBackgroundSystem.
         * @param registry The registry object.
         * @param positions The positions of the object.
         * @param scrollingBackgrounds The sparse array of scrolling background components.
         * @return ScrollingBackgroundSystem object.
         */
        ScrollingBackgroundSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::ScrollingBackground> &scrollingBackgrounds);
};
