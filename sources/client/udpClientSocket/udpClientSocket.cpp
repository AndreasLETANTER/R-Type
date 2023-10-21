/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** udpClientSocket
*/

#include "udpClientSocket.hpp"
#include <iostream>

udpClientSocket::udpClientSocket(size_t t_udpPort, ip::address t_ip) : m_socket(m_ioService), m_iStream(&m_readBuffer)
{
    m_endpoint = ip::udp::endpoint(t_ip, t_udpPort);
    m_socket.open(ip::udp::v4());
    m_udpPort = t_udpPort;
    udpThread = std::thread([this]() {
        while (true) {
            receive();
            run();
        }
    });
}

udpClientSocket::~udpClientSocket()
{
}

void udpClientSocket::run()
{
    m_ioService.reset();
    m_ioService.run();
    m_ioService.poll();
}

std::vector<packet_t> udpClientSocket::get_packet_queue()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_packet_queue;
}

void udpClientSocket::send(std::vector<char> t_message)
{
    m_socket.async_send_to(buffer(t_message), m_endpoint, [](const boost::system::error_code &error, std::size_t bytes_transferred) {
        std::cout << RED << "Sent " << bytes_transferred << " bytes" << RESET << std::endl;
        if (error) {
            std::cerr << RED << "Error when sending data: " << error.message() << RESET << std::endl;
            return;
        }
    });
}

void udpClientSocket::receive()
{
    auto buff = m_readBuffer.prepare(192);
    m_socket.async_receive_from(buff, m_endpoint, [this](const boost::system::error_code &error, std::size_t bytes_transferred) {
        if (error) {
            std::cerr << RED << "Error when receiving data: " << error.message() << RESET << std::endl;
            return;
        }
        m_readBuffer.commit(bytes_transferred);
        packet_t packet;
        m_iStream.read(reinterpret_cast<char *>(&packet), bytes_transferred);
        std::cout << GREEN << "Received " << bytes_transferred << " bytes" << RESET << std::endl;
        m_mutex.lock();
        m_packet_queue.push_back(packet);
        m_mutex.unlock();
        receive();
    });
}

void udpClientSocket::clear_packet_queue()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_packet_queue.clear();
}
