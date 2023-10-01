/*
** EPITECH PROJECT, 2023
** Colors
** File description:
** This file defines colors for debug messages
*/

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

void printFatalError(std::string const &str);
void printError(std::string const &str);
void printSuccess(std::string const &str);
void printWarning(std::string const &str);
void printInfo(std::string const &str);
void printTrace(std::string const &str);
void printDebug(std::string const &str);