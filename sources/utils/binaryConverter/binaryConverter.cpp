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
    t_header header = {0, 0};
    header.timestamp = 7;
    header.messageId = 3;
    (void)nbEntities;
    return (header);
}

message_t *binaryConverter::convertBinaryToStruct(char *buffer)
{
    (void)buffer;
    // t_header header = {0, 0, 0};

    // memcpy(&header, buffer, sizeof(t_header));
    // message_t *messages = new message_t[header.nbEntities];
    // for (size_t i = 0; i < header.nbEntities; i++) {
    //     memcpy(&messages[i], buffer + sizeof(t_header) + sizeof(message_t) * i, sizeof(message_t));
    // }
    // return (messages);
    return (nullptr);
}

unsigned int binaryConverter::convertBinaryToFirstMessage(char *buffer)
{
    std::cout << "len:" << strlen(buffer) << std::endl;
    t_header header;
    // t_first_message firstMessage;
    memcpy(&header, buffer, sizeof(t_header));

    long long timestamp = header.timestamp;
    long long messageId = header.messageId;
    std::cout << "header.timestamp: " << timestamp << std::endl;
    std::cout << "header.messageId: " << messageId << std::endl;


    std::cout << "header.timestamp2: " << header.timestamp << std::endl;
    std::cout << "header.messageId2: " << header.messageId << std::endl;
    // std::cout << "firstMessage.id: " << firstMessage->id << std::endl;
    
    return (1);
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
    (void)messageId;
    t_header header = createHeader(1);

    char *buffer = new char[sizeof(t_header)];
    memcpy(buffer, &header, sizeof(t_header));

    std::cout << "buffer: " << buffer << std::endl;
    std::cout << "len:" << strlen(buffer) << std::endl;
    // binaryConverter converter;
    // converter.convertBinaryToFirstMessage(buffer);

    return (buffer);
}
