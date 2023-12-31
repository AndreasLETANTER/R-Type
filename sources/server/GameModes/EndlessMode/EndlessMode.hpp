/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** EndlessMode
*/

#pragma once

#include "server/GameModes/AGameMode/AGameMode.hpp"

#define LOSE_CODE 106
#define WIN_CODE 107

/**
 * @brief EndlessMode class, a derived class of AGameMode.
 */
class EndlessMode : public AGameMode {
    public:
        /**
         * @brief Construct a new Endless Mode object
         */
        using AGameMode::AGameMode;

        /**
         * @brief Destroy the Endless Mode object
         */
        ~EndlessMode() = default;

        /**
         * @brief Initialize the Endless Mode object
         */
        void init() override;

        /**
         * @brief Run the Endless Mode object
         */
        void run() override;
    private:
        bool m_isAPlayerCreated = false;
};
