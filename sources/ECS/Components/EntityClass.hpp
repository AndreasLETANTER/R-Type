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

enum EntityClasses {
    NUGO,
    ANDREAS,
    ELIOT,
    LOUIS,
    MOB_ORANGE_CRAB,
    MOB_YELLOW_POPCORN
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
        ShootingPattern shootingPattern;

        EntityClass(std::string assetName, std::string projectileAssetName, Component::Position scale, sf::IntRect rect, int health, int damage, int shootingDelay, int speed, ShootingPattern shootingPattern);
    };

    class EntityClassFactory {
    public:
        static EntityClass CreateEntityClass(EntityClasses entityClass);
    };
}
