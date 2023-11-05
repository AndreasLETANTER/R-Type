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
        /**
         * @brief getDistancetoTravel calculates the distance to travel between the starting point and the target end point of the entity.
         * @param start the starting point
         * @param end the ending point
         * @return the distance to travel
         */
        double getDistancetoTravel(std::optional<Component::Position> start, std::optional<Component::Position> end);
    protected:
    private:
};
