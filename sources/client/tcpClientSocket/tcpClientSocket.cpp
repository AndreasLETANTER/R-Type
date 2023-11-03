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


tcpClientSocket::tcpClientSocket(unsigned int t_tcpPort, ip::address t_ip) : m_socket(m_ioService)
{
    m_endpoint = ip::tcp::endpoint(t_ip, t_tcpPort);
    m_id = 0;
}

tcpClientSocket::~tcpClientSocket()
{
    m_socket.close();
}

void tcpClientSocket::run()
{
    try {
        m_socket.connect(m_endpoint);
        m_ioService.run();
    }
    catch(const std::exception& e) {
        std::cout << "Error while connecting to server" << std::endl;
        exit(84);
    }
}

void tcpClientSocket::send(const std::string &t_message)
{
    boost::system::error_code error;
    boost::asio::write(m_socket, boost::asio::buffer(t_message), error);
    if (error) {
        std::cerr << "Error while sending message: " << error.message() << std::endl;
        return;
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
        return nullptr;
    }
    if (m_id == 0) {
        client_packet_t firstMessage = converter.convertBinaryToInput(m_readBuffer.data());
        m_id = firstMessage.input.id;
        if (m_id >= 5) {
            std::cerr << "Error: Too many clients already connected" << std::endl;
            exit(84);
        }
        printTrace("Received id: " + std::to_string(m_id));
    }
    return m_readBuffer.data();
}
