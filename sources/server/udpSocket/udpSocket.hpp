#pragma once

#include <string>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <map>
#include <thread>
#include <mutex>
#include <memory> // for std::shared_ptr

class udpSocket {
private:
    boost::asio::io_service m_ioService;
    boost::asio::ip::udp::socket m_udpSocket;
    u_int16_t m_udpPort;
    struct clientInfos {
        std::shared_ptr<boost::asio::ip::tcp::socket> tcpSocket;
        boost::asio::ip::udp::endpoint udpEndpoint;
        bool firstMessage = true;
    };
    boost::asio::ip::tcp::acceptor m_tcpAcceptor;
    u_int16_t m_tcpPort;
    std::map<int, clientInfos> m_clients;
    std::mutex m_mutex;
    std::vector<clientInfos> m_connectedClients;
    void startAccept();
public:
    udpSocket(u_int16_t t_udpPort, u_int16_t t_tcpPort);

    ~udpSocket();

    std::string receive();

    void send(const std::string& message);

    void acceptClient();

    void removeClient(int clientId);

    void clientHandler(int clientId, clientInfos clientInfo);

    void start();

};
