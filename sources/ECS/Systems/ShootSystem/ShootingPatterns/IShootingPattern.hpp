/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** IShootingPattern
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Shoot.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Drawable.hpp"

namespace Component {
    class Shoot;
    class Position;
    class Drawable;
}

/**
 * @brief The IShootingPattern class is an interface for the shooting patterns.
 */
class IShootingPattern {
    public:
        /**
         * @brief shoot is a pure virtual function that will be implemented in the shooting patterns.
         *
         * @param registry The entity registry.
         * @param shoot The shoot component.
         * @param pos The position component.
         * @param window The render window to draw the object on.
         * @param groupId The group id of the shooter.
         */
        virtual void shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, sf::RenderWindow *window, unsigned int groupId) = 0;

        /**
         * @brief Destroy the IShootingPattern object.
         */
        virtual ~IShootingPattern() = default;
};
