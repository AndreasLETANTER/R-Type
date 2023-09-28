#include "udpSocket.hpp"
#include "../../debugColors.hpp"
#include "../../binaryConverter/binaryConverter.hpp"
#include <boost/array.hpp>
#include <boost/system/system_error.hpp>

#define MAXLINE 1024

udpSocket::udpSocket(u_int16_t t_port) :
m_socket(m_ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), t_port))
{
    printInfo("Server is running on port " + std::to_string(t_port));
}

udpSocket::~udpSocket()
{
    m_socket.close();
    printTrace("Socket closed");
}

std::string udpSocket::receive()
{
    binaryConverter converter;
    boost::array<char, MAXLINE> buffer;
    boost::asio::ip::udp::endpoint senderEndpoint;
    boost::system::error_code error;
    std::string msg;

    try {
        m_socket.receive_from(boost::asio::buffer(buffer), senderEndpoint, 0, error);
        if (error)
            throw boost::system::system_error(error);
        msg = converter.binary_to_string(buffer.data());
    } catch (const std::exception &e) {
        printError(e.what());
    }
    printSuccess("Message received from " + senderEndpoint.address().to_string() + ":" + std::to_string(senderEndpoint.port()));
    printSuccess("Message: " + msg);
    return msg;
}

void udpSocket::send(std::string t_msg)
{
    binaryConverter converter;
    boost::asio::ip::udp::endpoint receiverEndpoint = m_socket.remote_endpoint();
    boost::system::error_code error;

    try {
        m_socket.send_to(boost::asio::buffer(converter.string_to_binary(t_msg)), receiverEndpoint, 0, error);
        if (error)
            throw boost::system::system_error(error);
    } catch (const std::exception &e) {
        printError(e.what());
    }
    printSuccess("Message sent to " + receiverEndpoint.address().to_string() + ":" + std::to_string(receiverEndpoint.port()));
    printSuccess("Message: " + t_msg);
}
