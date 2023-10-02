/*
** EPITECH PROJECT, 2023
** UdpSocket
** File description:
** to complete
*/

#include <iostream>
#include <atomic>

#include "udpSocket.hpp"
#include "utils/debugColors/debugColors.hpp"

std::atomic<int> nextClientId(1);

udpSocket::udpSocket(u_int16_t t_udpPort, u_int16_t t_tcpPort)
    : m_udpSocket(m_ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), t_udpPort)),
      m_udpPort(t_udpPort),
      m_tcpAcceptor(m_ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), t_tcpPort)),
      m_tcpPort(t_tcpPort) {
}

udpSocket::~udpSocket()
{
    m_ioService.stop();
    m_ioService.reset();
    m_udpSocket.close();
    m_tcpAcceptor.close();
    printTrace("Server stopped");
}

std::string udpSocket::receive() {
    // Implement UDP receive logic here
    return "Received UDP message";
}

void udpSocket::send(const std::string& message) {
    (void)message;
    // Implement UDP send logic here
}

void udpSocket::sendFirstMessage(int clientId, clientInfos clientInfo)
{
    std::string message = "300:id=" + std::to_string(clientId) + "\n";
    clientInfo.tcpSocket->write_some(boost::asio::buffer(message));
}

void udpSocket::acceptClient()
{
    std::shared_ptr<boost::asio::ip::tcp::socket> tcpSocket = std::make_shared<boost::asio::ip::tcp::socket>(m_ioService);
    boost::asio::ip::udp::endpoint udpEndpoint;
    int clientId = nextClientId++;
    clientInfos clientInfo = {tcpSocket, udpEndpoint};

    std::lock_guard<std::mutex> lock(m_mutex);
    m_tcpAcceptor.accept(*tcpSocket);
    m_clients.emplace(clientId, clientInfo);
    m_connectedClients.push_back(clientInfo);
    printTrace("New client connected from " + tcpSocket->remote_endpoint().address().to_string() + ":" + std::to_string(tcpSocket->remote_endpoint().port()));
    printTrace("Number of clients: " + std::to_string(m_clients.size()));
    printTrace("Client ID: " + std::to_string(clientId));
    std::thread([this, tcpSocket, udpEndpoint, clientId]() { clientHandler(clientId, clientInfos{tcpSocket, udpEndpoint}); }).detach();
}

void udpSocket::clientHandler(int clientId, clientInfos clientInfo)
{    
    boost::system::error_code error;
    char buffer[1024];
    try {
        boost::asio::mutable_buffer mutableBuffer(buffer, sizeof(buffer));
        std::size_t bytesRead = clientInfo.tcpSocket->read_some(mutableBuffer, error);

        if (error == boost::asio::error::eof) {
            removeClient(clientId);
        } else if (error) {
            throw boost::system::system_error(error);
        }
        std::string message(buffer, bytesRead);
        printTrace("Received TCP message from " + clientInfo.tcpSocket->remote_endpoint().address().to_string() + ":" + std::to_string(clientInfo.tcpSocket->remote_endpoint().port()) + ": " + message);

        if (clientInfo.firstMessage) {
            clientInfo.firstMessage = false;
            sendFirstMessage(clientId, clientInfo);
        } else {
            clientInfo.tcpSocket->write_some(boost::asio::buffer("200:ok\n"));
        }
    } catch (const std::exception& e) {
        printError(e.what());
    }
}

void udpSocket::start()
{
    startAccept();
    m_ioService.run();
}

void udpSocket::startAccept()
{
    acceptClient();
    std::thread([this]() { startAccept(); }).detach();
}

void udpSocket::removeClient(int clientId)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_clients.erase(clientId);
    printTrace("Client " + std::to_string(clientId) + " disconnected");
    printTrace("Number of clients: " + std::to_string(m_clients.size()));
}
