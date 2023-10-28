/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** GameModeFactory
*/

#include <stdexcept>

#include "server/GameModes/GameModeFactory/GameModeFactory.hpp"

GameModeFactory::GameModeFactory()
{
}

std::unique_ptr<IGameMode> GameModeFactory::createGameMode(const std::string &gameModeName, const char **av,
int ac, bool isMultiplayer)
{
    if (m_gameModeMap.find(gameModeName) == m_gameModeMap.end())
        throw std::runtime_error("GameModeFactory: GameMode not found");
    return m_gameModeMap[gameModeName](av, ac, isMultiplayer);
}
