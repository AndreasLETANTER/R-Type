/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** AGameMode
*/

#pragma once

#include "server/GameModes/IGameMode.hpp"
#include "utils/handleArgument/handleArgument.hpp"
#include "server/udpSocket/udpSocket.hpp"
#include "server/tcpSocket/tcpSocket.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"

#include <SFML/Graphics.hpp>

/// @brief AGameMode class
class AGameMode : public IGameMode {
    public:
        AGameMode(const char **av, int ac, bool isMultiplayer = false);
        ~AGameMode() = default;

        bool isMultiplayer() const override { return m_isMultiplayer;}
    protected:
        bool m_isMultiplayer = false;
        handleArgument handleArgument;
        binaryConverter converter;
        std::unique_ptr<tcpSocket> tcpServer;
        std::unique_ptr<udpSocket> udpServer;
        Registry registry;
        sf::Clock clock;
        sf::RenderWindow window;
};
