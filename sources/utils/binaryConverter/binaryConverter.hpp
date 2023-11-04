/*
** EPITECH PROJECT, 2023
** Binary converter class
** File description:
** This class create packet and convert binary to struct and struct to binary
*/

#pragma once

#include "ECS/RegistryClass/Registry.hpp"

/**
 * @brief A class that provides methods to convert binary data to structured data and vice versa.
 */
class binaryConverter {
    public:
        binaryConverter() = default;
        ~binaryConverter() = default;

        /**
         * @brief Converts binary data to structured data.
         *
         * @param buffer A pointer to the buffer containing the binary data.
         * @return A pointer to the structured data.
         */
        packet_t convertBinaryToStruct(const char *buffer);

        /**
         * @brief Converts a binary buffer to a client_packet_t input.
         *
         * @param buffer The binary buffer to convert.
         * @return The converted client_packet_t input.
         */
        client_packet_t convertBinaryToInput(const char *buffer);

        /**
         * @brief Converts structured data to binary data.
         *
         * @param nbEntites The number of entities in the structured data.
         * @param messages A pointer to the structured data.
         * @return A pointer to the binary data.
         */
        std::vector<char> convertStructToBinary(packet_t packet);

        /**
         * @brief Converts a client_packet_t input to a binary buffer.
         *
         * @param t_input The client_packet_t input to convert.
         * @return The converted binary buffer.
         */
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
