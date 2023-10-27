/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** IGameMode
*/

#pragma once

#include <string>

/// @brief Interface for GameMode class
class IGameMode {
    public:
        /// @brief Default destructor for IGameMode
        virtual ~IGameMode() = default;

        virtual void init() = 0;

        /// @brief Run the game mode
        virtual void run() = 0;

        /// @brief Get the multiplayer status of the game mode
        virtual bool isMultiplayer() const = 0;
};
