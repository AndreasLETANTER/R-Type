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
    size_t offset = 0;
    message_t *messages = nullptr;

    memcpy(&header.messageId, buffer + offset, sizeof(header.messageId));
    offset += sizeof(header.messageId);
    memcpy(&header.timestamp, buffer + offset, sizeof(header.timestamp));
    offset += sizeof(header.timestamp);
    memcpy(&header.nbEntities, buffer + offset, sizeof(header.nbEntities));
    offset += sizeof(header.nbEntities);
    messages = new message_t[header.nbEntities];
    for (size_t i = 0; i < header.nbEntities; i++) {
        memcpy(&messages[i].sprite_name, buffer + offset, sizeof(messages[i].sprite_name));
        offset += sizeof(messages[i].sprite_name);
        memcpy(&messages[i].x, buffer + offset, sizeof(messages[i].x));
        offset += sizeof(messages[i].x);
        memcpy(&messages[i].y, buffer + offset, sizeof(messages[i].y));
        offset += sizeof(messages[i].y);
        memcpy(&messages[i].rect, buffer + offset, sizeof(messages[i].rect));
        offset += sizeof(messages[i].rect);
        memcpy(&messages[i].position, buffer + offset, sizeof(messages[i].position));
        offset += sizeof(messages[i].position);
    }
    return (std::make_pair(messages, header.nbEntities));
}

t_first_message binaryConverter::convertBinaryToFirstMessage(char *buffer)
{
    t_header header = {0, 0, 0};
    t_first_message firstMessage = {0, 0};
    size_t offset = 0;

    memcpy(&header.messageId, buffer + offset, sizeof(header.messageId));
    offset += sizeof(header.messageId);
    memcpy(&header.timestamp, buffer + offset, sizeof(header.timestamp));
    offset += sizeof(header.timestamp);
    memcpy(&header.nbEntities, buffer + offset, sizeof(header.nbEntities));
    offset += sizeof(header.nbEntities);
    memcpy(&firstMessage.id, buffer + offset, sizeof(firstMessage.id));
    offset += sizeof(firstMessage.id);
    memcpy(&firstMessage.udp_port, buffer + offset, sizeof(firstMessage.udp_port));
    offset += sizeof(firstMessage.udp_port);
    return (firstMessage);
}

t_input binaryConverter::convertBinaryToInput(char *buffer)
{
    t_header header = {0, 0, 0};
    t_input key = {0, sf::Keyboard::Unknown};
    size_t offset = 0;

    memcpy(&header.messageId, buffer + offset, sizeof(header.messageId));
    offset += sizeof(header.messageId);
    memcpy(&header.timestamp, buffer + offset, sizeof(header.timestamp));
    offset += sizeof(header.timestamp);
    memcpy(&header.nbEntities, buffer + offset, sizeof(header.nbEntities));
    offset += sizeof(header.nbEntities);
    memcpy(&key.id, buffer + offset, sizeof(key.id));
    offset += sizeof(key.id);
    memcpy(&key.key, buffer + offset, sizeof(key.key));
    offset += sizeof(key.key);
    return (key);
}

std::vector<char> binaryConverter::convertStructToBinary(size_t size, message_t *messages)
{
    std::vector <char> buffer;
    t_header header = createHeader(size);
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.messageId), reinterpret_cast<char *>(&header.messageId) + sizeof(header.messageId));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.timestamp), reinterpret_cast<char *>(&header.timestamp) + sizeof(header.timestamp));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.nbEntities), reinterpret_cast<char *>(&header.nbEntities) + sizeof(header.nbEntities));
    for (size_t i = 0; i < size; i++) {
        buffer.insert(buffer.end(), reinterpret_cast<char *>(&messages[i].sprite_name), reinterpret_cast<char *>(&messages[i].sprite_name) + sizeof(messages[i].sprite_name));
        buffer.insert(buffer.end(), reinterpret_cast<char *>(&messages[i].x), reinterpret_cast<char *>(&messages[i].x) + sizeof(messages[i].x));
        buffer.insert(buffer.end(), reinterpret_cast<char *>(&messages[i].y), reinterpret_cast<char *>(&messages[i].y) + sizeof(messages[i].y));
        buffer.insert(buffer.end(), reinterpret_cast<char *>(&messages[i].rect), reinterpret_cast<char *>(&messages[i].rect) + sizeof(messages[i].rect));
        buffer.insert(buffer.end(), reinterpret_cast<char *>(&messages[i].position), reinterpret_cast<char *>(&messages[i].position) + sizeof(messages[i].position));
    }
    return (buffer);
}

std::vector<char> binaryConverter::convertStructToFirstMessage(unsigned int messageId)
{
    (void)messageId;
    std::vector<char> buffer;
    t_header header = createHeader(messageId);
    t_first_message firstMessage = {messageId, 4242};

    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.messageId), reinterpret_cast<char *>(&header.messageId) + sizeof(header.messageId));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.timestamp), reinterpret_cast<char *>(&header.timestamp) + sizeof(header.timestamp));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.nbEntities), reinterpret_cast<char *>(&header.nbEntities) + sizeof(header.nbEntities));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&firstMessage.id), reinterpret_cast<char *>(&firstMessage.id) + sizeof(firstMessage.id));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&firstMessage.udp_port), reinterpret_cast<char *>(&firstMessage.udp_port) + sizeof(firstMessage.udp_port));
    return (buffer);
}

std::vector<char> binaryConverter::convertStructToInput(unsigned int t_id, sf::Keyboard::Key t_key)
{
    std::vector<char> buffer;
    t_header header = createHeader(0);
    t_input input = {t_id, t_key};
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.messageId), reinterpret_cast<char *>(&header.messageId) + sizeof(header.messageId));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.timestamp), reinterpret_cast<char *>(&header.timestamp) + sizeof(header.timestamp));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.nbEntities), reinterpret_cast<char *>(&header.nbEntities) + sizeof(header.nbEntities));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&input.id), reinterpret_cast<char *>(&input.id) + sizeof(input.id));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&input.key), reinterpret_cast<char *>(&input.key) + sizeof(input.key));
    return (buffer);
}
