/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** DrawSystem
*/

#pragma once

#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Position.hpp"
#include "../../Components/Drawable.hpp"

class DrawSystem {
    public:
        DrawSystem() = default;
        ~DrawSystem() = default;
        DrawSystem operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::Drawable> &drawables);

    protected:
    private:
};
