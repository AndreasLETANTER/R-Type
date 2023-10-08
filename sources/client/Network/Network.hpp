/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
**
*/

#pragma once
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <csignal>

/**
 * @brief The Network class represents a TCP socket that can send and receive messages.
 */
class Network {
public:
    /**
     * @brief Construct a new Network object.
     */
    Network() = default;
    /**
     * @brief Construct a new Network object with the specified port number and IP address.
     * @param port The port number to bind the socket to.
     * @param ipAddress The IP address to connect to.
     */
    Network(uint16_t port, const char* ipAddress);
    /**
     * @brief Launch the connection to the server.
     */
    void launchConnection();
    /**
     * @brief Send a message to the server.
     * @param messageToServer The message to send to the server.
     */
    void sendMessageToServer(const std::string& messageToServer) const;
    /**
     * @brief Close the connected socket.
     */
    void closeConnectedSocket() const;
    /**
     * @brief Receive a message from the server.
     * @return The message received from the server.
     */
    std::string receiveMessageFromServer();
    /**
     * @brief Set the m_isCommunicationEnded boolean.
     * @param isCommunicationEnded The boolean to set.
     */
    void setCommunicationEnded(bool isCommunicationEnded);
    /**
     * @brief Get the m_isCommunicationEnded boolean.
     * @return The m_isCommunicationEnded boolean.
     */
    bool getCommunicationEnded() const;
    /**
     * @brief Destroy the Network object.
     */
    ~Network() = default;
private:
    /**
     * @brief Create a socket.
     */
    void createSocket();
    /**
     * @brief Set the server address.
     */
    void setServerAddress();
    /**
     * @brief Connect to the server.
     */
    void connectToServer();
    bool m_isCommunicationEnded;
    int m_clientFd;
    int m_status;
    const char *m_ipAddress = "127.0.0.1";
    ssize_t m_readValue;
    uint16_t m_port;
    sockaddr_in m_serverAddress{};
};
