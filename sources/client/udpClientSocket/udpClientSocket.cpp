/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** udpClientSocket
*/

#include "udpClientSocket.hpp"
#include "utils/debugColors/debugColors.hpp"

#include <iostream>

udpClientSocket::udpClientSocket(size_t t_udpPort, ip::address t_ip) : m_socket(m_ioService)
{
    m_endpoint = ip::udp::endpoint(t_ip, t_udpPort);
    m_socket.open(ip::udp::v4());
    m_udpPort = t_udpPort;
}

udpClientSocket::~udpClientSocket()
{
}

void udpClientSocket::run()
{
    m_ioService.run();
}

void udpClientSocket::send(std::vector<char> t_message)
{
    m_socket.send_to(buffer(t_message), m_endpoint);
}

char *udpClientSocket::receive()
{
    m_readBuffer.fill(0);
    m_socket.receive_from(buffer(m_readBuffer), m_endpoint);
    return m_readBuffer.data();
}
