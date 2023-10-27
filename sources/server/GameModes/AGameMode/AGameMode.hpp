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

/// @brief AGameMode class
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
        /**
         * @brief Default destructor for AGameMode class.
         */
        ~AGameMode() = default;

        /**
         * @brief Getter method for m_isMultiplayer attribute.
         * @return A boolean representing whether the game mode is multiplayer or not.
         */
        bool isMultiplayer() const override { return m_isMultiplayer;}
    protected:
        void create_player(int x, int y, int id) override;
        void create_background() override;
        bool m_isMultiplayer = false; /**< A boolean representing whether the game mode is multiplayer or not. */
        HandleArgument handleArgument; /**< An instance of HandleArgument class for handling command-line arguments. */
        binaryConverter converter; /**< An instance of binaryConverter class for converting binary data. */
        std::unique_ptr<tcpSocket> tcpServer; /**< A unique pointer to tcpSocket class for managing TCP sockets. */
        std::unique_ptr<udpSocket> udpServer; /**< A unique pointer to udpSocket class for managing UDP sockets. */
        Registry registry; /**< An instance of Registry class for managing game objects. */
        sf::Clock clock; /**< An instance of sf::Clock class for measuring time. */
        sf::RenderWindow window; /**< An instance of sf::RenderWindow class for managing game window. */
};
