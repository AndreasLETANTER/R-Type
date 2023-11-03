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
    FIRST_BOSS,
    SPEED_POWERUP,
    HEALTH_POWERUP,
    DAMAGE_POWERUP,
    SHOOTING_SPEED_POWERUP
};

extern std::map<std::string, EntityClasses> entityClassesMap;

namespace Component {
    /**
     * @brief The EntityClass class represents the characteristics of an entity in the game.
     */
    class EntityClass {
    public:
        std::string assetName; /**< The name of the asset used for the entity. */
        std::string projectileAssetName; /**< The name of the asset used for the entity's projectile. */
        Component::Position scale; /**< The scale of the entity. */
        sf::IntRect rect; /**< The rectangle that defines the entity's position and size. */
        int health; /**< The health points of the entity. */
        int healthBoost = 0; /**< The health boost of the entity. */
        int damage; /**< The damage points of the entity. */
        int shootingDelay; /**< The delay between two shots of the entity. */
        int speed; /**< The speed of the entity. */
        sf::Time delayForDispawn; /**< The delay before the entity disappears. */
        int stat; /**< The stat of the entity. */
        ShootingPattern shootingPattern; /**< The shooting pattern of the entity. */
        PowerUpType powerUpType; /**< The power up type of the entity. */

        /**
         * @brief Constructs an EntityClass object with the given parameters.
         * @param assetName The name of the asset used for the entity.
         * @param projectileAssetName The name of the asset used for the entity's projectile.
         * @param scale The scale of the entity.
         * @param rect The rectangle that defines the entity's position and size.
         * @param health The health points of the entity.
         * @param damage The damage points of the entity.
         * @param shootingDelay The delay between two shots of the entity.
         * @param speed The speed of the entity.
         * @param shootingPattern The shooting pattern of the entity.
         */
        EntityClass(std::string assetName, std::string projectileAssetName, Component::Position scale, sf::IntRect rect, int health, int damage, int shootingDelay, int speed, ShootingPattern shootingPattern);

        /**
         * @brief Constructs an EntityClass object with the given parameters.
         * @param assetName The name of the asset used for the entity.
         * @param scale The scale of the entity.
         * @param rect The rectangle that defines the entity's position and size.
         * @param powerUpType The power up type of the entity.
         * @param delayForDispawn The delay before the entity disappears.
         * @param stat The stat of the entity.
         */
        EntityClass(std::string assetName, Component::Position scale, sf::IntRect rect, PowerUpType powerUpType, sf::Time delayForDispawn, int stat);
    };

    /**
     * @brief The EntityClassFactory class is responsible for creating EntityClass objects.
     */
    class EntityClassFactory {
    public:
        /**
         * @brief Creates an EntityClass object with the given entity class type.
         * @param entityClass The type of the entity class.
         * @return The created EntityClass object.
         */
        static EntityClass CreateEntityClass(EntityClasses entityClass);
    };
}
