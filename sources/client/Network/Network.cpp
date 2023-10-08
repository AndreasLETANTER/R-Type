/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
**
*/

#include "Network.hpp"
#include <stdexcept>
#include <iostream>

Network::Network(uint16_t port, const char *ipAddress)
{
    m_isCommunicationEnded = false;
    m_clientFd = 0;
    m_status = 0;
    m_ipAddress = ipAddress;
    m_readValue = 0;
    m_port = port;
}

void Network::launchConnection()
{
    createSocket();
    setServerAddress();
    connectToServer();
}

void Network::sendMessageToServer(const std::string& messageToServer) const
{
    int sendReturnValue = send(m_clientFd, messageToServer.c_str(), messageToServer.size(), 0);

    if (sendReturnValue < 0) {
        throw std::invalid_argument("Error : failed to send message \"" + messageToServer + "\" to the server");
    }
    std::cout << "sent: " << messageToServer << std::endl;
}

void Network::closeConnectedSocket() const
{
    if (close(m_clientFd) < 0) {
        throw std::invalid_argument("Error : failed to close the connection");
    }
}

std::string Network::receiveMessageFromServer()
{
    char buffer[1024] = {0};

    m_readValue = read(m_clientFd, buffer, 1024);
    if (m_readValue < 0) {
        throw std::invalid_argument("Error : failed to read on client file descriptor.");
    }
    return buffer;
}

void Network::setCommunicationEnded(bool isCommunicationEnded)
{
    m_isCommunicationEnded = isCommunicationEnded;
}

bool Network::getCommunicationEnded() const
{
    return m_isCommunicationEnded;
}

void Network::createSocket()
{
    m_clientFd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_clientFd < 0) {
        throw std::invalid_argument("Error: socket creation");
    }
}

void Network::setServerAddress()
{
    m_serverAddress.sin_family = AF_INET;
    m_serverAddress.sin_port = htons(m_port);
    if (inet_pton(AF_INET, m_ipAddress, &m_serverAddress.sin_addr) <= 0) {
        throw std::invalid_argument("Error : Invalid IP address");
    }
}

void Network::connectToServer()
{
    m_status = connect(m_clientFd, (struct sockaddr*)&m_serverAddress, sizeof(m_serverAddress));
    if (m_status < 0) {
        throw std::invalid_argument("Error : connection to server failed");
    }
}
