/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ShootSystem
*/

#include "ECS/Systems/ShootSystem/ShootSystem.hpp"

ShootSystem ShootSystem::operator()(Registry &registry, SparseArray<Component::Shoot> &shoots, SparseArray<Component::Position> &positions, SparseArray<Component::Drawable> &drawable)
{
    for (size_t i = 0; i < shoots.size() && i < positions.size() && i < drawable.size(); i++) {
        auto &shoot = shoots[i];
        auto &pos = positions[i];
        auto &draw = drawable[i];

        if (shoot.has_value() && pos.has_value() && draw.has_value()) {
            sf::Time elapsedTime = shoot.value().clock->getElapsedTime() - shoot.value().lastShot;
            if (shoot.value().canShoot == true && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || shoot.value().isMonster) && elapsedTime >= shoot.value().shootDelay) {
                auto projectile = registry.spawn_entity();
                double x = pos.value().x;
                double y = pos.value().y;
                auto window = draw.value().window;

                shoot.value().lastShot = shoot.value().clock->getElapsedTime();
                auto &projectileDraw = registry.add_component<Component::Drawable>(projectile, Component::Drawable(shoot.value().bulletSpriteName, window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), registry.get_assets().get_texture(shoot.value().bulletSpriteName)));
                registry.add_component<Component::Position>(projectile, Component::Position(x + projectileDraw.value().sprite.getTextureRect().width + 1, y));
                registry.add_component<Component::Velocity>(projectile, Component::Velocity(0, 0));
                if (shoot.value().isMonster) {
                    registry.add_component<Component::Position>(projectile, Component::Position(x - (projectileDraw.value().sprite.getTextureRect().width + 1), y));
                    registry.add_component<Component::Projectile>(projectile, Component::Projectile(Component::Position(x - (projectileDraw.value().sprite.getTextureRect().width + 1), y), Component::Position(0, y), 10, shoot.value().damage));
                } else {
                    registry.add_component<Component::Position>(projectile, Component::Position(x + projectileDraw.value().sprite.getTextureRect().width + 1, y));
                    registry.add_component<Component::Projectile>(projectile, Component::Projectile(Component::Position(x - (projectileDraw.value().sprite.getTextureRect().width + 1), y), Component::Position(window->getSize().x, y), 10, shoot.value().damage));
                }
                registry.add_component<Component::Collision>(projectile, Component::Collision(projectileDraw.value().sprite.getTextureRect().height, projectileDraw.value().sprite.getTextureRect().width));
            }
        }
    }
    return *this;
}
