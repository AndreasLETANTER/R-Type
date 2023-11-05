/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** AGameMode
*/

#pragma once

#include "server/GameModes/IGameMode.hpp"
#include "utils/HandleArgument/HandleArgument.hpp"
#include "server/udpSocket/udpSocket.hpp"
#include "server/tcpSocket/tcpSocket.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"

#include <SFML/Graphics.hpp>

/**
 * @brief AGameMode class is an abstract class that implements IGameMode interface.
 * It provides basic functionalities for game modes such as multiplayer support, argument handling, socket management, registry management, clock and window management.
 */
class AGameMode : public IGameMode {
    public:
        /**
         * @brief Constructor for AGameMode class.
         * @param av An array of strings representing the command-line arguments passed to the program.
         * @param ac An integer representing the number of command-line arguments passed to the program.
         * @param isMultiplayer A boolean representing whether the game mode is multiplayer or not.
         */
        AGameMode(const char **av, int ac, bool isMultiplayer = false);

        ~AGameMode() = default;

        /**
         * @brief Getter method for m_isMultiplayer attribute.
         * @return A boolean representing whether the game mode is multiplayer or not.
         */
        bool isMultiplayer() const override { return m_isMultiplayer;}
    protected:
        /**
         * @brief Creates a player entity with the given position, ID, and class.
         *
         * @param x The x-coordinate of the player's starting position.
         * @param y The y-coordinate of the player's starting position.
         * @param id The unique ID of the player entity.
         * @param classEnum The class of the player entity.
         */
        void create_player(int x, int y, int id, EntityClasses classEnum) override;

        /**
         * @brief Creates the background for the game mode.
         */
        void create_background() override;

        bool m_isMultiplayer = false;
        HandleArgument handleArgument;
        binaryConverter converter;
        std::unique_ptr<tcpSocket> tcpServer;
        std::unique_ptr<udpSocket> udpServer;
        Registry registry;
        sf::Clock clock;
        sf::RenderWindow window;
};
