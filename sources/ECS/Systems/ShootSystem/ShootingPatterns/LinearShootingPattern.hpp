/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** LinearShootingPattern
*/

#pragma once

#include "ECS/Systems/ShootSystem/ShootingPatterns/AShootingPattern.hpp"

/**
 * @brief Class representing a linear shooting pattern.
 */
class LinearShootingPattern : public AShootingPattern {
    public:
        /**
         * @brief Shoots bullets in a linear pattern.
         *
         * @param registry The registry containing the entity.
         * @param shoot The shoot component of the entity.
         * @param pos The position component of the entity.
         * @param draw The drawable component of the entity.
         */
        void shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, Component::Drawable &draw, unsigned int groupId) override;
};
