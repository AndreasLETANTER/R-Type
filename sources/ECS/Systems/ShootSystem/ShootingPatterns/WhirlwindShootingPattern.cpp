/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** RandomShootingPattern
*/

#include "WhirlwindShootingPattern.hpp"
#include <math.h>

void WhirlwindShootingPattern::shoot(Registry &registry, Component::Shoot &shoot, Component::Position &pos, sf::RenderWindow *window, unsigned int groupId)
{
    sf::Time elapsedTime = shoot.clock->getElapsedTime() - shoot.lastShot;
    if (shoot.canShoot == true && (shoot.m_keyMapState[sf::Keyboard::Space] == true || shoot.direction == -1) && elapsedTime >= shoot.shootDelay) {
        double x = pos.x;
        auto texture = registry.get_assets().get_texture(shoot.bulletSpriteName);
        auto sprite = sf::Sprite(*texture);
        double y = pos.y;

        int numRings = 4; // Number of rings of projectiles
        int projectilesInRing = 10; // Number of projectiles in each ring
        double ringRadius = 50.0; // Radius of the outermost ring
        double ringSpacing = 30.0; // Spacing between rings

        static int y_direction = 0;
        static int y_direction_offset = 400;

        if (y_direction >= 1920 || y_direction < 0) {
            y_direction_offset = -y_direction_offset;
        }

        for (int i = 0; i < numRings; i++) {
            double ringAngleStep = 360.0 / projectilesInRing;
            for (int j = 0; j < projectilesInRing; j++) {
                double angle = j * ringAngleStep + (i * 10); // Add an offset for spiral effect
                double radians = angle * (3.14 / 180.0);
                double ringRadiusOffset = i * ringSpacing;
                double offsetX = cos(radians) * (ringRadius + ringRadiusOffset);
                double offsetY = sin(radians) * (ringRadius + ringRadiusOffset);

                createProjectile(registry, window, shoot.bulletSpriteName, Component::Position(x + offsetX, y + offsetY), Component::Position(0 + offsetX, y_direction + offsetY), shoot.damage, shoot.playerId, groupId);
            }
        }
        std::cout << y_direction << std::endl;
        y_direction += y_direction_offset;
        shoot.lastShot = shoot.clock->getElapsedTime();
    }
}
