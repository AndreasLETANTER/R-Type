/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** IPowerUpType
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/EntityClass.hpp"

/**
 * @brief Interface for power-up types.
 */
class IPowerUpType {
    public:
        /**
         * @brief Update the power-up effect on the given entity.
         * 
         * @param registry The ECS registry.
         * @param entityclasses The entity classes component.
         * @param stat The power-up stat.
         */
        virtual void update(Registry &registry, Component::EntityClass &entityclasses, int stat) = 0;
        virtual ~IPowerUpType() = default;

    protected:
    private:
};
