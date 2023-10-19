/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** udpClientSocket
*/

#pragma once

#include <boost/asio.hpp>

#include "server/udpSocket/udpSocket.hpp"

using namespace boost::asio;

/**
 * @brief The udpClientSocket class represents a UDP client socket that can send and receive messages.
 */
class udpClientSocket {
    public:
        /**
         * @brief Construct a new udpClientSocket object with the specified UDP port.
         * 
         * @param t_udpPort The UDP port to use.
         * @param t_ip The IP address to use.
         */
        udpClientSocket(size_t t_udpPort, ip::address t_ip);

        /**
         * @brief Destroy the udpClientSocket object.
         */
        ~udpClientSocket();

        /**
         * @brief Run the UDP client socket.
         */
        void run();

        /**
         * @brief Send a message through the UDP client socket.
         * 
         * @param t_message The message to send.
         */
        void send(std::vector<char> t_message);

        std::vector<const char *> get_packet_queue();

        /**
         * @brief Receive a message through the UDP client socket.
         * 
         * @return char* The received message.
         */
        void receive();

    private:
        io_service m_ioService; /**< The boost io_service object. */
        ip::udp::socket m_socket; /**< The boost UDP socket object. */
        ip::udp::endpoint m_endpoint; /**< The boost UDP endpoint object. */
        size_t m_udpPort; /**< The UDP port to use. */
        std::vector<const char *> m_packet_queue;
        std::array<char, UDP_PACKET_SIZE> m_readBuffer;
};
