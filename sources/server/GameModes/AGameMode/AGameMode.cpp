/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AGameMode
*/

#include "AGameMode.hpp"

AGameMode::AGameMode(const char **av, int ac, bool isMultiplayer)
{
    (void) av;
    (void) ac;
    m_isMultiplayer = isMultiplayer;
}
