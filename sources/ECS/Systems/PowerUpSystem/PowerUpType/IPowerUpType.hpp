/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** IPowerUpType
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/EntityClass.hpp"

class IPowerUpType {
    public:
        virtual void update(Registry &registry, Component::EntityClass &entityclasses, int stat) = 0;
        virtual ~IPowerUpType() = default;

    protected:
    private:
};
