/*
** EPITECH PROJECT, 2023
** Colors
** File description:
** This file defines colors for debug messages
*/

#include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[90m"
#define BOLD_BLACK   "\033[1m\033[30m"
#define BOLD_RED     "\033[1m\033[31m"
#define BOLD_GREEN   "\033[1m\033[32m"
#define BOLD_YELLOW  "\033[1m\033[33m"
#define BOLD_BLUE    "\033[1m\033[34m"
#define BOLD_MAGENTA "\033[1m\033[35m"
#define BOLD_CYAN    "\033[1m\033[36m"
#define BOLD_WHITE   "\033[1m\033[37m"
#define BOLD_GREY    "\033[1m\033[90m"

#define DEBUG true
#define TRACE true

/**
 * @brief Prints a fatal error message with the given string.
 *
 * @param str The string to print as a fatal error message.
 */
void printFatalError(std::string const &str);

/**
 * @brief Prints an error message in red text.
 *
 * @param str The error message to print.
 */
void printError(std::string const &str);

/**
 * @brief Prints a success message in green color.
 *
 * @param str The message to print.
 */
void printSuccess(std::string const &str);

/**
 * @brief Prints a warning message with the given string.
 *
 * @param str The string to print as a warning message.
 */
void printWarning(std::string const &str);

/**
 * @brief Prints an informational message to the console with a specific color.
 *
 * @param str The message to print.
 */
void printInfo(std::string const &str);

/**
 * @brief Prints a trace message with the given string.
 *
 * @param str The string to be printed as a trace message.
 */
void printTrace(std::string const &str);

/**
 * @brief Prints a debug message to the console with a specific color.
 *
 * @param str The message to print.
 */
void printDebug(std::string const &str);