/*
** EPITECH PROJECT, 2023
** udpSocket class
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
#include <boost/asio/steady_timer.hpp>

/**
 * @brief The udpSocket class represents a UDP socket that can receive and send messages to clients.
 * 
 */
class udpSocket {
    private:
        boost::asio::io_service m_ioService; /**< The boost asio io service object. */
        boost::asio::ip::udp::socket m_udpSocket; /**< The boost asio UDP socket object. */
        u_int16_t m_udpPort; /**< The UDP port number. */
        struct clientInfos {
            std::shared_ptr<boost::asio::ip::tcp::socket> tcpSocket; /**< The boost asio TCP socket object. */
            boost::asio::ip::udp::endpoint udpEndpoint; /**< The boost asio UDP endpoint object. */
            bool firstMessage = true; /**< A boolean indicating if it is the first message received from the client. */
        };
        boost::asio::ip::tcp::acceptor m_tcpAcceptor; /**< The boost asio TCP acceptor object. */
        u_int16_t m_tcpPort; /**< The TCP port number. */
        std::map<int, clientInfos> m_clients; /**< A map of connected clients. */
        std::mutex m_mutex; /**< A mutex to protect the access to the connected clients map. */
        std::vector<clientInfos> m_connectedClients; /**< A vector of connected clients. */
        /**
         * @brief Start accepting incoming TCP connections.
         * 
         */
        void startAccept();
    public:
        /**
         * @brief Construct a new udpSocket object.
         * 
         * @param t_udpPort The UDP port number.
         * @param t_tcpPort The TCP port number.
         */
        udpSocket(u_int16_t t_udpPort, u_int16_t t_tcpPort);

        /**
         * @brief Destroy the udpSocket object.
         * 
         */
        ~udpSocket();

        /**
         * @brief Receive a message from a client.
         * 
         * @return std::string The received message.
         */
        std::string receive();

        /**
         * @brief Send a message to all connected clients.
         * 
         * @param message The message to send.
         */
        void send(const std::string& message);

        /**
         * @brief Send the first message to a newly connected client.
         * 
         * @param clientId The ID of the client.
         * @param clientInfo The client information.
         */
        void sendFirstMessage(int clientId, clientInfos clientInfo);

        /**
         * @brief Accept incoming TCP connections.
         * 
         */
        void acceptClient();

        /**
         * @brief Remove a client from the connected clients map.
         * 
         * @param clientId The ID of the client to remove.
         */
        void removeClient(int clientId);

        /**
         * @brief Handle a client.
         * 
         * @param clientId The ID of the client to handle.
         * @param clientInfo The client information.
         */
        void clientHandler(int clientId, clientInfos clientInfo);

        /**
         * @brief Start the UDP and TCP sockets.
         * 
         */
        void start();
};
