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
        udpClientSocket(unsigned int t_udpPort, ip::address t_ip);
        ~udpClientSocket();

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
         * @return std::vector<packet_t> The packet queue of the UDP client socket.
         */
        std::vector<packet_t> get_packet_queue();

        /**
         * @brief Receive a message through the UDP client socket.
         *
         * @return true If the message was received successfully.
         */
        void receive();

        /**
         * @brief Clears the packet queue.
         */
        void clear_packet_queue();

    private:
        io_service m_ioService;
        ip::udp::socket m_socket;
        ip::udp::endpoint m_endpoint;
        size_t m_udpPort;
        std::vector<packet_t> m_packet_queue;
        streambuf m_readBuffer;
        std::istream m_iStream;
        std::thread udpThread;
        std::mutex m_mutex;
};
