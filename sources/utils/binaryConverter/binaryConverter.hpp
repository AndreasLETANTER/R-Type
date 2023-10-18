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
    unsigned int nbEntities;
    unsigned int messageType;
} t_header;

class binaryConverter {
/**
 * @brief A class that provides methods to convert binary data to structured data and vice versa.
 */
    public:
        /**
         * @brief Default constructor.
         */
        binaryConverter() = default;

        /**
         * @brief Default destructor.
         */
        ~binaryConverter() = default;

        /**
         * @brief Converts binary data to structured data.
         * 
         * @param buffer A pointer to the buffer containing the binary data.
         * @return A pointer to the structured data.
         */
        std::pair<message_t *, size_t> convertBinaryToStruct(char *buffer);
        t_input convertBinaryToInput(char *buffer);

        /**
         * @brief Converts structured data to binary data.
         * 
         * @param nbEntites The number of entities in the structured data.
         * @param messages A pointer to the structured data.
         * @return A pointer to the binary data.
         */
        std::vector<char> convertStructToBinary(size_t nbEntites, message_t *messages);
        std::vector<char> convertStructToInput(unsigned int t_id, sf::Keyboard::Key key);

    private:
        /**
         * @brief Creates a header for the binary data.
         * 
         * @param nbEntities The number of entities in the structured data.
         * @return The header for the binary data.
         */
        t_header createHeader(size_t nbEntities);
};
