/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** EntityClass
*/

#pragma once

enum EntityClasses {
    NUGO,
    ANDREAS,
    ELIOT,
    LOUIS,
    MOB_ORANGE_CRAB,
    MOB_YELLOW_POPCORN
};

namespace Component {
    /**
     * @brief The EntityClass class represents the class of an entity.
     */
    class EntityClass {
        public:
            /**
             * @brief Default constructor for EntityClass class.
             */
            EntityClass() = default;
            int health; /**< The health of the entity. */
            int damage; /**< The damage of the entity. */
            int shootingDelay; /**< The delay between each shot of the entity. */
            int speed; /**< The speed of the entity. */

            /**
             * @brief Construct a new Entity Class object with specified values.
             *
             * @param entityClass The class of the entity.
             * @param health The health of the entity.
             * @param damage The damage of the entity.
             * @param shootingDelay the shootingDelay of the entity.
             * @param speed the speed of the entity.
             */
            inline EntityClass(int health, int damage, int shootingDelay, int speed) { this->health = health; this->damage = damage; this->shootingDelay = shootingDelay; this->speed = speed; }

            /**
             * @brief Creates a new Entity Class object with specified values.
             *
             * @param entityClass The class of the entity.
             *
             * @return A new Entity Class object.
             */
            static EntityClass CreateEntityClass(EntityClasses entityClass) {
                switch (entityClass) {
                    case EntityClasses::NUGO:
                        return EntityClass(100, 5, 500, 5);
                    case EntityClasses::ANDREAS:
                        return EntityClass(100, 5, 500, 5);
                    case EntityClasses::ELIOT:
                        return EntityClass(100, 5, 500, 5);
                    case EntityClasses::LOUIS:
                        return EntityClass(100, 5, 500, 5);
                    case EntityClasses::MOB_ORANGE_CRAB:
                        return EntityClass(10, 25, 3000, 5);
                    case EntityClasses::MOB_YELLOW_POPCORN:
                        return EntityClass(10, 25, 3000, 5);
                    default:
                        return EntityClass(100, 5, 500, 5);
                }
            }
    };
}
