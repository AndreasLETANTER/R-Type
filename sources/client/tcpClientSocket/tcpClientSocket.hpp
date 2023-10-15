/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
**
*/

#pragma once

#include <iostream>
#include <boost/asio.hpp>

#include "server/udpSocket/udpSocket.hpp"

using namespace boost::asio;

/**
 * @brief The Network class represents a TCP socket that can send and receive messages.
 */
/**
 * @brief The tcpClientSocket class represents a TCP client socket.
 * 
 */
class tcpClientSocket {
    public:
        /**
         * @brief Construct a new tcpClientSocket object
         * 
         * @param t_tcpPort The TCP port to connect to.
         */
        tcpClientSocket(u_int16_t t_tcpPort);

        /**
         * @brief Destroy the tcpClientSocket object
         * 
         */
        ~tcpClientSocket();

        /**
         * @brief Run the client socket.
         * 
         */
        void run();

        /**
         * @brief Send a message to the server.
         * 
         * @param t_message The message to send.
         */
        void send(const std::string &t_message);

        /**
         * @brief Receive a message from the server.
         * 
         * @return char* The received message.
         */
        char *receive();

        /**
         * @brief Get the ID of the client socket.
         * 
         * @return unsigned int The ID of the client socket.
         */
        unsigned int getId() const {return m_id;};

        /**
         * @brief Get the UDP port of the client socket.
         * 
         * @return unsigned int The UDP port of the client socket.
         */
        unsigned int getUdpPort() const {return m_udpPort;};
    private:
        unsigned int m_id; /**< The ID of the client socket. */
        io_service m_ioService; /**< The io_service object. */
        ip::tcp::socket m_socket; /**< The TCP socket object. */
        u_int16_t m_tcpPort; /**< The TCP port to connect to. */
        u_int16_t m_udpPort; /**< The UDP port of the client socket. */
        std::array<char, UDP_PACKET_SIZE> m_readBuffer; /**< The read buffer. */
};
