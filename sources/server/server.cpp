/*
** EPITECH PROJECT, 2023
** Server
** File description:
** Server main
*/

#include <iostream>

#include "handleArgument/handleArgument.hpp"
#include "udpSocket/udpSocket.hpp"

int main(int ac, char **av)
{
    handleArgument handleArgument;
    udpSocket udp(handleArgument.getPort(av[1]));

    try {
        while (true) {
            udp.receive();
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
