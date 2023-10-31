/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AttackSpeedType
*/

#include "AttackSpeedType.hpp"

void AttackSpeedType::update(Registry &registry, Component::EntityClass &entityclasses, int stat)
{
    (void) registry;
    if (stat > entityclasses.shootingDelay) {
        entityclasses.shootingDelay = 0;
        return;
    }
    entityclasses.shootingDelay += stat;
}
