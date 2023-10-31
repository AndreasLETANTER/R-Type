/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** EndlessMode
*/

#pragma once

#include "server/GameModes/AGameMode/AGameMode.hpp"

class EndlessMode : public AGameMode {
    public:
        using AGameMode::AGameMode;
        ~EndlessMode() = default;
        void init() override;
        void run() override;
    protected:
    private:
};
