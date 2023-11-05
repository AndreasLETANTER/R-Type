/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** APowerUpType
*/

#pragma once

#include "IPowerUpType.hpp"

/**
 * @brief Abstract class representing a power-up type.
 */
class APowerUpType : public IPowerUpType {
    public:
        /**
         * @brief Update the power-up type.
         *
         * @param registry The ECS registry.
         * @param entityclasses The entity classes.
         * @param stat The power-up stat.
         */
        virtual void update(Registry &registry, Component::EntityClass &entityclasses, int stat) = 0;

        /**
         * @brief Destroy the APowerUpType object.
         */
        virtual ~APowerUpType() = default;
};
