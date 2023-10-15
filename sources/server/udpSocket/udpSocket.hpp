/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** udpSocket
*/

#pragma once

#include <boost/asio.hpp>

#define UDP_PACKET_SIZE 65535

using namespace boost::asio;

/**
 * @brief The udpSocket class represents a UDP socket that can send and receive messages.
 */
class udpSocket {
    public:
        /**
         * @brief Construct a new udpSocket object with the specified UDP port.
         * 
         * @param t_udpPort The UDP port to use.
         */
        udpSocket(int t_udpPort, ip::address t_ip);

        /**
         * @brief Destroy the udpSocket object.
         */
        ~udpSocket();

        /**
         * @brief Start the io_service thread.
         */
        void run();

        /**
         * @brief Send a message through the UDP socket.
         * 
         * @param t_message The message to send.
         */
        void send(std::vector<char> t_message);

        /**
         * @brief Receive a message from the UDP socket.
         * 
         * @return char* The received message.
         */
        char *receive();

    private:
        io_service m_ioService; /**< The io_service used by the socket. */
        ip::udp::socket m_socket; /**< The UDP socket. */
        ip::udp::endpoint m_endpoint; /**< The endpoint of the socket. */
        std::array<char, UDP_PACKET_SIZE> m_readBuffer; /**< The buffer used to read messages. */
        std::thread m_ioServiceThread; /**< The thread used to run the io_service. */
};
