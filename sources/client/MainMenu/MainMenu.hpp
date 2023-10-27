/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MainMenu
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "client/Buttons/TextButton/TextButton.hpp"
#include "ECS/Assets/Assets.hpp"
#include "ECS/RegistryClass/Registry.hpp"

/// @brief Class to create the main menu with Play and Quit buttons
class MainMenu {
    public:
        /// @brief Constructor of MainMenu which display a scrolling background and two buttons (Play and Quit)
        /// @param window The window where the main menu will be displayed
        /// @param assets The assets of the game
        MainMenu(sf::RenderWindow &window, Assets &assets, Registry &registry);

        /// @brief Draw the buttons on the window
        void draw();

        /// @brief Update the buttons to check if they are hovered or clicked
        void update();

        /// @brief Resize the buttons to fit the new window size
        void resize();

        void setKey(sf::Keyboard::Key key) { m_keys.push_back(key); };
        std::vector<sf::Keyboard::Key> getKeys() { return m_keys; };

        void resetAndSetSelectedButton(unsigned int index);

    private:
        sf::RenderWindow &m_window;
        Assets &m_assets;
        Registry &m_registry;
        std::vector<TextButton> m_buttons;

        std::vector<sf::Text> m_texts;
        std::vector<sf::Keyboard::Key> m_keys;
        std::vector<bool> m_bools;
        sf::Font m_font;
        bool m_isPlayMenuOpen = false;
};
