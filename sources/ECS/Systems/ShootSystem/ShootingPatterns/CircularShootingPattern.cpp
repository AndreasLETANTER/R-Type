/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** CircularShootingPattern
*/

#include "CircularShootingPattern.hpp"

void CircularShootingPattern::shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, Component::Drawable &draw, unsigned int groupId)
{
    sf::Time elapsedTime = shoot.clock->getElapsedTime() - shoot.lastShot;
    if (shoot.canShoot == true && (shoot.m_keyMapState[sf::Keyboard::Space] == true || shoot.direction == -1) && elapsedTime >= shoot.shootDelay) {
        double x = pos.x;
        double y = pos.y;
        auto window = draw.window;
        auto projectile = registry.spawn_entity();
        auto &projectileDraw = registry.add_component<Component::Drawable>(projectile, Component::Drawable(shoot.bulletSpriteName, window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), registry.get_assets().get_texture(shoot.bulletSpriteName)));

        createProjectile(registry, draw, shoot.bulletSpriteName, Component::Position(x - projectileDraw.value().sprite.getTextureRect().width - 1, y), Component::Position(0, y), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, draw, shoot.bulletSpriteName, Component::Position(x - projectileDraw.value().sprite.getTextureRect().width - 1, y - projectileDraw.value().sprite.getTextureRect().height - 1), Component::Position(0, 0), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, draw, shoot.bulletSpriteName, Component::Position(x, y - projectileDraw.value().sprite.getTextureRect().height - 1), Component::Position(x, 0), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, draw, shoot.bulletSpriteName, Component::Position(x + projectileDraw.value().sprite.getTextureRect().width + 15, y - projectileDraw.value().sprite.getTextureRect().height - 1), Component::Position(1920, 0), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, draw, shoot.bulletSpriteName, Component::Position(x + projectileDraw.value().sprite.getTextureRect().width + 15, y), Component::Position(1920, y), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, draw, shoot.bulletSpriteName, Component::Position(x + projectileDraw.value().sprite.getTextureRect().width + 15, y + projectileDraw.value().sprite.getTextureRect().height + 1), Component::Position(1920, 1080), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, draw, shoot.bulletSpriteName, Component::Position(x, y + projectileDraw.value().sprite.getTextureRect().height + 1), Component::Position(x, 1080), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, draw, shoot.bulletSpriteName, Component::Position(x - projectileDraw.value().sprite.getTextureRect().width - 1, y + projectileDraw.value().sprite.getTextureRect().height + 1), Component::Position(0, 1080), shoot.damage, shoot.playerId, groupId);

        shoot.lastShot = shoot.clock->getElapsedTime();
        registry.kill_entity(projectile);
    }
}
