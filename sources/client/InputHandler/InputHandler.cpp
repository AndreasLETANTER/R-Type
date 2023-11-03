/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** InputHandler
*/

#include "InputHandler.hpp"

InputHandler::InputHandler(unsigned int t_player_id)
{
    m_player_id = t_player_id;
    m_keyMap.push_back(sf::Keyboard::Z);
    m_keyMap.push_back(sf::Keyboard::S);
    m_keyMap.push_back(sf::Keyboard::Q);
    m_keyMap.push_back(sf::Keyboard::D);
    m_keyMap.push_back(sf::Keyboard::Space);
    m_keyMapState[sf::Keyboard::Z] = false;
    m_keyMapState[sf::Keyboard::S] = false;
    m_keyMapState[sf::Keyboard::Q] = false;
    m_keyMapState[sf::Keyboard::D] = false;
    m_keyMapState[sf::Keyboard::Space] = false;
    m_keyMapStatePrev[sf::Keyboard::Z] = false;
    m_keyMapStatePrev[sf::Keyboard::S] = false;
    m_keyMapStatePrev[sf::Keyboard::Q] = false;
    m_keyMapStatePrev[sf::Keyboard::D] = false;
    m_keyMapStatePrev[sf::Keyboard::Space] = false;
}

std::vector<client_packet_t> InputHandler::handle_inputs()
{
    client_packet_t tempPacket;
    m_inputPacketQueue.clear();
    for (unsigned int i = 0; i < m_keyMap.size(); i++) {
        m_keyMapState[m_keyMap[i]] = sf::Keyboard::isKeyPressed(m_keyMap[i]);
    }
    for (unsigned int i = 0; i < m_keyMap.size() && i < m_keyMapStatePrev.size(); i++) {
        if (m_keyMapState[m_keyMap[i]] != m_keyMapStatePrev[m_keyMap[i]]) {
            tempPacket.messageType = CLIENT_INPUT_CODE;
            tempPacket.input.id = m_player_id;
            tempPacket.input.key = m_keyMap[i];
            tempPacket.input.pressed = m_keyMapState[m_keyMap[i]];
            m_inputPacketQueue.push_back(tempPacket);
        }
    }
    m_keyMapStatePrev = m_keyMapState;
    return m_inputPacketQueue;
}