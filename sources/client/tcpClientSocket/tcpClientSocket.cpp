/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
**
*/

#include "tcpClientSocket.hpp"
#include <iostream>
#include "utils/binaryConverter/binaryConverter.hpp"
#include "utils/debugColors/debugColors.hpp"


tcpClientSocket::tcpClientSocket(u_int16_t t_tcpPort, ip::address t_ip) : m_socket(m_ioService), m_tcpPort(t_tcpPort)
{
    ip::tcp::endpoint endpoint(t_ip, t_tcpPort);
    m_socket.connect(endpoint);
    m_id = 0;
}

tcpClientSocket::~tcpClientSocket()
{
    m_socket.close();
}

void tcpClientSocket::run()
{
    m_ioService.run();
}

void tcpClientSocket::send(const std::string &t_message)
{
    boost::system::error_code error;
    boost::asio::write(m_socket, boost::asio::buffer(t_message), error);
    if (error) {
        std::cerr << "Error while sending message: " << error.message() << std::endl;
    }
}

char *tcpClientSocket::receive()
{
    std::thread([this]() {
        boost::system::error_code error;
        binaryConverter converter;
        m_readBuffer.fill(0);
        boost::asio::read(m_socket, boost::asio::buffer(m_readBuffer), boost::asio::transfer_at_least(1));
        if (error) {
            std::cerr << "Error while receiving message: " << error.message() << std::endl;
        }
    if (m_id == 0) {
        t_first_message firstMessage = converter.convertBinaryToFirstMessage(m_readBuffer.data());
        m_id = firstMessage.id;
        m_udpPort = firstMessage.udp_port;
        printTrace("Received id: " + std::to_string(m_id));
        printTrace("Received udp port: " + std::to_string(m_udpPort));
    }
    }).detach();
    return m_readBuffer.data();
}
