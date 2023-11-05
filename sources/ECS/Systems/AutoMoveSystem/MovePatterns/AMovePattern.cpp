/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AMovePattern
*/

#include "AMovePattern.hpp"

double AMovePattern::getDistancetoTravel(std::optional<Component::Position> startPos, std::optional<Component::Position> endPos)
{
    double dx = endPos.value().x - startPos.value().x;
    double dy = endPos.value().y - startPos.value().y;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}
