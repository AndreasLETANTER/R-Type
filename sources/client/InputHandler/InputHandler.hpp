/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** InputHandler
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "ECS/RegistryClass/Registry.hpp"

/**
 * @brief InputHandler class, used to handle inputs
 */
class InputHandler {
    public:
        /**
         * @brief Constructor of InputHandler
         *
         * @param t_player_id The id of the player
         */
        InputHandler(unsigned int t_player_id);
        ~InputHandler() = default;

        /**
         * @brief Handles user inputs and returns a vector of client packets.
         *
         * @return std::vector<client_packet_t> A vector of client packets representing the user inputs.
         */
        std::vector<client_packet_t> handle_inputs();

    protected:
    private:
        std::map<sf::Keyboard::Key, bool> m_keyMapState;
        std::map<sf::Keyboard::Key, bool> m_keyMapStatePrev;
        std::vector<sf::Keyboard::Key> m_keyMap;
        std::vector<client_packet_t> m_inputPacketQueue;
        unsigned int m_player_id;
};
