#pragma once

#include <boost/asio.hpp>

using namespace boost::asio;

class udpClientSocket {
    public:
        udpClientSocket();
        ~udpClientSocket();
        void run();
        void send(const std::string &t_message);
        char *receive();
    private:
        io_service m_ioService;
        ip::udp::socket m_socket;
        ip::udp::endpoint m_endpoint;
        std::array<char, 1024> m_readBuffer;
};