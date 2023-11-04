/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** GameModeFactory
*/

#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <functional>

#include "server/GameModes/EndlessMode/EndlessMode.hpp"
#include "server/GameModes/DefaultMode/DefaultMode.hpp"

/**
 * @brief The GameModeFactory class is responsible for creating instances of IGameMode based on the given game mode name.
 */
class GameModeFactory {
    public:
        GameModeFactory();
        ~GameModeFactory() = default;

        /**
         * @brief Creates an instance of IGameMode based on the given game mode name.
         *
         * @param gameModeName The name of the game mode to create.
         * @param av The command line arguments.
         * @param ac The number of command line arguments.
         * @param isMultiplayer Whether the game mode is multiplayer or not.
         * @return std::unique_ptr<IGameMode> The created game mode instance.
         */
        std::unique_ptr<IGameMode> createGameMode(const std::string &gameModeName, const char **av, int ac, bool isMultiplayer);
    private:
        std::unordered_map<std::string, std::function<std::unique_ptr<IGameMode>(const char **av, int ac, bool isMultiplayer)>> m_gameModeMap = {
                {"Default", [](const char **av, int ac, bool isMultiplayer) {
                    return std::make_unique<DefaultMode>(av, ac, isMultiplayer);
                }},
                {"Endless", [](const char **av, int ac, bool isMultiplayer) {
                    return std::make_unique<EndlessMode>(av, ac, isMultiplayer);
                }}
        };
};
