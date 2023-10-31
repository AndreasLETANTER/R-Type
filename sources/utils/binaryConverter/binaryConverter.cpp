/*
** EPITECH PROJECT, 2023
** Binary converter class
** File description:
** This class create packet and convert binary to struct and struct to binary
*/

#include <chrono>
#include <random>
#include <cstring>
#include <random>

#include "binaryConverter.hpp"
#include "utils/debugColors/debugColors.hpp"

packet_t binaryConverter::createpacket(unsigned int messageType)
{
    packet_t packet;

    packet.messageType = messageType;
    return (packet);
}

packet_t binaryConverter::convertBinaryToStruct(const char *buffer)
{
    packet_t packet;

    memcpy(&packet, buffer, sizeof(packet));
    return (packet);
}

input_t binaryConverter::convertBinaryToInput(const char *buffer)
{
    input_t key = {0, sf::Keyboard::Unknown, false};

    memcpy(&key, buffer, sizeof(key));
    return (key);
}

std::vector<char> binaryConverter::convertStructToBinary(packet_t packet)
{
    std::vector <char> buffer;
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&packet), reinterpret_cast<char *>(&packet) + sizeof(packet));
    return (buffer);
}

std::vector<char> binaryConverter::convertInputToBinary(input_t t_input)
{
    std::vector<char> buffer;
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&t_input), reinterpret_cast<char *>(&t_input) + sizeof(t_input));
    return (buffer);
}
