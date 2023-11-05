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

    if (ac < 5) {
        std::cerr << "Usage: ./r-type_server <port> <map> <gameMode> [args]" << std::endl;
        return 84;
    }
    try {
        gameMode = factory.createGameMode(av[4], av, ac, true);
        gameMode->init();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 84;
    }

    gameMode->run();

}
