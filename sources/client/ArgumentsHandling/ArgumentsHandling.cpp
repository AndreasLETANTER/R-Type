/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** handle client arguments
*/

#include <iostream>
#include <cstring>
#include "ArgumentsHandling.hpp"

int handleArguments(int ac, char **av)
{
    std::string usageMessage = "Usage: ./r-type_client <port> <ip_address>";
    unsigned long port;

    for (int i = 0; i < ac; i++) {
        if ((av[i][0] == '-' && av[i][1] == 'h') || (strcmp(av[i], "--help") == 0)) {
            std::cerr << usageMessage << std::endl;
            exit(0);
        }
    }
    if (ac != 3) {
        std::cerr << usageMessage << std::endl;
        return (84);
    }
    port = strtoul(av[1], nullptr, 10);
    if (port == 0 || port > 65535) {
        std::cerr << "Error: invalid port number" << std::endl;
        return (84);
    }
    return (0);
}
