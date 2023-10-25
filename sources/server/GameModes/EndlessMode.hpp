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
        ~EndlessMode() = default;
        void init();
        void run();
    protected:
    private:
};
