/*
** EPITECH PROJECT, 2023
** Binary Converter
** File description:
** Functions are used to convert binary to str and str to binary
*/

#pragma once

#include <string>

/**
 * @brief This class provides methods to convert strings to binary and vice versa.
 */
class binaryConverter {
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
         * @brief Converts a string to binary.
         * @param t_str The string to convert.
         * @return The binary representation of the input string.
         */
        std::string string_to_binary(std::string t_str);

        /**
         * @brief Converts binary to a string.
         * @param t_str The binary string to convert.
         * @return The string representation of the input binary string.
         */
        std::string binary_to_string(std::string t_str);
};
