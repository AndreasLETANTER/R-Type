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

void LinearShootingPattern::shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, Component::Drawable &draw)
{
    sf::Time elapsedTime = shoot.clock->getElapsedTime() - shoot.lastShot;
    if (shoot.canShoot == true && (shoot.m_keyMapState[sf::Keyboard::Space] == true || shoot.direction == -1) && elapsedTime >= shoot.shootDelay) {
        auto projectile = registry.spawn_entity();
        double x = pos.x;
        double y = pos.y;
        auto window = draw.window;

        shoot.lastShot = shoot.clock->getElapsedTime();
        auto &projectileDraw = registry.add_component<Component::Drawable>(projectile, Component::Drawable(shoot.bulletSpriteName, window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), registry.get_assets().get_texture(shoot.bulletSpriteName)));
        registry.add_component<Component::Position>(projectile, Component::Position(x + projectileDraw.value().sprite.getTextureRect().width + 1, y));
        registry.add_component<Component::Velocity>(projectile, Component::Velocity(0, 0));
        registry.add_component<Component::Position>(projectile, Component::Position((x + (projectileDraw.value().sprite.getTextureRect().width + 1) * shoot.direction), y));
        registry.add_component<Component::Projectile>(projectile, Component::Projectile(Component::Position((x + (projectileDraw.value().sprite.getTextureRect().width + 1) * shoot.direction), y), Component::Position(shoot.offsetLimit * shoot.direction, y), 10, shoot.damage));
        registry.add_component<Component::Collision>(projectile, Component::Collision(projectileDraw.value().sprite.getTextureRect().height, projectileDraw.value().sprite.getTextureRect().width));
    }
}
