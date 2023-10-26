/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** DefaultMode
*/

#pragma once

#include "server/GameModes/AGameMode/AGameMode.hpp"

class DefaultMode : public AGameMode {
    public:
        using AGameMode::AGameMode;
        ~DefaultMode() = default;
        void init() override;
        void run() override;

    protected:
    private:
};
