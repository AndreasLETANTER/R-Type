/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** LinerShootingPattern
*/

#include "LinearShootingPattern.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Projectile.hpp"
#include "ECS/Components/Collision.hpp"

void LinearShootingPattern::shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, Component::Drawable &draw, unsigned int groupId)
{
    sf::Time elapsedTime = shoot.clock->getElapsedTime() - shoot.lastShot;
    if (shoot.canShoot == true && (shoot.m_keyMapState[sf::Keyboard::Space] == true || shoot.direction == -1) && elapsedTime >= shoot.shootDelay) {
        double x = pos.x;
        auto texture = registry.get_assets().get_texture(shoot.bulletSpriteName);
        auto sprite = sf::Sprite(*texture);
        double y = pos.y + ((draw.scale.y / 2) - (texture->getSize().y / 2));

        createProjectile(registry, draw, shoot.bulletSpriteName, Component::Position(x + (sprite.getTextureRect().width + 1) * shoot.direction, y), Component::Position(shoot.offsetLimit * shoot.direction, y), shoot.damage, shoot.playerId, groupId);
        shoot.lastShot = shoot.clock->getElapsedTime();
    }
}
