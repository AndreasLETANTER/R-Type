/*
** EPITECH PROJECT, 2023
** Server
** File description:
** Server main
*/

#include <iostream>

#include "handleArgument/handleArgument.hpp"
#include "udp/udp.hpp"

int main(int ac, char **av)
{
    handleArgument handleArgument;
    Udp udp(handleArgument.getPort(av[1]));

    try {
        udp.init();
        while (true) {
            std::cout << udp.receive() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
