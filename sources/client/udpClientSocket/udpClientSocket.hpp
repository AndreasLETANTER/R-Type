/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** udpClientSocket
*/

#pragma once

#include "utils/debugColors/debugColors.hpp"

#include "utils/binaryConverter/binaryConverter.hpp"
#include "ECS/RegistryClass/Registry.hpp"

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

        /**
         * @brief Returns the packet queue of the UDP client socket.
         * 
         * @return std::vector<packet_t> The packet queue of the UDP client socket.
         */
        std::vector<packet_t> get_packet_queue();

        /**
         * @brief Receive a message through the UDP client socket.
         * 
         * @return char* The received message.
         */
        void receive();

        /**
         * @brief Clears the packet queue.
         * 
         * This function removes all packets from the queue, freeing up memory and ensuring
         * that the queue is empty.
         */
        void clear_packet_queue();

    private:
        io_service m_ioService; /**< The boost io_service object. */
        ip::udp::socket m_socket; /**< The boost UDP socket object. */
        ip::udp::endpoint m_endpoint; /**< The boost UDP endpoint object. */
        size_t m_udpPort; /**< The UDP port to use. */
        std::vector<packet_t> m_packet_queue;
        streambuf m_readBuffer;
        std::istream m_iStream;
};
