/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** DamageType
*/

#pragma once

#include "ECS/Systems/PowerUpSystem/PowerUpType/APowerUpType.hpp"

class DamageType : public APowerUpType {
    public:
        ~DamageType() = default;
        void update(Registry &registry, Component::EntityClass &entityclasses, int stat) override;
    protected:
    private:
};
