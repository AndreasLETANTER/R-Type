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
    t_header header = {0, 0};
    header.timestamp = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() % 10000000);
    header.messageId = std::rand() % 10000000;

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
    t_header header = {0, 0};
    t_first_message firstMessage = {0};
    size_t offset = 0;

    memcpy(&header.messageId, buffer + offset, sizeof(header.messageId));
    offset += sizeof(header.messageId);
    memcpy(&header.timestamp, buffer + offset, sizeof(header.timestamp));
    offset += sizeof(header.timestamp);
    memcpy(&firstMessage.id, buffer + offset, sizeof(firstMessage.id));
    offset += sizeof(firstMessage.id);

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

std::vector<char> binaryConverter::convertStructToFirstMessage(unsigned int messageId)
{
    (void)messageId;
    std::vector<char> buffer;
    t_header header = createHeader(messageId);
    t_first_message firstMessage = {messageId};

    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.messageId), reinterpret_cast<char *>(&header.messageId) + sizeof(header.messageId));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.timestamp), reinterpret_cast<char *>(&header.timestamp) + sizeof(header.timestamp));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&firstMessage.id), reinterpret_cast<char *>(&firstMessage.id) + sizeof(firstMessage.id));
    // t_first_message firstMessage = {messageId};
    // buffer.insert(buffer.end(), (char *)&firstMessage, (char *)&firstMessage + sizeof(t_first_message));


    std::cout << "buffer: " << buffer.data() << std::endl;
    std::cout << "len:" << strlen(buffer.data()) << std::endl;
    std::cout << "header.messageId: " << header.messageId << std::endl;
    std::cout << "header.timestamp: " << header.timestamp << std::endl;
    std::cout << "firstMessage: " << firstMessage.id << std::endl;
    // binaryConverter converter;
    // converter.convertBinaryToFirstMessage(buffer);
    return (buffer);
}
