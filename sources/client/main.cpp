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
#include "client/udpClientSocket/udpClientSocket.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"

void signalHandler(int signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    exit(signum);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    binaryConverter converter;
    udpClientSocket udpClient(4242);
    // tcpClientSocket client(8080);
    // client.run();

    // client.send("zizi");
    // while (client.getId() == 0) {
    //     client.receive();
    // }
    udpClient.run();
    udpClient.send("connect");

    while (true) {
        message_t *messages = converter.convertBinaryToStruct(udpClient.receive());
        std::cout << "message: " << messages[0].sprite_name << std::endl;
        (void)messages;
        // load messages in registry with export function
    }
    return 0;
}
