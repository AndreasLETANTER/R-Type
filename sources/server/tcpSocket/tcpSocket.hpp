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

#include "server/udpSocket/udpSocket.hpp"

using namespace boost::asio;

/**
 * @brief The tcpSocket class represents a TCP socket server that accepts incoming connections from clients.
 */
class tcpSocket {
    private:
        io_service m_ioService; /**< The boost asio io service object. */
        ip::tcp::acceptor m_tcpAcceptor; /**< The boost asio TCP acceptor object. */
        ip::tcp::socket m_socket; /**< The boost asio TCP socket object. */
        std::shared_ptr<std::map<int, ip::tcp::socket>> m_clients; /**< The map of connected clients. */
        std::array<char, UDP_PACKET_SIZE> m_readBuffer; /**< The buffer used to read data from the socket. */
        std::thread m_ioServiceThread; /**< The thread used to run the io service object. */
    public:
        /**
         * @brief Construct a new tcpSocket object with the specified TCP port number.
         * 
         * @param t_tcpPort The TCP port number.
         * @param t_ip The IP address to use.
         */
        tcpSocket(u_int16_t t_tcpPort, boost::asio::ip::address t_ip);

        /**
         * @brief Destroy the tcpSocket object.
         */
        ~tcpSocket();

        /**
         * @brief Start accepting incoming connections from clients.
         */
        void startAccept();

        /**
         * @brief Run the TCP socket server.
         */
        void run();

        /**
         * @brief Remove a client from the map of connected clients.
         * 
         * @param clientId The ID of the client to remove.
         */
        void removeClient(int clientId);

        /**
         * @brief Handle the read operation for a client.
         * 
         * @param clientId The ID of the client.
         * @param bytesTransferred The number of bytes transferred.
         */
        void handleRead(int clientId, std::size_t bytesTransferred);

        /**
         * @brief Start reading data from a client.
         * 
         * @param clientId The ID of the client.
         */
        void startRead(int clientId);

        /**
         * @brief Send a message to a client.
         * 
         * @param clientId The ID of the client.
         * @param message The message to send.
         */
        void sendMessage(int clientId, std::vector<char> message);

        unsigned int getNbClients() const {return m_clients->size();};
};
