/*
** EPITECH PROJECT, 2023
** Handle Argument
** File description:
** The goal of this class is to check is the parameter is valid, else throw error
*/

#include <iostream>

#include "server/handleArgument/handleArgument.hpp"
#include "utils/debugColors/debugColors.hpp"

u_int16_t handleArgument::getPort(char const *t_av) const
{
    u_int16_t port = DEFAULT_PORT;

    if (t_av != nullptr) {
        try {
            check_if_number(t_av);
            port = std::stoi(t_av);
        } catch (std::invalid_argument const &e) {
            printError(e.what());
        }
    }
    return port;
}

void handleArgument::check_if_number(std::string const &t_str) const
{
    if (t_str.empty()) {
        throw std::invalid_argument("Invalid argument: empty string");
    }
    for (char const &c : t_str) {
        if (!std::isdigit(c)) {
            throw std::invalid_argument("Invalid argument: not a number or not a positive number");
        }
    }
}
