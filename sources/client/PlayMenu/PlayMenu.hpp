/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** PlayMenu
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "client/Buttons/TextButton/TextButton.hpp"
#include "ECS/Assets/Assets.hpp"
#include "ECS/RegistryClass/Registry.hpp"

class PlayMenu {
public:
    PlayMenu(sf::RenderWindow &window, Assets &assets, Registry &registry);
    void draw();
    void update();
    void resize();
private:
    sf::RenderWindow &m_window;
    Assets &m_assets;
    Registry &m_registry;
    std::vector<TextButton> m_buttons;
    sf::Font m_font;
};
