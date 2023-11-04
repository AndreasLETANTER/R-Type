/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** entity
*/

#pragma once

#include <cstddef>

/**
 * @brief The Entity class represents an entity in the game.
 * An entity is an object that exists in the game world, such as a player, an enemy, or a projectile.
 * Each entity has a unique identifier represented by an std::size_t value.
 */
class Entity {
    public:
        /**
         * @brief Default destructor for Entity.
         */
        ~Entity() = default;

        /**
         * @brief Conversion operator to std::size_t.
         * This operator allows an Entity object to be implicitly converted to its unique identifier.
         *
         * @return The unique identifier of the Entity.
         */
        inline operator std::size_t() const { return m_id; };

    private:
        friend class Registry;

        /**
         * @brief Explicit constructor for Entity.
         *
         * @param id The unique identifier of the Entity.
         */
        explicit Entity(const std::size_t id);

        /**
         * @brief Default constructor for Entity.
         */
        explicit Entity();

        std::size_t m_id;
};
