/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** InputHandler
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "ECS/RegistryClass/Registry.hpp"

class InputHandler {
    public:
        InputHandler(unsigned int t_player_id);
        ~InputHandler() = default;
        std::vector<client_packet_t> handle_inputs();

    protected:
    private:
        std::map<sf::Keyboard::Key, bool> m_keyMapState;
        std::map<sf::Keyboard::Key, bool> m_keyMapStatePrev;
        std::vector<sf::Keyboard::Key> m_keyMap;
        std::vector<client_packet_t> m_inputPacketQueue;
        unsigned int m_player_id;
};
