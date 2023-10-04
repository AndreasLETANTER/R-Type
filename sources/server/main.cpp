/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ECS/Systems/LoggingSystem/LoggingSystem.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"
#include "ECS/Systems/ControlSystem/ControlSystem.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Systems/AutoMoveSystem/AutoMoveSystem.hpp"
#include "ECS/Systems/ShootSystem/ShootSystem.hpp"
#include "ECS/Systems/ProjectileSystem/ProjectileSystem.hpp"
#include "ECS/Systems/CollisionSystem/CollisionSystem.hpp"
#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/ScrollingBackgroundSystem/ScrollingBackgroundSystem.hpp"

#include "tcpSocket/tcpSocket.hpp"
#include "handleArgument/handleArgument.hpp"

int main(int ac, char **av)
{
    (void)ac;
    handleArgument handleArgument;
    tcpSocket server(handleArgument.getPort(av[1]));

    server.run();
    return 0;
}
