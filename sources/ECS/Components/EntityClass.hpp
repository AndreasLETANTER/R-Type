/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** EntityClass
*/

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "ECS/Components/Shoot.hpp"
#include "ECS/Components/PowerUp.hpp"

enum EntityClasses {
    NUGO,
    ANDREAS,
    ELIOT,
    LOUIS,
    MOB_ORANGE_CRAB,
    MOB_YELLOW_POPCORN,
    SPEED_POWERUP,
    HEALTH_POWERUP,
    DAMAGE_POWERUP,
    SHOOTING_SPEED_POWERUP
};

extern std::map<std::string, EntityClasses> entityClassesMap;

namespace Component {
    class EntityClass {
    public:
        std::string assetName;
        std::string projectileAssetName;
        Component::Position scale;
        sf::IntRect rect;
        int health;
        int damage;
        int shootingDelay;
        int speed;
        sf::Time delayForDispawn;
        int stat;
        ShootingPattern shootingPattern;
        PowerUpType powerUpType;

        EntityClass(std::string assetName, std::string projectileAssetName, Component::Position scale, sf::IntRect rect, int health, int damage, int shootingDelay, int speed, ShootingPattern shootingPattern);
        EntityClass(std::string assetName, Component::Position scale, sf::IntRect rect, PowerUpType powerUpType, sf::Time delayForDispawn, int stat);
    };

    class EntityClassFactory {
    public:
        static EntityClass CreateEntityClass(EntityClasses entityClass);
    };
}
