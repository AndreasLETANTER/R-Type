#include "udpSocket.hpp"
#include "../../debugColors.hpp"
#include <iostream>

udpSocket::udpSocket(u_int16_t t_udpPort, u_int16_t t_tcpPort)
    : m_udpSocket(m_ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), t_udpPort)),
      m_udpPort(t_udpPort),
      m_tcpAcceptor(m_ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), t_tcpPort)),
      m_tcpPort(t_tcpPort) {
}

udpSocket::~udpSocket() {
}

std::string udpSocket::receive() {
    // Implement UDP receive logic here
    return "Received UDP message";
}

void udpSocket::send(const std::string& message) {
    (void)message;
    // Implement UDP send logic here
}

void udpSocket::acceptClient() {
    std::shared_ptr<boost::asio::ip::tcp::socket> tcpSocket = std::make_shared<boost::asio::ip::tcp::socket>(m_ioService);
    m_tcpAcceptor.accept(*tcpSocket);

    // Implement logic to receive the UDP endpoint from the client
    // This can involve a separate handshake or protocol

    boost::asio::ip::udp::endpoint udpEndpoint;  // Obtain the UDP endpoint from the client

    std::lock_guard<std::mutex> lock(m_mutex);
    m_clients.emplace(tcpSocket, udpEndpoint);
    printTrace("New client connected from " + tcpSocket->remote_endpoint().address().to_string() + ":" + std::to_string(tcpSocket->remote_endpoint().port()));
    printTrace("Number of clients: " + std::to_string(m_clients.size()));
    // Start handling the client in a separate thread
    std::thread([this, tcpSocket, udpEndpoint]() { clientHandler(tcpSocket, udpEndpoint); }).detach();
}

void udpSocket::clientHandler(std::shared_ptr<boost::asio::ip::tcp::socket> tcpSocket, boost::asio::ip::udp::endpoint udpEndpoint) {
    // Implement logic to handle UDP messages for a specific client
    printDebug("je suis dans le clientHandler");
    while (true) {
        try {
            // Receive UDP messages from the client
            char buffer[1024];
            std::size_t len = m_udpSocket.receive_from(boost::asio::buffer(buffer, sizeof(buffer)), udpEndpoint);

            // Process and handle the received UDP message
            std::string udpMessage(buffer, len);
            printTrace("Received UDP message from " + udpEndpoint.address().to_string() + ":" + std::to_string(udpEndpoint.port()) + ": " + udpMessage);

            // Example: Send a response back to the client
            std::string response = "Received UDP message: " + udpMessage;
            m_udpSocket.send_to(boost::asio::buffer(response), udpEndpoint);
        } catch (const std::exception& e) {
            // Handle exceptions and errors gracefully
            std::cerr << "Error in clientHandler: " << e.what() << std::endl;
            break;
        }
    }

    // Clean up and remove the client from the map when done
    std::lock_guard<std::mutex> lock(m_mutex);
    m_clients.erase(tcpSocket);
}

void udpSocket::start() {
    startAccept();
    m_ioService.run();
}

void udpSocket::startAccept() {
    acceptClient();
    std::thread([this]() { startAccept(); }).detach();
}
