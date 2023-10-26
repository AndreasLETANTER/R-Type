/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/


#include <iostream>
#include <SFML/Graphics.hpp>

#include "utils/ParserClass/Parser.hpp"
#include "ECS/Systems/LoggingSystem/LoggingSystem.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"
#include "ECS/Systems/ControlSystem/ControlSystem.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Systems/AutoMoveSystem/AutoMoveSystem.hpp"
#include "ECS/Systems/ShootSystem/ShootSystem.hpp"
#include "ECS/Systems/ProjectileSystem/ProjectileSystem.hpp"
#include "ECS/Systems/CollisionSystem/CollisionSystem.hpp"
#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/ScrollSystem/ScrollSystem.hpp"
#include "ECS/Systems/HealthSystem/HealthSystem.hpp"
#include "ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.hpp"
#include "ECS/Systems/ScoreSystem/ScoreSystem.hpp"
#include "utils/handleArgument/handleArgument.hpp"
#include "udpSocket/udpSocket.hpp"
#include "tcpSocket/tcpSocket.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"
#include "GameModes/GameModeFactory/GameModeFactory.hpp"

int main(const int ac, const char **av)
{
    GameModeFactory factory;
    std::unique_ptr<IGameMode> gameMode;
    try {
        gameMode = factory.createGameMode("Default", av, ac, true);
        gameMode->init();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    gameMode->run();

}
