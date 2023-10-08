#include "udpClientSocket.hpp"


udpClientSocket::udpClientSocket() : m_socket(m_ioService, ip::udp::endpoint(ip::udp::v4(), 0))
{
    m_endpoint = ip::udp::endpoint(ip::address::from_string("127.0.0.1"), 4242);
}

udpClientSocket::~udpClientSocket()
{
}

void udpClientSocket::run()
{
    m_ioService.run();
}

void udpClientSocket::send(const std::string &t_message)
{
    m_socket.send_to(buffer(t_message), m_endpoint);
}

char *udpClientSocket::receive()
{
    m_readBuffer.fill(0);
    m_socket.receive_from(buffer(m_readBuffer), m_endpoint);
    return m_readBuffer.data();
}
