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
        AGameMode(bool isMultiplayer = false) : m_isMultiplayer(isMultiplayer) {}
        ~AGameMode() = default;

        bool isMultiplayer() const override { return m_isMultiplayer;}
    private:
        bool m_isMultiplayer = false;
};
