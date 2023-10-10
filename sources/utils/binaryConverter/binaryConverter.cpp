/*
** EPITECH PROJECT, 2023
** Binary converter class
** File description:
** This class create header and convert binary to struct and struct to binary
*/

#include <chrono>
#include <random>
#include <cstring>
#include <random>

#include "binaryConverter.hpp"
#include "utils/debugColors/debugColors.hpp"

t_header binaryConverter::createHeader(size_t nbEntities)
{
    t_header header = {0, 0, 0};
    header.timestamp = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() % 10000000);
    header.messageId = std::rand() % 10000000;
    header.nbEntities = nbEntities;
    return (header);
}

std::pair<message_t *, size_t> binaryConverter::convertBinaryToStruct(char *buffer)
{
    t_header header = {0, 0, 0};
    message_t *messages = nullptr;
    t_packet packet = {header, messages};

    packet.messages = new message_t[100];

    memcpy(&packet, buffer, sizeof(packet));
    std::cout << "Message NB: " << packet.header.nbEntities << std::endl;
    for (int i = 0; (size_t)i < packet.header.nbEntities; i++) {
        std::cout << "Message TRIPLE COUCOU " << i << ": " << packet.messages[i].sprite_name << std::endl;
    }
    return (std::make_pair(packet.messages, packet.header.nbEntities));
}

t_first_message binaryConverter::convertBinaryToFirstMessage(char *buffer)
{
    t_header header = {0, 0, 0};
    t_first_message firstMessage = {0, 0};
    t_first_packet firstPacket = {header, firstMessage};
    
    memcpy(&firstPacket, buffer, sizeof(firstPacket));
    return (firstPacket.message);
}

std::vector<char> binaryConverter::convertStructToBinary(size_t size, message_t *messages)
{
    std::vector <char> buffer;
    t_header header = createHeader(size);
    t_packet packet;

    packet.header = header;
    packet.messages = messages;
    for (size_t i = 0; i < size; i++) {
        std::cout << "Message COUCOU " << i << ": " << messages[i].sprite_name << std::endl;
    }
    memcpy(&buffer, &packet, sizeof(packet));
    return (buffer);
}

std::vector<char> binaryConverter::convertStructToFirstMessage(unsigned int messageId)
{
    (void)messageId;
    std::vector<char> buffer;
    t_header header = createHeader(messageId);
    t_first_message firstMessage = {messageId, 4242};
    t_first_packet firstPacket = {header, firstMessage};

    memcpy(&buffer, &firstPacket, sizeof(firstPacket));
    return (buffer);
}
