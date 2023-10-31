/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** HealthType
*/

#pragma once

#include "ECS/Systems/PowerUpSystem/PowerUpType/APowerUpType.hpp"

class HealthType : public APowerUpType {
    public:
        ~HealthType() = default;
        void update(Registry &registry, Component::EntityClass &entityclasses, int stat) override;
    protected:
    private:
};
