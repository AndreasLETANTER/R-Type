/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** IGameMode
*/

#pragma once

#include <string>

#include "ECS/Components/EntityClass.hpp"

/**
 * @brief Interface for game modes.
 */
class IGameMode {
    public:
        virtual ~IGameMode() = default;

        /**
         * @brief Initializes the game mode.
         */
        virtual void init() = 0;

        /**
         * @brief Runs the game mode.
         */
        virtual void run() = 0;

        /**
         * @brief Returns whether the game mode is multiplayer or not.
         *
         * @return true if the game mode is multiplayer, false otherwise.
         */
        virtual bool isMultiplayer() const = 0;
    protected:
        /**
         * @brief Creates a player entity with the given position, ID, and class.
         *
         * @param x The x-coordinate of the player's starting position.
         * @param y The y-coordinate of the player's starting position.
         * @param id The unique ID of the player entity.
         * @param classEnum The class of the player entity.
         */
        virtual void create_player(int x, int y, int id, EntityClasses classEnum) = 0;

        /**
         * @brief Creates the background for the game mode.
         */
        virtual void create_background() = 0;
};
