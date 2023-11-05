/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** udpSocket
*/

#include "udpSocket.hpp"
#include <iostream>

udpSocket::udpSocket(int t_udpPort, ip::address t_ip) : m_socket(m_ioService, ip::udp::endpoint(t_ip, t_udpPort)), m_iStream(&m_readBuffer)
{
    m_endpoint = ip::udp::endpoint(ip::udp::v4(), t_udpPort);
    udpThread = std::thread([this]() {
        while (true) {
            receive();
            run();
        }
    });
}

udpSocket::~udpSocket()
{
}

void udpSocket::run()
{
    m_ioService.reset();
    m_ioService.run();
    m_ioService.poll();
}

std::vector<client_packet_t> udpSocket::get_packet_queue()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_packet_queue;
}

void udpSocket::send(std::vector<char> t_message)
{
    for (auto &client : m_clients_endpoints) {
        m_socket.async_send_to(buffer(t_message), client, [](const boost::system::error_code &error, std::size_t bytes_transferred) {
            (void) bytes_transferred;
            if (error) {
                std::cerr << RED << "Error when sending data: " << error.message() << RESET << std::endl;
                return;
            } 
        });
    }
}

void udpSocket::receive()
{
    auto buff = m_readBuffer.prepare(20);
    m_socket.async_receive_from(buff, m_endpoint, [this](const boost::system::error_code &error, std::size_t bytes_transferred) {
        if (error) {
            std::cerr << RED << "Error when receiving data: " << error.message() << RESET << std::endl;
            return;
        }
        if (std::find(m_clients_endpoints.begin(), m_clients_endpoints.end(), m_endpoint) == m_clients_endpoints.end()) {
            m_clients_endpoints.push_back(m_endpoint);
        }
        m_readBuffer.commit(bytes_transferred);
        client_packet_t packet;
        m_iStream.read(reinterpret_cast<char *>(&packet), bytes_transferred);
        m_mutex.lock();
        m_packet_queue.push_back(packet);
        m_mutex.unlock();
        receive();
    });
}

void udpSocket::clear_packet_queue()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_packet_queue.clear();
}
