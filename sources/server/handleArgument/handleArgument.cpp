/*
** EPITECH PROJECT, 2023
** Handle Argument
** File description:
** The goal of this class is to check is the parameter is valid, else throw error
*/

#include <iostream>
#include "handleArgument.hpp"
#include "../../debugColors.hpp"

u_int16_t handleArgument::getPort(char const *t_av) const
{
    u_int16_t port = DEFAULT_PORT;

    if (t_av != nullptr) {
        try {
            check_if_number(t_av);
            check_if_is_in_range(std::stoi(t_av));
            port = std::stoi(t_av);
        } catch (std::invalid_argument const &e) {
            printError(e.what());
        }
    }
    printInfo("Server is running on port " + (port == DEFAULT_PORT ? std::to_string(port) + " (default)" : std::to_string(port)));
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

void handleArgument::check_if_is_in_range(u_int16_t const &port) const
{
    if (port < MIN_PORT || port > MAX_PORT) {
        throw std::invalid_argument("Invalid argument: port is not in range");
    }
}
