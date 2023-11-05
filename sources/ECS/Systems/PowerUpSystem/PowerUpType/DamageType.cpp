/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** DamageType
*/

#include "DamageType.hpp"

void DamageType::update(Registry &registry, Component::EntityClass &entityclasses, int stat)
{
    (void) registry;
    if (stat < 0) {
        entityclasses.damage = 0;
        return;
    }
    entityclasses.damage += stat;
}
