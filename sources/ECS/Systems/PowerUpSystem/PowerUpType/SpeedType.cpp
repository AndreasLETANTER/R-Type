/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** SpeedType
*/

#include "SpeedType.hpp"

void SpeedType::update(Registry &registry, Component::EntityClass &entityclasses, int stat)
{
    (void) registry;
    if (stat < 0) {
        entityclasses.speed = 0;
        return;
    }
    entityclasses.speed += stat;
}
