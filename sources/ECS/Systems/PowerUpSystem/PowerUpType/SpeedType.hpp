/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** SpeedType
*/

#pragma once

#include "ECS/Systems/PowerUpSystem/PowerUpType/APowerUpType.hpp"

/**
 * @brief The SpeedType class is a subclass of APowerUpType that represents a power-up that increases the speed of the entity.
 */
class SpeedType : public APowerUpType {
    public:
        ~SpeedType() = default;

        /**
         * @brief Updates the speed of the entity by a given amount.
         *
         * @param registry The registry containing the entity.
         * @param entityclasses The entity class component of the entity.
         * @param stat The amount to increase the speed by.
         */
        void update(Registry &registry, Component::EntityClass &entityclasses, int stat) override;
};
