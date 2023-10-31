/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** APowerUpType
*/

#pragma once

#include "IPowerUpType.hpp"

class APowerUpType : public IPowerUpType {
    public:
        virtual void update(Registry &registry, Component::EntityClass &entityclasses, int stat) = 0;
        virtual ~APowerUpType() = default;

    protected:
    private:
};
