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

class udpSocket {
    public:
        udpSocket(int t_udpPort);
        ~udpSocket();
        void run();
        void send(std::vector<char> t_message);
        char *receive();
    private:
        io_service m_ioService;
        ip::udp::socket m_socket;
        ip::udp::endpoint m_endpoint;
        std::array<char, UDP_PACKET_SIZE> m_readBuffer;
        std::thread m_ioServiceThread;
};
