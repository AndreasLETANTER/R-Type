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
    
    EntityClass::EntityClass(std::string assetName, Component::Position scale, sf::IntRect rect, PowerUpType powerUpType, sf::Time delayForDispawn, int stat)
        : assetName(std::move(assetName)),
            scale(scale),
            rect(rect),
            delayForDispawn(delayForDispawn),
            stat(stat),
            powerUpType(powerUpType) {}

    EntityClass EntityClassFactory::CreateEntityClass(EntityClasses entityClass) {
        switch (entityClass) {
            case EntityClasses::NUGO:
                return EntityClass("SpaceShips.gif", "PBulletNugo.png", Component::Position(102, 57), sf::IntRect(0, 2, 34, 16), 150, 15, 750, 1, ShootingPattern::LINEAR);
            case EntityClasses::ANDREAS:
                return EntityClass("SpaceShips.gif", "PBulletAndreas.png", Component::Position(102, 57), sf::IntRect(0, 19, 34, 16), 50, 5, 300, 7, ShootingPattern::LINEAR);
            case EntityClasses::ELIOT:
                return EntityClass("SpaceShips.gif", "PBulletEliot.png", Component::Position(102, 57), sf::IntRect(0, 36, 34, 16), 100, 10, 500, 5, ShootingPattern::LINEAR);
            case EntityClasses::LOUIS:
                return EntityClass("SpaceShips.gif", "PBulletLouis.png", Component::Position(102, 57), sf::IntRect(0, 53, 34, 16), 75, 10, 500, 3, ShootingPattern::LINEAR);
            case EntityClasses::MOB_ORANGE_CRAB:
                return EntityClass("OrangeCrabEnemy.gif", "EBulletOrangeCrab.png", Component::Position(99, 87), sf::IntRect(0, 1, 33, 29), 30, 5, 2000, 5, ShootingPattern::SPREAD);
            case EntityClasses::MOB_YELLOW_POPCORN:
                return EntityClass("YellowPopcornEnemy.gif", "EBulletYellowPopcorn.png", Component::Position(99, 87), sf::IntRect(0, 1, 33, 29), 10, 3, 1000, 7, ShootingPattern::CIRCULAR);
            case EntityClasses::MOB_GREEN_PLANT:
                return EntityClass("GreenPlantEnemy.gif", "EBulletGreenPlant.png", Component::Position(112, 112), sf::IntRect(0, 1, 66, 66), 50, 15, 3000, 3, ShootingPattern::WAVE);
            case EntityClasses::MOB_BLUE_D:
                return EntityClass("BlueDEnemy.gif", "EBulletBlueD.png", Component::Position(102, 105), sf::IntRect(0, 1, 34, 35), 20, 5, 1000, 5, ShootingPattern::LINEAR);
            case EntityClasses::FIRST_BOSS:
                return EntityClass("FirstBoss.gif", "EBulletYellowPopcorn.png", Component::Position(380, 748), sf::IntRect(0, 0, 145, 262), 300, 30, 1000, 3, ShootingPattern::WHIRLWIND);
            case EntityClasses::SPEED_POWERUP:
                return EntityClass("PowerUpSpeed.png", Component::Position(50, 50), sf::IntRect(0, 0, 368, 368), PowerUpType::Speed, sf::Time(sf::seconds(5)), 1);
            case EntityClasses::HEALTH_POWERUP:
                return EntityClass("PowerUpHealth.png", Component::Position(50, 50), sf::IntRect(0, 0, 368, 368), PowerUpType::Health, sf::Time(sf::seconds(5)), 20);
            case EntityClasses::DAMAGE_POWERUP:
                return EntityClass("PowerUpDamage.png", Component::Position(50, 50), sf::IntRect(0, 0, 368, 368), PowerUpType::Damage, sf::Time(sf::seconds(5)), 2);
            case EntityClasses::SHOOTING_SPEED_POWERUP:
                return EntityClass("PowerUpAttackSpeed.png", Component::Position(50, 50), sf::IntRect(0, 0, 368, 368), PowerUpType::AttackSpeed, sf::Time(sf::seconds(5)), 3);
            default:
                return EntityClass("SpaceShips.gif", "PBulletNugo.png", Component::Position(102, 57), sf::IntRect(0, 2, 34, 16), 100, 5, 500, 5, ShootingPattern::LINEAR);
        }
    }
}
