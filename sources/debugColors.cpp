#include <iostream>

#include "debugColors.hpp"

void printFatalError(std::string const &str)
{
    std::cout << BOLD_RED << str << RESET << std::endl;
}

void printError(std::string const &str)
{
    std::cerr << RED << str << RESET << std::endl;
}

void printSuccess(std::string const &str)
{
    std::cout << GREEN << str << RESET << std::endl;
}

void printWarning(std::string const &str)
{
    std::cout << YELLOW << str << RESET << std::endl;
}

void printInfo(std::string const &str)
{
    std::cout << BLUE << str << RESET << std::endl;
}

void printTrace(std::string const &str)
{
    if (!TRACE)
        return;
    std::cout << GREY << str << RESET << std::endl;
}

void printDebug(std::string const &str)
{
    if (!DEBUG)
        return;
    std::cout << MAGENTA << str << RESET << std::endl;
}