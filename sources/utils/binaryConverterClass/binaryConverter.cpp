/*
** EPITECH PROJECT, 2023
** Binary Converter
** File description:
** Functions are used to convert binary to str and str to binary
*/

#include <bitset>
#include <stdexcept>
#include "../debugColors/debugColors.hpp"
#include "binaryConverter.hpp"

std::string binaryConverter::string_to_binary(std::string t_str)
{
    std::string binary;

    for (char& _char : t_str) {
        binary += std::bitset<8>(_char).to_string();
    }
    return binary;
}

std::string binaryConverter::binary_to_string(std::string t_str)
{
    std::string str;
    std::string byte;

    try {
        for (size_t i = 0; i < t_str.length(); i += 8) {
            byte = t_str.substr(i, 8);
            if (byte.find_first_not_of("01") != std::string::npos) {
                throw std::invalid_argument("Invalid binary string");
            }
            str += std::bitset<8>(byte).to_ulong();
        }
    } catch (std::invalid_argument const &e) {
        printError(e.what());
    }
    return str;
}

