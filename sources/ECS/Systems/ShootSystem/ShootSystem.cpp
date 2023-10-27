/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ShootSystem
*/

#include "ECS/Systems/ShootSystem/ShootSystem.hpp"
#include "ECS/Systems/ShootSystem/ShootingPatterns/ShootingPatternFactory.hpp"

ShootSystem ShootSystem::operator()(Registry &registry, SparseArray<Component::Shoot> &shoots, SparseArray<Component::Position> &positions, SparseArray<Component::Drawable> &drawable, SparseArray<Component::Group> &groups)
{
    for (size_t i = 0; i < shoots.size() && i < positions.size() && i < drawable.size(); i++) {
        auto &shoot = shoots[i];
        auto &pos = positions[i];
        auto &draw = drawable[i];
        auto &group = groups[i];

        if (shoot.has_value() && pos.has_value() && draw.has_value() && group.has_value()) {
            auto shootingPattern = ShootingPatternFactory::createShootingPattern(shoot.value().pattern);
            shootingPattern->shoot(registry, shoot.value(), pos.value(), draw.value(), group.value().groupId);
        }
    }
    return *this;
}
