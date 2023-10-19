/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** udpClientSocket
*/

#include "udpClientSocket.hpp"
#include "utils/debugColors/debugColors.hpp"

#include "utils/binaryConverter/binaryConverter.hpp"

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

std::vector<const char *> udpClientSocket::get_packet_queue()
{
    return m_packet_queue;
}

void udpClientSocket::send(std::vector<char> t_message)
{
    m_ioService.reset();
    m_ioService.poll();
    m_socket.async_send_to(buffer(t_message), m_endpoint, [](const boost::system::error_code &error, std::size_t bytes_transferred) {
        (void)bytes_transferred;
        std::cout << RED << "Sent " << bytes_transferred << " bytes" << RESET << std::endl;
        if (error) {
            std::cerr << RED << "Error: " << error.message() << RESET << std::endl;
        }
    });
}

void udpClientSocket::receive()
{
    m_ioService.reset();
    m_ioService.poll();
    m_socket.async_receive_from(buffer(m_readBuffer), m_endpoint, [this](const boost::system::error_code &error, std::size_t bytes_transferred) {
        (void)bytes_transferred;
        binaryConverter converter;

        std::cout << "received message type; " << converter.convertBinaryToStruct(m_readBuffer.data()).message.sprite_name << std::endl;
        std::cout << GREEN << "Received " << bytes_transferred << " bytes" << RESET << std::endl;
        if (error && error != boost::asio::error::message_size) {
            std::cerr << RED << "Error: " << error.message() << RESET << std::endl;
        }
        m_packet_queue.push_back(m_readBuffer.data());
        receive();
    });
}
