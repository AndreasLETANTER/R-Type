/*
** EPITECH PROJECT, 2023
** Upd class
** File description:
** This class init, bind and function to receive, send
*/

#include <netinet/in.h>
#include <string>

#define MAXLINE 1024

/**
 * @brief The udpSocket class provides an interface to create and manage a udpSocket socket.
 */
class udpSocket {
    public:
        /**
         * @brief Constructs a udpSocket object with the specified port number.
         * @param t_port The port number to bind the socket to.
         */
        udpSocket(u_int16_t t_port);

        /**
         * @brief Destroys the udpSocket object and closes the socket.
         */
        ~udpSocket();

        /**
         * @brief Initializes the socket and binds it to the specified port.
         */
        void init(void);

        /**
         * @brief Receives a message from the socket.
         * @return The received message as a string.
         */
        std::string receive(void);

        /**
         * @brief Sends a message through the socket.
         * @param t_msg The message to send as a string.
         */
        void send(std::string t_msg);

    protected:
        /**
         * @brief Initializes the socket.
         */
        void init_socket(void);

        /**
         * @brief Binds the socket to the specified port.
         */
        void bind_socket(void);

    private:
        int m_sockfd; /**< The socket file descriptor. */
        struct sockaddr_in m_servAddr; /**< The server address. */
        struct sockaddr_in m_cliAddr; /**< The client address. */
};
