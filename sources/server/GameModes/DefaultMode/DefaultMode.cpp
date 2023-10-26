/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** DefaultMode
*/

#include "DefaultMode.hpp"
#include <iostream>

void DefaultMode::init()
{
    std::cout << "Initiating Default Mode in multiplayer mode: " << std::boolalpha << m_isMultiplayer << std::endl;
}

void DefaultMode::run()
{
    std::cout << "DefaultMode run" << std::endl;
}
