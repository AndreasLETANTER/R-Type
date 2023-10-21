/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** SpreadShootingPattern
*/

#include "SpreadShootingPattern.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Projectile.hpp"
#include "ECS/Components/Collision.hpp"

void SpreadShootingPattern::shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, Component::Drawable &draw)
{
    sf::Time elapsedTime = shoot.clock->getElapsedTime() - shoot.lastShot;
    if (shoot.canShoot == true && (shoot.keyPressed == sf::Keyboard::Space || shoot.direction == -1) && elapsedTime >= shoot.shootDelay) {
        auto window = draw.window;
        double x = pos.x;
        double y = pos.y;

        auto projectileLeft = registry.spawn_entity();
        auto &projectileDrawLeft = registry.add_component<Component::Drawable>(projectileLeft, Component::Drawable(shoot.bulletSpriteName, window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), registry.get_assets().get_texture(shoot.bulletSpriteName)));
        registry.add_component<Component::Position>(projectileLeft, Component::Position(x - projectileDrawLeft.value().sprite.getTextureRect().width - 1, y));
        registry.add_component<Component::Velocity>(projectileLeft, Component::Velocity(0, 0));
        registry.add_component<Component::Projectile>(projectileLeft, Component::Projectile(Component::Position(x - projectileDrawLeft.value().sprite.getTextureRect().width - 1, y), Component::Position(0, y), 10, shoot.damage));
        registry.add_component<Component::Collision>(projectileLeft, Component::Collision(projectileDrawLeft.value().sprite.getTextureRect().height, projectileDrawLeft.value().sprite.getTextureRect().width));

        auto projectileTop = registry.spawn_entity();
        auto &projectileDrawTop = registry.add_component<Component::Drawable>(projectileTop, Component::Drawable(shoot.bulletSpriteName, window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), registry.get_assets().get_texture(shoot.bulletSpriteName)));
        registry.add_component<Component::Position>(projectileTop, Component::Position(x, y - projectileDrawTop.value().sprite.getTextureRect().height - 1));
        registry.add_component<Component::Velocity>(projectileTop, Component::Velocity(0, 0));
        registry.add_component<Component::Projectile>(projectileTop, Component::Projectile(Component::Position(x, y - projectileDrawTop.value().sprite.getTextureRect().height - 1), Component::Position(x, 0), 10, shoot.damage));
        registry.add_component<Component::Collision>(projectileTop, Component::Collision(projectileDrawTop.value().sprite.getTextureRect().height, projectileDrawTop.value().sprite.getTextureRect().width));

        auto projectileRight = registry.spawn_entity();
        auto &projectileDrawRight = registry.add_component<Component::Drawable>(projectileRight, Component::Drawable(shoot.bulletSpriteName, window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), registry.get_assets().get_texture(shoot.bulletSpriteName)));
        registry.add_component<Component::Position>(projectileRight, Component::Position(x + projectileDrawRight.value().sprite.getTextureRect().width + 15, y));
        registry.add_component<Component::Velocity>(projectileRight, Component::Velocity(0, 0));
        registry.add_component<Component::Projectile>(projectileRight, Component::Projectile(Component::Position(x + projectileDrawRight.value().sprite.getTextureRect().width + 1, y), Component::Position(1920, y), 10, shoot.damage));
        registry.add_component<Component::Collision>(projectileRight, Component::Collision(projectileDrawRight.value().sprite.getTextureRect().height, projectileDrawRight.value().sprite.getTextureRect().width));

        auto projectileBottom = registry.spawn_entity();
        auto &projectileDrawBottom = registry.add_component<Component::Drawable>(projectileBottom, Component::Drawable(shoot.bulletSpriteName, window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), registry.get_assets().get_texture(shoot.bulletSpriteName)));
        registry.add_component<Component::Position>(projectileBottom, Component::Position(x, y + projectileDrawBottom.value().sprite.getTextureRect().height + 1));
        registry.add_component<Component::Velocity>(projectileBottom, Component::Velocity(0, 0));
        registry.add_component<Component::Projectile>(projectileBottom, Component::Projectile(Component::Position(x, y + projectileDrawBottom.value().sprite.getTextureRect().height + 1), Component::Position(x, 1080), 10, shoot.damage));
        registry.add_component<Component::Collision>(projectileBottom, Component::Collision(projectileDrawBottom.value().sprite.getTextureRect().height, projectileDrawBottom.value().sprite.getTextureRect().width));

        shoot.lastShot = shoot.clock->getElapsedTime();
    }
}

