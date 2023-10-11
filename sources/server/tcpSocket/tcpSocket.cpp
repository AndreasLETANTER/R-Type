/*
** EPITECH PROJECT, 2023
** tcpSocket
** File description:
** to complete
*/

#include <iostream>
#include <atomic>

#include "tcpSocket.hpp"
#include "utils/debugColors/debugColors.hpp"
#include "utils/binaryConverter/binaryConverter.hpp"

std::atomic<int> nextClientId(1);

tcpSocket::tcpSocket(u_int16_t t_tcpPort)
    : m_ioService(),
    m_tcpAcceptor(m_ioService, ip::tcp::endpoint(ip::tcp::v4(), t_tcpPort)),
    m_socket(m_ioService),
    m_tcpPort(t_tcpPort),
    m_clients(std::make_shared<std::map<int, ip::tcp::socket>>())
{
    printTrace("Server started on port " + std::to_string(m_tcpPort));
    startAccept();
}


tcpSocket::~tcpSocket()
{
    m_ioService.stop();
    m_ioService.reset();
    m_clients->clear();
    m_socket.close();
    m_tcpAcceptor.close();
    printTrace("Server stopped");
}

void tcpSocket::run()
{
    m_ioService.run();
}

void tcpSocket::handleRead(int clientId, std::size_t bytesTransferred)
{
    std::string message(m_readBuffer.data(), bytesTransferred);
    printTrace("Received message from client " + std::to_string(clientId) + ": " + message);
    std::fill(m_readBuffer.begin(), m_readBuffer.end(), 0);
}

void tcpSocket::startRead(int clientId)
{
    auto& clientSocket = m_clients->at(clientId);
    clientSocket.async_read_some(buffer(m_readBuffer),
        [this, clientId](boost::system::error_code ec, std::size_t bytesTransferred) {
            binaryConverter converter;
            if (ec == error::eof) { // Client disconnected
                removeClient(clientId);
            } else if (!ec) {
                handleRead(clientId, bytesTransferred); // Handle the received message
                sendMessage(clientId, converter.convertStructToFirstMessage(clientId));
                startRead(clientId); // Continue reading
            } else {
                printError("Error reading from client " + std::to_string(clientId) + ": " + ec.message());
                removeClient(clientId);
            }
        });
}

void tcpSocket::sendMessage(int clientId, std::vector<char> message)
{
    auto& clientSocket = m_clients->at(clientId);
    clientSocket.async_send(buffer(message),
        [this, clientId](boost::system::error_code ec, std::size_t bytesTransferred) {
            (void)bytesTransferred;
            if (!ec) {
                printTrace("Sent message to client " + std::to_string(clientId));
            } else {
                printError("Error sending message to client " + std::to_string(clientId) + ": " + ec.message());
                removeClient(clientId);
            }
        });
}

void tcpSocket::startAccept()
{
    m_tcpAcceptor.async_accept(m_socket, [this](boost::system::error_code ec) {
        if (!ec) {
            printInfo("New client connected");
            m_clients->insert_or_assign(nextClientId, std::move(m_socket));
            printTrace("Number of clients: " + std::to_string(m_clients->size()));
            ++nextClientId;

            // Start reading from the socket of the newly connected client
            auto clientId = nextClientId - 1;
            startRead(clientId);

            // Continue accepting more clients
            startAccept();
        }
        else {
            // Handle the error condition, if necessary
            printError("Error accepting client: " + ec.message());
        }
    });
}

void tcpSocket::removeClient(int clientId)
{
    m_clients->erase(clientId);
    printTrace("Client " + std::to_string(clientId) + " disconnected");
    printTrace("Number of clients: " + std::to_string(m_clients->size()));
}
