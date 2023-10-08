/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Systems/ScrollSystem/ScrollSystem.hpp"
#include "client/MainMenu/MainMenu.hpp"
#include "client/Network/Network.hpp"
#include "client/ArgumentsHandling/ArgumentsHandling.hpp"

#include "client/tcpClientSocket/tcpClientSocket.hpp"

void signalHandler(int signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    exit(signum);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    tcpClientSocket client(8080);
    client.run();
    std::string message = "Hello from client";
    client.send(message);
    char *buffer = client.receive();
    std::cout << "buffer: " << buffer << std::endl;
    return 0;
}
