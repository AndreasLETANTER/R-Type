/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AttackSpeedType
*/

#pragma once

#include "ECS/Systems/PowerUpSystem/PowerUpType/APowerUpType.hpp"

/**
 * @class AttackSpeedType
 * AttackSpeedType is a subclass of APowerUpType that represents a power-up that increases the attack speed of an entity.
 */
class AttackSpeedType : public APowerUpType {
    public:
        /**
         * Destructor for AttackSpeedType.
         */
        ~AttackSpeedType() = default;

        /**
         * Updates the entity's attack speed stat when the power-up is applied.
         * @param registry The registry containing the entity's components.
         * @param entityclasses The entity's class components.
         * @param stat The current value of the entity's attack speed stat.
         */
        void update(Registry &registry, Component::EntityClass &entityclasses, int stat) override;
    protected:
    private:
};
