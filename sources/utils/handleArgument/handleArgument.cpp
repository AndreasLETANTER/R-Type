/*
** EPITECH PROJECT, 2023
** Handle Argument
** File description:
** The goal of this class is to check is the parameter is valid, else throw error
*/

#include <iostream>

#include "utils/handleArgument/handleArgument.hpp"
#include "utils/debugColors/debugColors.hpp"

uint16_t handleArgument::getPort(char const *t_av) const
{
    uint16_t port = DEFAULT_PORT;

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

boost::asio::ip::address handleArgument::getIp(char const *t_av) const
{
    boost::asio::ip::address ip = boost::asio::ip::address::from_string("0.0.0.0");
    
    if (t_av != nullptr) {
        try {
            std::cout << t_av << std::endl;
            ip = boost::asio::ip::address::from_string(t_av);
        } catch (std::exception const &e) {
            printError(e.what());
        }
    }
    return ip;
}
