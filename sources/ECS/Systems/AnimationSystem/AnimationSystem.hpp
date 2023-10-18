/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AnimationSystem
*/

#pragma once
#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Animation.hpp"
#include "ECS/Components/Drawable.hpp"

class AnimationSystem {
    public:
        AnimationSystem() = default;
        ~AnimationSystem() = default;
        AnimationSystem operator()(Registry &registry, SparseArray<Component::Animation> &animations, SparseArray<Component::Drawable> &drawables);
};
