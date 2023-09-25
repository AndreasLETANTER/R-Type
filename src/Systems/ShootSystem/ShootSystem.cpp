/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** ShootSystem
*/

#include "ShootSystem.hpp"

ShootSystem ShootSystem::operator()(Registry &registry, SparseArray<Component::Shoot> &shoots, SparseArray<Component::Position> &positions, SparseArray<Component::Drawable> &drawable)
{
    for (size_t i = 0; i < shoots.size() && i < positions.size() && i < drawable.size(); i++)
    {
        auto &shoot = shoots[i];
        auto &pos = positions[i];
        auto &draw = drawable[i];

        if (shoot.has_value() && pos.has_value() && draw.has_value()) {
            sf::Time elapsedTime = shoot.value().clock->getElapsedTime() - shoot.value().lastShot;
            if (shoot.value().canShoot == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && elapsedTime >= shoot.value().shootDelay) {
                auto projectile = registry.spawn_entity();
                double x = pos.value().x;
                double y = pos.value().y;

                shoot.value().lastShot = shoot.value().clock->getElapsedTime();
                registry.add_component<Component::Position>(projectile, Component::Position(x, y));
                registry.add_component<Component::Velocity>(projectile, Component::Velocity(0, 0));
                registry.add_component<Component::Projectile>(projectile, Component::Projectile(Component::Position(draw.value().window->getSize().x, y), 10));
                registry.add_component<Component::Drawable>(projectile, Component::Drawable(draw.value().sprite, draw.value().window));
            }
        }
    }
    return *this;
}