/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AGameMode
*/

#include "AGameMode.hpp"

AGameMode::AGameMode(const char **av, int ac, bool isMultiplayer) : handleArgument()
{
    if (ac != 4) {
        throw std::runtime_error("AGameMode: Invalid number of arguments");
    }
    tcpServer = std::make_unique<tcpSocket>(handleArgument.getPort(av[1]), handleArgument.getIp(av[3]));
    udpServer = std::make_unique<udpSocket>(handleArgument.getPort(av[2]), handleArgument.getIp(av[3]));
    m_isMultiplayer = isMultiplayer;
}
