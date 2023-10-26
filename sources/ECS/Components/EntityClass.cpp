/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** EntityClass
*/

#include "EntityClass.hpp"

namespace Component {
    EntityClass::EntityClass(std::string assetName, std::string projectileAssetName, Component::Position scale, sf::IntRect rect, int health, int damage, int shootingDelay, int speed, ShootingPattern shootingPattern)
        : assetName(std::move(assetName)),
            projectileAssetName(std::move(projectileAssetName)),
            scale(scale),
            rect(rect),
            health(health),
            damage(damage),
            shootingDelay(shootingDelay),
            speed(speed),
            shootingPattern(shootingPattern) {}

    EntityClass EntityClassFactory::CreateEntityClass(EntityClasses entityClass) {
        switch (entityClass) {
            case EntityClasses::NUGO:
                return EntityClass("SpaceShips.gif", "BulletSprite.png", Component::Position(102, 57), sf::IntRect(0, 2, 34, 16), 100, 5, 500, 5, ShootingPattern::LINEAR);
            case EntityClasses::ANDREAS:
                return EntityClass("SpaceShips.gif", "BulletSprite.png", Component::Position(102, 57), sf::IntRect(0, 19, 34, 16), 100, 5, 500, 5, ShootingPattern::LINEAR);
            case EntityClasses::ELIOT:
                return EntityClass("SpaceShips.gif", "BulletSprite.png", Component::Position(102, 57), sf::IntRect(0, 36, 34, 16), 100, 5, 500, 5, ShootingPattern::LINEAR);
            case EntityClasses::LOUIS:
                return EntityClass("SpaceShips.gif", "BulletSprite.png", Component::Position(102, 57), sf::IntRect(0, 53, 34, 16), 100, 5, 500, 5, ShootingPattern::LINEAR);
            case EntityClasses::MOB_ORANGE_CRAB:
                return EntityClass("OrangeCrabEnemy.gif", "BulletSpriteMonster.png", Component::Position(99, 87), sf::IntRect(0, 1, 33, 29), 10, 25, 3000, 5, ShootingPattern::SPREAD);
            case EntityClasses::MOB_YELLOW_POPCORN:
                return EntityClass("YellowPopcornEnemy.gif", "BulletSpriteMonster.png", Component::Position(99, 87), sf::IntRect(0, 1, 33, 29), 10, 25, 3000, 5, ShootingPattern::CIRCULAR);
            default:
                return EntityClass("SpaceShips.gif", "BulletSprite.png", Component::Position(102, 57), sf::IntRect(0, 2, 34, 16), 100, 5, 500, 5, ShootingPattern::LINEAR);
        }
    }
}
