#include "udpSocket.hpp"
#include "utils/debugColors/debugColors.hpp"

udpSocket::udpSocket(int t_udpPort) : m_socket(m_ioService, ip::udp::endpoint(ip::udp::v4(), t_udpPort))
{
    m_endpoint = ip::udp::endpoint(ip::udp::v4(), t_udpPort);
    printTrace("UDP socket created on port " + std::to_string(t_udpPort));
}

udpSocket::~udpSocket()
{
}

void udpSocket::run()
{
    m_ioService.run();
}

void udpSocket::send(std::vector<char> t_message)
{
    m_socket.send_to(buffer(t_message), m_endpoint);
}

char *udpSocket::receive()
{
    m_readBuffer.fill(0);
    m_socket.receive_from(buffer(m_readBuffer), m_endpoint);
    return m_readBuffer.data();
}