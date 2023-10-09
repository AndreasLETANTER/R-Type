/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
**
*/

#pragma once

#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

/**
 * @brief The Network class represents a TCP socket that can send and receive messages.
 */
class tcpClientSocket {
    public:
        tcpClientSocket(u_int16_t t_tcpPort);
        ~tcpClientSocket();
        void run();
        void send(const std::string &t_message);
        char *receive();
        unsigned int getId() const {return m_id;};
        unsigned int getUdpPort() const {return m_udpPort;};
    private:
        unsigned int m_id;
        io_service m_ioService;
        ip::tcp::socket m_socket;
        u_int16_t m_tcpPort;
        u_int16_t m_udpPort;
        std::array<char, 4096> m_readBuffer;  
};