/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** SpreadShootingPattern
*/

#pragma once

#include "ECS/Systems/ShootSystem/ShootingPatterns/AShootingPattern.hpp"

/**
 * @brief Class representing a spread shooting pattern.
 */
class SpreadShootingPattern : public AShootingPattern {
    public:
        /**
         * @brief Shoots bullets in a spread pattern.
         *
         * @param registry The registry containing the entity.
         * @param shoot The shoot component of the entity.
         * @param pos The position component of the entity.
         * @param draw The drawable component of the entity.
         */
        void shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, Component::Drawable &draw, unsigned int groupId) override;
};
