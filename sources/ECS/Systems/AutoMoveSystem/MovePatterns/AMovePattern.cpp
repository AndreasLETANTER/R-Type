/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AMovePattern
*/

#include "AMovePattern.hpp"

double AMovePattern::getDistancetoTravel(std::optional<Component::Position> pos, std::optional<Component::Position> end)
{
    double dx = end.value().x - pos.value().x;
    double dy = end.value().y - pos.value().y;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}
