#pragma once

#include <string>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <map>
#include <thread>
#include <mutex>
#include <memory> // for std::shared_ptr

class udpSocket {
public:
    udpSocket(u_int16_t t_udpPort, u_int16_t t_tcpPort);

    ~udpSocket();

    std::string receive();

    void send(const std::string& message);

    void acceptClient();

    void clientHandler(std::shared_ptr<boost::asio::ip::tcp::socket> tcpSocket, boost::asio::ip::udp::endpoint udpEndpoint);

    void start();

private:
    boost::asio::io_service m_ioService;
    boost::asio::ip::udp::socket m_udpSocket;
    u_int16_t m_udpPort;

    boost::asio::ip::tcp::acceptor m_tcpAcceptor;
    u_int16_t m_tcpPort;
    std::map<std::shared_ptr<boost::asio::ip::tcp::socket>, boost::asio::ip::udp::endpoint> m_clients;
    std::mutex m_mutex;

    void startAccept();
};
