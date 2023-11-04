/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MainMenu
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <boost/asio.hpp>

#include "client/Buttons/OneUseButton/OneUseButton.hpp"
#include "ECS/Assets/Assets.hpp"
#include "ECS/RegistryClass/Registry.hpp"
#include "client/Buttons/ButtonFactory/ButtonFactory.hpp"

using namespace boost::asio;

/**
 * @brief Class to create the main menu with Play and Quit buttons
 */
class MainMenu {
    public:
        /**
         * @brief Constructs a MainMenu object.
         *
         * @param window The SFML RenderWindow to draw the MainMenu on.
         * @param assets The Assets object containing all game assets.
         * @param registry The entt::registry object containing all game entities and components.
         */
        MainMenu(sf::RenderWindow &window, Assets &assets, Registry &registry);

        /**
         * @brief Draws the main menu on the screen.
         */
        void draw();

        /**
         * @brief Update the buttons to check if they are hovered or clicked.
         */
        void update();

        /**
         * @brief Adds a new keyboard key to the list of keys to be handled by the menu.
         *
         * @param key The keyboard key to be added.
         */
        void setKey(sf::Keyboard::Key key) { m_keys.push_back(key); };

        /**
         * @brief Returns the vector of keyboard keys currently being pressed.
         *
         * @return std::vector<sf::Keyboard::Key> The vector of keyboard keys currently being pressed.
         */
        std::vector<sf::Keyboard::Key> getKeys() { return m_keys; };

        /**
         * @brief Resets the state of all buttons and sets the selected button to the one at the given index.
         *
         * @param index The index of the button to select.
         */
        void resetAndSetSelectedButton(unsigned int index);

        /**
         * @brief Gets the ID of the button that was pressed in the main menu.
         *
         * @return The ID of the button that was pressed.
         */
        unsigned int getButtonPressed();

        /**
         * @brief Returns the UDP port used by the client.
         *
         * @return The UDP port used by the client.
         */
        unsigned int getUDPPort() const;

        /**
         * @brief Returns the TCP port used by the client.
         *
         * @return The TCP port used by the client.
         */
        unsigned int getTCPPort() const;

        /**
         * @brief Returns the IP address associated with the MainMenu object.
         *
         * @return The IP address associated with the MainMenu object.
         */
        ip::address getIp() const;

        /**
         * @brief Loads the background image for the main menu and displays it on the given window.
         *
         * @param window A pointer to the SFML RenderWindow to display the background on.
         * @param registry A reference to the ECS registry to use for loading resources.
         */
        void loadBackground(sf::RenderWindow *window, Registry &registry);

        /**
         * @brief Deletes the background entity from the registry.
         *
         * @param registry The registry containing the background entity.
         */
        void deleteBackground(Registry &registry);

        /**
         * @brief Deletes all buttons from the main menu.
         *
         * @param registry The registry containing the buttons to delete.
         */
        void deleteButtons(Registry &registry);

        /**
         * @brief Loads the class for the main menu.
         *
         * @param window A pointer to the SFML render window.
         * @param registry A reference to the ECS registry.
         */
        void loadClass(sf::RenderWindow *window, Registry &registry);

        /**
         * @brief Deletes the MainMenu class from the given registry.
         *
         * @param registry The registry to delete the MainMenu class from.
         */
        void deleteClass(Registry &registry);

        /**
         * @brief Draws the main menu class.
         *
         */
        void drawClass();

        /**
         * @brief Returns whether a class has been selected in the main menu.
         *
         * @return true if a class has been selected, false otherwise.
         */
        bool isClassSelected() { return m_classSelected; }

        /**
         * @brief Waits for a valid key press event and returns the corresponding scancode.
         *
         * @return The scancode of the key that was pressed.
         */
        sf::Keyboard::Scan::Scancode getValidKeyPressed();

        bool m_nugoSelected = false;
        bool m_andreasSelected = false;
        bool m_eliotSelected = false;
        bool m_louisSelected = false;

    private:
        sf::RenderWindow &m_window;
        Assets &m_assets;
        Registry &m_registry;
        std::vector<std::unique_ptr<IButton>> m_buttons;
        std::vector<sf::Text> m_texts;
        std::vector<sf::Keyboard::Key> m_keys;
        std::vector<sf::Keyboard::Scan::Scancode> m_validKeys;
        std::map<sf::Keyboard::Scan::Scancode, char> m_keyMap;
        std::vector<bool> m_bools;
        enum ButtonType {
            PORT,
            ADDRESS,
            CONNECT
        };
        std::vector<ButtonType> m_buttonTypes;
        sf::Font m_font;
        bool m_isPlayMenuOpen = false;
        bool m_classSelected = false;
        ButtonFactory m_buttonFactory;
};
