/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** SpeedType
*/

#pragma once

#include "ECS/Systems/PowerUpSystem/PowerUpType/APowerUpType.hpp"

class SpeedType : public APowerUpType {
    public:
        ~SpeedType() = default;
        void update(Registry &registry, Component::EntityClass &entityclasses, int stat) override;
    protected:
    private:
};
