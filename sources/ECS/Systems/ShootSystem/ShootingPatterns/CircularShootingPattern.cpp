/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** CircularShootingPattern
*/

#include "CircularShootingPattern.hpp"

void CircularShootingPattern::shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, sf::RenderWindow *window, unsigned int groupId)
{
    sf::Time elapsedTime = shoot.clock->getElapsedTime() - shoot.lastShot;
    if (shoot.canShoot == true && (shoot.m_keyMapState[sf::Keyboard::Space] == true || shoot.direction == -1) && elapsedTime >= shoot.shootDelay) {
        double x = pos.x;
        auto texture = registry.get_assets().get_texture(shoot.bulletSpriteName);
        auto sprite = sf::Sprite(*texture);
        double y = pos.y;

        createProjectile(registry, window, shoot.bulletSpriteName, Component::Position(x - sprite.getTextureRect().width - 1, y - sprite.getTextureRect().height - 1), Component::Position(0, 0), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, window, shoot.bulletSpriteName, Component::Position(x, y - sprite.getTextureRect().height - 1), Component::Position(x, 0), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, window, shoot.bulletSpriteName, Component::Position(x + sprite.getTextureRect().width + 15, y - sprite.getTextureRect().height - 1), Component::Position(1920, 0), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, window, shoot.bulletSpriteName, Component::Position(x + sprite.getTextureRect().width + 15, y + sprite.getTextureRect().height + 1), Component::Position(1920, 1080), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, window, shoot.bulletSpriteName, Component::Position(x, y + sprite.getTextureRect().height + 1), Component::Position(x, 1080), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, window, shoot.bulletSpriteName, Component::Position(x - sprite.getTextureRect().width - 1, y + sprite.getTextureRect().height + 1), Component::Position(0, 1080), shoot.damage, shoot.playerId, groupId);
        shoot.lastShot = shoot.clock->getElapsedTime();
    }
}
