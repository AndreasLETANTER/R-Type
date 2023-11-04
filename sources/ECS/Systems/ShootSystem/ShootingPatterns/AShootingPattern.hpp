/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AShootingPattern
*/

#pragma once

#include "ECS/Systems/ShootSystem/ShootingPatterns/IShootingPattern.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Projectile.hpp"
#include "ECS/Components/Collision.hpp"
#include "ECS/Components/Group.hpp"

namespace Component {
    class Shoot;
    class Position;
    class Drawable;
    class Velocity;
    class Projectile;
    class Collision;
}

/**
 * @brief Abstract class representing a shooting pattern.
 */
class AShootingPattern : public IShootingPattern {
    public:
        virtual ~AShootingPattern() = default;

        /**
         * @brief Shoots a projectile.
         *
         * @param registry The registry containing the entity.
         * @param shoot The shoot component of the entity.
         * @param pos The position component of the entity.
         * @param window The render window to draw the object on.
         * @param groupId The id of the group.
         */
        virtual void shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, sf::RenderWindow *window, unsigned int groupId) = 0;

        /**
         * @brief Creates a projectile.
         *
         * @param registry The registry containing the entity.
         * @param window The render window to draw the object on.
         * @param bulletSpriteName The name of the bullet sprite.
         * @param initialPos The initial position of the projectile.
         * @param endPos The end position of the projectile.
         * @param damage The damage of the projectile.
         * @param playerId The id of the player.
         * @param groupId The id of the group.
         */
        void createProjectile(Registry &registry, sf::RenderWindow *window, std::string bulletSpriteName, Component::Position initialPos, Component::Position endPos, size_t damage, int playerId, unsigned int groupId);
};
