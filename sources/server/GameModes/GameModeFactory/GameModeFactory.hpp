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

#include "server/GameModes/IGameMode.hpp"
#include "server/GameModes/WaveGameMode/WaveGameMode.hpp"
#include "server/GameModes/EndlessGameMode/EndlessGameMode.hpp"
#include "server/GameModes/PvpGameMode/PvpGameMode.hpp"

/// @brief Factory for GameMode class
class GameModeFactory {
    public:
        GameModeFactory();
        ~GameModeFactory() = default;

        std::unique_ptr<IGameMode> createGameMode(const std::string &gameModeName);
    private:
        std::unordered_map<std::string, std::function<std::unique_ptr<IGameMode>()>> m_gameModeMap = {
        };
};
