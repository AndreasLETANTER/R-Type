/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** WaveShootingPattern
*/

#include "WaveShootingPattern.hpp"

void WaveShootingPattern::shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, sf::RenderWindow *window, unsigned int groupId)
{
    sf::Time elapsedTime = shoot.clock->getElapsedTime() - shoot.lastShot;
    if (shoot.canShoot == true && (shoot.m_keyMapState[sf::Keyboard::Space] == true || shoot.direction == -1) && elapsedTime >= shoot.shootDelay) {
        double x = pos.x;
        auto texture = registry.get_assets().get_texture(shoot.bulletSpriteName);
        auto sprite = sf::Sprite(*texture);
        double y = pos.y + ((draw.scale.y / 2) - (texture->getSize().y / 2));

        createProjectile(registry, window, shoot.bulletSpriteName, Component::Position(x - sprite.getTextureRect().width - 1, y), Component::Position(0, y), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, window, shoot.bulletSpriteName, Component::Position(x - sprite.getTextureRect().width - 1, y - sprite.getTextureRect().height - 10), Component::Position(0, 0), shoot.damage, shoot.playerId, groupId);
        createProjectile(registry, window, shoot.bulletSpriteName, Component::Position(x - sprite.getTextureRect().width - 1, y + sprite.getTextureRect().height + 10), Component::Position(0, 1080), shoot.damage, shoot.playerId, groupId);
        shoot.lastShot = shoot.clock->getElapsedTime();
    }
}
