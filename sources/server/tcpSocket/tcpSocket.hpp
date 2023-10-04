/*
** EPITECH PROJECT, 2023
** tcpSocket class
** File description:
** This class is used to send and receive messages
*/

#pragma once

#include <map>
#include <thread>
#include <mutex>
#include <memory>
#include <string>

#include <boost/asio.hpp>

using namespace boost::asio;

/**
 * @brief The tcpSocket class represents a UDP socket that can receive and send messages to clients.
 * 
 */
class tcpSocket {
    private:
        io_service m_ioService; /**< The boost asio io service object. */
        ip::tcp::acceptor m_tcpAcceptor; /**< The boost asio TCP acceptor object. */
        ip::tcp::socket m_socket; /**< The boost asio TCP socket object. */
        u_int16_t m_tcpPort; /**< The TCP port number. */
        std::shared_ptr<std::map<int, ip::tcp::socket>> m_clients; /**< The map of connected clients. */
        std::array<char, 1024> m_readBuffer; /**< The buffer used to read data from the socket. */
    public:
        tcpSocket(u_int16_t t_tcpPort);
        ~tcpSocket();
        void startAccept();
        void run();
        void removeClient(int clientId);
        void handleRead(int clientId, std::size_t bytesTransferred);

        /**
         * @brief Receive a message from a client.
         * 
         * @return std::string The received message.
         */
        // std::string receive();

        /**
         * @brief Send a message to all connected clients.
         * 
         * @param message The message to send.
         */
        // void send(const std::string& message);

        /**
         * @brief Accept incoming TCP connections.
         * 
         */
        // void acceptClient();

        /**
         * @brief Remove a client from the connected clients map.
         * 
         * @param clientId The ID of the client to remove.
         */
        // void removeClient(int clientId);
        /**
         * @brief Start the TCP socket.
         * 
         */
        // void start();
};
