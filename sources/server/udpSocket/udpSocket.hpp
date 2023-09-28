/*
** EPITECH PROJECT, 2023
** Udp socket class
** File description:
** This class send, receive and create the udp connexion
*/

#pragma once

#include <string>
#include <boost/asio.hpp>

/**
 * @brief The udpSocket class represents a UDP socket that can send and receive messages.
 */
class udpSocket {
    public:
        /**
         * @brief Construct a new udpSocket object with the specified port number.
         * @param t_port The port number to bind the socket to.
         */
        udpSocket(u_int16_t t_port);

        /**
         * @brief Destroy the udpSocket object.
         */
        ~udpSocket();

        /**
         * @brief Receive a message from the socket.
         * @return The received message as a string.
         */
        std::string receive();

        /**
         * @brief Send a message through the socket.
         * 
         * @param t_msg The message to send as a string.
         */
        void send(std::string t_msg);

    private:
        boost::asio::io_service m_ioService; ///< The Boost.Asio I/O service object.
        boost::asio::ip::udp::socket m_socket; ///< The Boost.Asio UDP socket object.
};
