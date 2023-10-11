#pragma once

#include <boost/asio.hpp>

#include "server/udpSocket/udpSocket.hpp"

using namespace boost::asio;

class udpClientSocket {
    public:
        udpClientSocket(size_t t_udpPort);
        ~udpClientSocket();
        void run();
        void send(const std::string &t_message);
        char *receive();
    private:
        io_service m_ioService;
        ip::udp::socket m_socket;
        ip::udp::endpoint m_endpoint;
        size_t m_udpPort;
        std::array<char, UDP_PACKET_SIZE> m_readBuffer;
};
