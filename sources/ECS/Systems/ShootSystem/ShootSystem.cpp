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
    for (size_t i = 0; i < shoots.size() && i < positions.size() && i < drawable.size() && i < groups.size(); i++) {
        auto &shoot = shoots[i];
        auto &pos = positions[i];
        auto &draw = drawable[i];
        auto &group = groups[i];

        if (shoot.has_value() && pos.has_value() && draw.has_value() && group.has_value()) {
            auto shootingPattern = ShootingPatternFactory::createShootingPattern(shoot.value().pattern);
            auto window = draw.value().window;
            auto newpos = Component::Position(pos.value().x, pos.value().y + ((draw.value().scale.y / 2) - (registry.get_assets().get_texture(shoot.value().bulletSpriteName)->getSize().y / 2)));
            shootingPattern->shoot(registry, shoot.value(), newpos, window, group.value().groupId);
        }
    }
    return *this;
}
