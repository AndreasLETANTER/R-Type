/*
** EPITECH PROJECT, 2023
** Binary converter class
** File description:
** This class create packet and convert binary to struct and struct to binary
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"

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
        packet_t convertBinaryToStruct(const char *buffer);
        client_packet_t convertBinaryToInput(const char *buffer);

        /**
         * @brief Converts structured data to binary data.
         * 
         * @param nbEntites The number of entities in the structured data.
         * @param messages A pointer to the structured data.
         * @return A pointer to the binary data.
         */
        std::vector<char> convertStructToBinary(packet_t packet);
        std::vector<char> convertInputToBinary(client_packet_t t_input);

    private:
        /**
         * @brief Creates a packet for the binary data.
         * 
         * @param messageType The type of message.
         * @return The packet for the binary data.
         */
        packet_t createpacket(unsigned int messageType);
};
