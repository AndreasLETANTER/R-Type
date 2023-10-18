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
    header.nbEntities = nbEntities;
    return (header);
}

std::pair<message_t *, size_t> binaryConverter::convertBinaryToStruct(char *buffer)
{
    t_header header = {0, 0};
    size_t offset = 0;
    message_t *messages = nullptr;

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

t_input binaryConverter::convertBinaryToInput(char *buffer)
{
    t_header header = {0, 0};
    t_input key = {0, sf::Keyboard::Unknown};
    size_t offset = 0;

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

std::vector<char> binaryConverter::convertStructToInput(unsigned int t_id, sf::Keyboard::Key t_key)
{
    std::vector<char> buffer;
    t_header header = createHeader(0);
    t_input input = {t_id, t_key};
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&header.nbEntities), reinterpret_cast<char *>(&header.nbEntities) + sizeof(header.nbEntities));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&input.id), reinterpret_cast<char *>(&input.id) + sizeof(input.id));
    buffer.insert(buffer.end(), reinterpret_cast<char *>(&input.key), reinterpret_cast<char *>(&input.key) + sizeof(input.key));
    return (buffer);
}
