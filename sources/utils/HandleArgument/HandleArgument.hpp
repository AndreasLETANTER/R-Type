/*
** EPITECH PROJECT, 2023
** Handle Argument
** File description:
** The goal of this class is to check is the parameter is valid, else throw error
*/

#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <boost/asio.hpp>

#define MAX_PORT 65535
#define MIN_PORT 1024
#define DEFAULT_PORT 8080

#define VAL(x) #x
#define TOSTRING(str) VAL(str)

class HandleArgument
/**
 * @brief Class for handling command line argument.
 */
{
    public:
        /**
         * @brief Default constructor.
         */
        HandleArgument(void) = default;
        /**
         * @brief Default destructor.
         */
        ~HandleArgument(void) = default;
        /**
         * @brief Get the port number from the command line arguments.
         * @param t_av The command line arguments.
         * @return The port number.
         */
        uint16_t getPort(char const *t_av) const;
        /**
         * @brief Get the IP address from the command line arguments.
         * @param t_av The command line arguments.
         * @return The IP address.
         */
        boost::asio::ip::address getIp(char const *t_av) const;

    protected:
        /**
         * @brief Check if a string is a number.
         * @param str The string to check.
         * @throw std::invalid_argument If the string is not a number.
         */
        void check_if_number(std::string const &str) const;
};
