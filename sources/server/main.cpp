/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/


#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameModes/GameModeFactory/GameModeFactory.hpp"

int main(const int ac, const char **av)
{
    GameModeFactory factory;
    std::unique_ptr<IGameMode> gameMode;
    try {
        gameMode = factory.createGameMode("Endless", av, ac, false);
        gameMode->init();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    gameMode->run();

}
