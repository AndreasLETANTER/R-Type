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


tcpClientSocket::tcpClientSocket(u_int16_t t_tcpPort, ip::address t_ip) : m_socket(m_ioService)
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
    boost::system::error_code error;
    binaryConverter converter;
    m_readBuffer.fill(0);
    boost::asio::read(m_socket, boost::asio::buffer(m_readBuffer), boost::asio::transfer_at_least(1));
    if (error) {
        std::cerr << "Error while receiving message: " << error.message() << std::endl;
    }
    if (m_id == 0) {
        input_t firstMessage = converter.convertBinaryToInput(m_readBuffer.data());
        m_id = firstMessage.id;
        printTrace("Received id: " + std::to_string(m_id));
    }
    return m_readBuffer.data();
}
