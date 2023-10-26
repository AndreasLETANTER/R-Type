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
        ~DefaultMode() = default;
        using AGameMode::AGameMode;
        void init() override;
        void run() override;

    protected:
    private:
};
