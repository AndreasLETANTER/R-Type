#include "udpSocket/udpSocket.hpp"
#include "handleArgument/handleArgument.hpp"


int main(int ac, char **av)
{
    (void)ac;
    handleArgument handleArgument;
    udpSocket server(handleArgument.getPort(av[1]), handleArgument.getPort(av[2]));

    while (true) {
        server.start();
    }
    return 0;
}
