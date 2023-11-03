/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ButtonFactory
*/

#include <stdexcept>

#include "client/Buttons/ButtonFactory/ButtonFactory.hpp"

std::unique_ptr<IButton> ButtonFactory::createButton(const std::string &buttonType)
{
    if (m_buttonsType.find(buttonType) == m_buttonsType.end())
        throw std::runtime_error("ButtonFactory: Button not found");
    return m_buttonsType[buttonType]();
}
