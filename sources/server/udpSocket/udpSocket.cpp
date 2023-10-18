/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** udpSocket
*/

#include "udpSocket.hpp"
#include "utils/debugColors/debugColors.hpp"
#include <iostream>

udpSocket::udpSocket(int t_udpPort, ip::address t_ip) : m_socket(m_ioService, ip::udp::endpoint(t_ip, t_udpPort))
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
    m_ioService.reset();
    m_ioService.poll();
    try
    {
        m_socket.async_send_to(buffer(t_message), m_endpoint, [](const boost::system::error_code &error, std::size_t bytes_transferred) {
            (void)bytes_transferred;
            if (error)
                throw std::runtime_error(error.message());
        });
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

char *udpSocket::receive()
{
    m_ioService.reset();
    m_ioService.poll();
    m_socket.async_receive_from(buffer(m_readBuffer), m_endpoint, [
    ](const boost::system::error_code &error, std::size_t bytes_transferred) {
            std::cout << GREEN << "Received " << bytes_transferred << " bytes" << RESET << std::endl;
            (void)bytes_transferred;
            if (error)
                throw std::runtime_error(error.message());
        });
    return m_readBuffer.data();
}
