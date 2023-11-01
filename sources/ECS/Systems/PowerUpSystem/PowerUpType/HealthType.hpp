/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** HealthType
*/

#pragma once

#include "ECS/Systems/PowerUpSystem/PowerUpType/APowerUpType.hpp"

/**
 * @class HealthType
 * @brief A class representing a power-up type that increases the health of an entity.
 */
class HealthType : public APowerUpType {
    public:
        /**
         * @brief Default destructor.
         */
        ~HealthType() = default;
        
        /**
         * @brief Updates the health of the entity with the given stat.
         * @param registry The registry containing the entity.
         * @param entityclasses The entity class component of the entity.
         * @param stat The stat to update the health with.
         */
        void update(Registry &registry, Component::EntityClass &entityclasses, int stat) override;
    protected:
    private:
};
