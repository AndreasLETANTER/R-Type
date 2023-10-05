/*
** EPITECH PROJECT, 2023
** Binary converter class
** File description:
** This class create header and convert binary to struct and struct to binary
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"

typedef struct s_header
{
    long long timestamp;
    unsigned int messageId;
    size_t nbEntities;
} t_header;

class binaryConverter
{
    public:
        binaryConverter() = default;
        ~binaryConverter() = default;
        message_t *convertBinaryToStruct(char *buffer);
        char *convertStructToBinary(size_t nbEntites, message_t *messages);
    private:
        t_header createHeader(size_t nbEntities);
};