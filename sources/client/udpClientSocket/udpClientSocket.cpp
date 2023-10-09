#include "udpClientSocket.hpp"
#include "utils/debugColors/debugColors.hpp"

udpClientSocket::udpClientSocket(size_t t_udpPort) : m_socket(m_ioService, ip::udp::endpoint(ip::udp::v4(), 0))
{
    m_endpoint = ip::udp::endpoint(ip::address::from_string("127.0.0.1"), t_udpPort);
    m_udpPort = t_udpPort;
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
    // check if port is open before sending
    m_socket.send_to(buffer(t_message), m_endpoint);
}

char *udpClientSocket::receive()
{
    m_readBuffer.fill(0);
    m_socket.receive_from(buffer(m_readBuffer), m_endpoint);
    return m_readBuffer.data();
}
