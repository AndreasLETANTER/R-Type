/*
** EPITECH PROJECT, 2023
** Binary converter class
** File description:
** This class create header and convert binary to struct and struct to binary
*/

#include <chrono>
#include <random>
#include <cstring>

#include "binaryConverter.hpp"
#include "utils/debugColors/debugColors.hpp"

t_header binaryConverter::createHeader(size_t nbEntities)
{
    t_header header = {0, 0, 0};

    header.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>
    (std::chrono::system_clock::now().time_since_epoch()).count();
    header.messageId = header.timestamp + (rand() % 900 + 100);
    header.nbEntities = nbEntities;
    return (header);
}

message_t *binaryConverter::convertBinaryToStruct(char *buffer)
{
    t_header header = {0, 0, 0};

    memcpy(&header, buffer, sizeof(t_header));
    message_t *messages = new message_t[header.nbEntities];
    for (size_t i = 0; i < header.nbEntities; i++) {
        memcpy(&messages[i], buffer + sizeof(t_header) + sizeof(message_t) * i, sizeof(message_t));
    }
    return (messages);
}

unsigned int binaryConverter::convertBinaryToFirstMessage(char *buffer)
{
    t_header header = {0, 0, 0};
    t_first_message firstMessage = {0};

    memcpy(&header, buffer, sizeof(t_header));
    memcpy(&firstMessage, buffer + sizeof(t_header), sizeof(t_first_message));
    return (firstMessage.id);
}

char *binaryConverter::convertStructToBinary(size_t size, message_t *messages)
{
    t_header header = createHeader(size);
    char *buffer = new char[sizeof(t_header) + sizeof(message_t) * size];

    for (size_t i = 0; i < size; i++) {
        memcpy(buffer + sizeof(t_header) + sizeof(message_t) * i, &messages[i], sizeof(message_t));
    }
    memcpy(buffer, &header, sizeof(t_header));
    return (buffer);
}

char *binaryConverter::convertStructToFirstMessage(unsigned int messageId)
{
    t_header header = createHeader(0);
    t_first_message firstMessage = {messageId};
    char *buffer = new char[sizeof(t_header) + sizeof(t_first_message)];

    memcpy(buffer, &header, sizeof(t_header));
    memcpy(buffer + sizeof(t_header), &firstMessage, sizeof(t_first_message));
    return (buffer);
}
