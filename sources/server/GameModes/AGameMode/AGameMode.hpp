/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** AGameMode
*/

#pragma once

#include "server/GameModes/IGameMode.hpp"

/// @brief AGameMode class
class AGameMode : public IGameMode {
    public:
        AGameMode(const char **av, int ac, bool isMultiplayer = false);
        ~AGameMode() = default;

        bool isMultiplayer() const override { return m_isMultiplayer;}
    protected:
        bool m_isMultiplayer = false;
};
