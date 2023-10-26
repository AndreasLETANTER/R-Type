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

#include "server/GameModes/DefaultMode/DefaultMode.hpp"

/// @brief Factory for GameMode class
class GameModeFactory {
    public:
        GameModeFactory();
        ~GameModeFactory() = default;

        std::unique_ptr<IGameMode> createGameMode(const std::string &gameModeName, const char **av, int ac, bool isMultiplayer);
    private:
        std::unordered_map<std::string,
            std::function<std::unique_ptr<IGameMode>(const char **av,
    int ac, bool isMultiplayer)>>
            m_gameModeMap = {
                {"Default", [](const char **av, int ac, bool isMultiplayer) {
                    return std::make_unique<DefaultMode>(av, ac, isMultiplayer);
                }}
        };
};
