#include "udpSocket.hpp"
#include "../../debugColors.hpp"
#include <iostream>
#include <atomic>

// Define an atomic variable to manage unique client IDs
std::atomic<int> nextClientId(1);

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
    int clientId = nextClientId++;               // Assign a unique ID to the client
    clientInfos clientInfo = {tcpSocket, udpEndpoint};

    std::lock_guard<std::mutex> lock(m_mutex);

    m_clients.emplace(clientId, clientInfo);
    m_connectedClients.push_back(clientInfo);
    printTrace("New client connected from " + tcpSocket->remote_endpoint().address().to_string() + ":" + std::to_string(tcpSocket->remote_endpoint().port()));
    printTrace("Number of clients: " + std::to_string(m_clients.size()));
    printTrace("Client ID: " + std::to_string(clientId));
    
    // Notify all existing clients about the new connection via UDP
    std::string udpMessage = "New client connected from " + tcpSocket->remote_endpoint().address().to_string() + ":" + std::to_string(tcpSocket->remote_endpoint().port());
    
    std::thread([this, tcpSocket, udpEndpoint, clientId]() { clientHandler(clientId, clientInfos{tcpSocket, udpEndpoint}); }).detach();
    // Start handling the client in a separate thread
}

void udpSocket::clientHandler(int clientId, clientInfos clientInfo) {
    // Implement logic to handle UDP messages for a specific client
    printDebug("je suis dans le clientHandler");
    try {
        std::shared_ptr<boost::asio::ip::tcp::socket> tcpSocket = clientInfo.tcpSocket;
        boost::system::error_code error;
        // mutable buffer is needed because read_some modifies the buffer
        char buffer[1024];
        boost::asio::mutable_buffer mutableBuffer(buffer, sizeof(buffer));
        std::size_t bytesRead = tcpSocket->read_some(mutableBuffer, error);

        if (error == boost::asio::error::eof) {
            // Connection closed by the client
            removeClient(clientId);
            std::cout << "Connection closed by the client" << std::endl;
        } else if (error) {
            throw boost::system::system_error(error);
        }

        // Process the received message
        std::string message(buffer, bytesRead);
        std::cout << "Received TCP message from " << tcpSocket->remote_endpoint().address().to_string() << ":" << tcpSocket->remote_endpoint().port() << ": " << message << std::endl;

        // Send id of the client to the client
        if (clientInfo.firstMessage) {
            clientInfo.firstMessage = false;
            tcpSocket->write_some(boost::asio::buffer("300:id=" + std::to_string(clientId) + "\n"));
        } else {
            // Send the message to the client
            tcpSocket->write_some(boost::asio::buffer("200:ok\n"));
        }
    } catch (const std::exception& e) {
        // Handle exceptions and errors gracefully
        std::cerr << "Error in clientHandler: " << e.what() << std::endl;
    }
    // Clean up and remove the client from the map when done
    // std::lock_guard<std::mutex> lock(m_mutex);
    // m_clients.erase(clientId);
}

void udpSocket::start() {
    startAccept();
    m_ioService.run();
    // print me the connected clients
}

void udpSocket::startAccept() {
    acceptClient();
    std::thread([this]() { startAccept(); }).detach();
}

void udpSocket::removeClient(int clientId) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_clients.erase(clientId);
    printTrace("Client disconnected");
    printTrace("Number of clients: " + std::to_string(m_clients.size()));
}
