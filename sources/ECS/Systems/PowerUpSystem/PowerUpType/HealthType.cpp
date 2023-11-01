/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** HealthType
*/

#include "HealthType.hpp"

void HealthType::update(Registry &registry, Component::EntityClass &entityclasses, int stat)
{
    (void) registry;
    if (stat < 0) {
        entityclasses.healthBoost = 0;
        return;
    }
    entityclasses.healthBoost += stat;
}
