/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** ControlSystem
*/

#pragma once
#include "../../RegistryClass/Registry.hpp"
#include "../../Components/Controllable.hpp"
#include "../../Components/Velocity.hpp"

class ControlSystem {
    public:
        ControlSystem() = default;
        ~ControlSystem() = default;
        ControlSystem operator()(Registry &registry, SparseArray<Component::Controllable> &controllables, SparseArray<Component::Velocity> &velocities);

    protected:
    private:
};
