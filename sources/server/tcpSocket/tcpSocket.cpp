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
}


void tcpSocket::startAccept()
{
    m_tcpAcceptor.async_accept(m_socket, [this](boost::system::error_code ec) {
        if (!ec) {
            printInfo("New client connected");
            m_clients->insert_or_assign(nextClientId, std::move(m_socket));
            printTrace("Number of clients: " + std::to_string(m_clients->size()));
            ++nextClientId;

            // Start reading from the socket
            auto clientId = nextClientId - 1;
            auto& clientSocket = m_clients->at(clientId);
            clientSocket.async_read_some(buffer(m_readBuffer),
                [this, clientId](boost::system::error_code ec, std::size_t bytesTransferred) {
                    if (ec == error::eof) {
                        removeClient(clientId);
                    } else if (!ec) {
                        // Handle the received data
                        handleRead(clientId, bytesTransferred);
                        auto& clientSocket = m_clients->at(clientId);
                        clientSocket.async_read_some(buffer(m_readBuffer),
                            [this, clientId](boost::system::error_code ec, std::size_t bytesTransferred) {
                                if (ec == error::eof) {
                                    removeClient(clientId);
                                } else if (!ec) {
                                    handleRead(clientId, bytesTransferred);
                                } else {
                                    printError("Error reading from client " + std::to_string(clientId) + ": " + ec.message());
                                    removeClient(clientId);
                                }
                            });
                    } else {
                        printError("Error reading from client " + std::to_string(clientId) + ": " + ec.message());
                        removeClient(clientId);
                    }
                });
        }
        startAccept();
    });
}

void tcpSocket::removeClient(int clientId)
{
    m_clients->erase(clientId);
    printTrace("Client " + std::to_string(clientId) + " disconnected");
    printTrace("Number of clients: " + std::to_string(m_clients->size()));
}
