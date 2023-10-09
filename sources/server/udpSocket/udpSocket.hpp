#pragma once

#include <boost/asio.hpp>

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
        u_int16_t m_udpPort;
        std::array<char, 1024> m_readBuffer;
};