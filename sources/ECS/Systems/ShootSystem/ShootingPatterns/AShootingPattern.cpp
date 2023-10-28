/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AShootingPattern
*/

#include "AShootingPattern.hpp"

void AShootingPattern::createProjectile(Registry &registry, Component::Drawable &draw, std::string bulletSpriteName, Component::Position initialPos, Component::Position endPos, size_t damage, int playerId)
{
    auto window = draw.window;
    auto projectile = registry.spawn_entity();
    auto &projectileDraw = registry.add_component<Component::Drawable>(projectile, Component::Drawable(bulletSpriteName, window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), registry.get_assets().get_texture(bulletSpriteName)));

    registry.add_component<Component::Position>(projectile, Component::Position(initialPos.x, initialPos.y));
    registry.add_component<Component::Velocity>(projectile, Component::Velocity(0, 0, 5));
    registry.add_component<Component::Projectile>(projectile, Component::Projectile(initialPos, endPos, 10, damage, playerId));
    registry.add_component<Component::Collision>(projectile, Component::Collision(projectileDraw.value().sprite.getTextureRect().height, projectileDraw.value().sprite.getTextureRect().width));
}
