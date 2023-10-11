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
    m_ioServiceThread = std::thread([this]() { m_ioService.run(); });
}
#include <iostream>
void udpSocket::send(std::vector<char> t_message)
{
    try
    {
        m_socket.send_to(buffer(t_message), m_endpoint);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

char *udpSocket::receive()
{
    std::thread([this]() {
        m_readBuffer.fill(0);
        m_socket.receive_from(buffer(m_readBuffer), m_endpoint);
    }).detach();
    return m_readBuffer.data();
}