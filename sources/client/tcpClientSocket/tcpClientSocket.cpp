/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
**
*/

#include "tcpClientSocket.hpp"
#include <iostream>
#include "utils/binaryConverter/binaryConverter.hpp"


tcpClientSocket::tcpClientSocket(u_int16_t t_tcpPort) : m_socket(m_ioService), m_tcpPort(t_tcpPort)
{
    ip::tcp::endpoint endpoint(ip::tcp::v4(), m_tcpPort);
    m_socket.connect(endpoint);
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
    m_readBuffer.fill(0);
    // read the async_send message
    boost::asio::read(m_socket, boost::asio::buffer(m_readBuffer), boost::asio::transfer_at_least(1), error);
    if (error) {
        std::cerr << "Error while receiving message: " << error.message() << std::endl;
    }
    binaryConverter converter;
    m_id = converter.convertBinaryToFirstMessage(m_readBuffer.data());
    return m_readBuffer.data();
}
