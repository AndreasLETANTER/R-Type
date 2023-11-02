/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** CircularShootingPattern
*/

#pragma once

#include "ECS/Systems/ShootSystem/ShootingPatterns/AShootingPattern.hpp"

/**
 * @brief Class representing a circular shooting pattern.
 */
class CircularShootingPattern : public AShootingPattern {
    public:
        /**
         * @brief Shoots bullets in a circular pattern.
         *
         * @param registry The registry containing the entity.
         * @param shoot The shoot component of the entity.
         * @param pos The position component of the entity.
         * @param window The render window to draw the object on.
         */
        void shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, sf::RenderWindow *window, unsigned int groupId) override;
};
