/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AMovePattern
*/

#pragma once
#include <memory>
#include <optional>
#include <cmath>
#include "ECS/Components/Position.hpp"
#include "ECS/Components/AutoMove.hpp"

class AMovePattern {
    public:
        double getDistancetoTravel(std::optional<Component::Position> start, std::optional<Component::Position> end);
    protected:
    private:
};
