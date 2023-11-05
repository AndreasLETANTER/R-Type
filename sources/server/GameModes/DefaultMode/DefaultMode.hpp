/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** DefaultMode
*/

#pragma once

#include "server/GameModes/AGameMode/AGameMode.hpp"
#include "../../../../build/assets/Level1Config.hpp"
#include "../../../../build/assets/Level2Config.hpp"
#include "../../../../build/assets/Level3Config.hpp"

/**
 * @brief Default game mode class that inherits from AGameMode.
 */
class DefaultMode : public AGameMode {
    public:
        using AGameMode::AGameMode;
        ~DefaultMode() = default;

        /**
         * @brief Initializes the game mode.
         */
        void init() override;

        /**
         * @brief Runs the game mode.
         */
        void run() override;
    private:
        bool m_isAPlayerCreated = false;
        std::vector<std::string> m_filePath = {Level1Config, Level2Config, Level3Config};
        unsigned int m_currentLevel = 0;
};
