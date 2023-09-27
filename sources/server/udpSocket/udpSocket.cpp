#include <iostream>
#include <cstring>
#include <unistd.h>
#include <bitset>

#include "udpSocket.hpp"
#include "../../binaryConverter/binaryConverter.hpp"
#include "../../debugColors.hpp"

udpSocket::udpSocket(u_int16_t t_port) : m_sockfd(-1) {
    memset(&m_servAddr, 0, sizeof(m_servAddr));
    m_servAddr.sin_port = htons(t_port);
    m_servAddr.sin_family = AF_INET;
    m_servAddr.sin_addr.s_addr = INADDR_ANY;
}

udpSocket::~udpSocket()
{
    close(m_sockfd);
    printTrace("Socket closed");
}

void udpSocket::init(void)
{
    init_socket();
    bind_socket();
}

void udpSocket::init_socket(void)
{
    if ((m_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        throw std::runtime_error("socket creation failed");
    }
    printTrace("Socket created");
}

void udpSocket::bind_socket(void)
{
    if (bind(m_sockfd, (const struct sockaddr *)&m_servAddr, sizeof(m_servAddr)) < 0) {
        throw std::runtime_error("bind failed");
    }
    printTrace("Socket binded");
}

std::string udpSocket::receive(void)
{
    binaryConverter converter;
    socklen_t len;
    int n = -1;
    char buffer[MAXLINE];

    len = sizeof(m_cliAddr);
    n = recvfrom(m_sockfd, buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&m_cliAddr, &len);
    if (n < 0) {
        throw std::runtime_error("recvfrom failed");
    }
    buffer[n] = '\0';
    return converter.binary_to_string(std::string(buffer));
}

void udpSocket::send(std::string t_msg)
{
    binaryConverter converter;

    t_msg = converter.string_to_binary(t_msg);
    sendto(m_sockfd, t_msg.c_str(), t_msg.length(), MSG_CONFIRM, (const struct sockaddr *)&m_cliAddr, sizeof(m_cliAddr));
}
