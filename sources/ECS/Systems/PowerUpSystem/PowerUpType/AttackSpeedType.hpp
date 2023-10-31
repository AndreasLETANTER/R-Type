/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AttackSpeedType
*/

#pragma once

#include "ECS/Systems/PowerUpSystem/PowerUpType/APowerUpType.hpp"

class AttackSpeedType : public APowerUpType {
    public:
        ~AttackSpeedType() = default;
        void update(Registry &registry, Component::EntityClass &entityclasses, int stat) override;
    protected:
    private:
};
