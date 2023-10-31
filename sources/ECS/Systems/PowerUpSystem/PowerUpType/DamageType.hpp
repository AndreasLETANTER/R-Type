/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** DamageType
*/

#pragma once

#include "ECS/Systems/PowerUpSystem/PowerUpType/APowerUpType.hpp"

/**
 * @class DamageType
 * @brief A class representing a power-up type that increases the damage of the entity.
 */
class DamageType : public APowerUpType {
    public:
        /**
         * @brief Default destructor.
         */
        ~DamageType() = default;
        
        /**
         * @brief Updates the entity's damage stat.
         * @param registry The entity registry.
         * @param entityclasses The entity's class components.
         * @param stat The entity's current damage stat.
         */
        void update(Registry &registry, Component::EntityClass &entityclasses, int stat) override;
    protected:
    private:
};
