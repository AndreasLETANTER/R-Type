/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** udpSocket
*/

#pragma once

#include "utils/debugColors/debugColors.hpp"

#include "utils/binaryConverter/binaryConverter.hpp"
#include "ECS/RegistryClass/Registry.hpp"

#include <boost/asio.hpp>

#include "server/udpSocket/udpSocket.hpp"

#define UDP_PACKET_SIZE 65507
#define TICKRATE 64

using namespace boost::asio;

/**
 * @brief The udpSocket class represents a UDP client socket that can send and receive messages.
 */
/**
 * @file udpSocket.hpp
 * @brief Defines the udpSocket class.
 */

/**
 * @class udpSocket
 * @brief Represents a UDP socket.
 * 
 * This class provides methods to construct, send and receive messages through a UDP socket.
 * It also provides a packet queue to store received packets.
 */
class udpSocket {
    public:
        /**
         * @brief Construct a new udpSocket object with the specified UDP port.
         * 
         * @param t_udpPort The UDP port to use.
         * @param t_ip The IP address to use.
         */
        udpSocket(int t_udpPort, ip::address t_ip);

        /**
         * @brief Destroy the udpSocket object.
         */
        ~udpSocket();

        /**
         * @brief Run the UDP client socket.
         */
        void run();

        /**
         * @brief Send a message through the UDP client socket.
         * 
         * @param t_message The message to send.
         * @return true If the message was sent successfully.
         */
        void send(std::vector<char> t_message);

        /**
         * @brief Returns the packet queue of the UDP client socket.
         * 
         * @return std::vector<input_t> The packet queue of the UDP client socket.
         */
        std::vector<input_t> get_packet_queue();

        /**
         * @brief Receive a message through the UDP client socket.
         * 
         * @return true If the message was received successfully.
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
        std::vector<ip::udp::endpoint> m_clients_endpoints; /**< The map of connected clients. */
        std::vector<input_t> m_packet_queue; /**< The packet queue of the UDP client socket. */
        streambuf m_readBuffer; /**< The boost streambuf object. */
        std::istream m_iStream; /**< The boost istream object. */
        std::thread udpThread; /**< The thread object for the UDP client socket. */
        std::mutex m_mutex; /**< The mutex object for the packet queue. */
};
