/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Parser
*/

#pragma once

#include <libconfig.h++>

#include "ECS/RegistryClass/Registry.hpp"

struct levelParams {
    int level;
    int width;
    int height;
};

struct basicEntity {
    int id;
    std::string assetName;
    int posX;
    int posY;
    int scaleX;
    int scaleY;
    int textureRectX;
    int textureRectY;
    int textureRectWidth;
    int textureRectHeight;
    int textureOffsetRectX;
    int textureOffsetRectY;
    int textureOffsetRectWidth;
    int textureOffsetRectHeight;
};

/**
 * @brief The Parser class is responsible for loading game data from a file using libconfig.
 */
class Parser {
    public:
        /**
         * @brief Constructs a Parser object with the given registry and files path.
         *
         * @param registry The registry to use for parsing.
         * @param window The window to use for parsing.
         * @param clock The clock to use for parsing.
         * @param filesContents A vector of file content to parse.
         */
        Parser(Registry &registry, sf::RenderWindow &window, sf::Clock &clock, std::vector<std::string> filesContents);

        /**
         * @brief Default destructor for Parser class.
         */
        ~Parser() = default;

        /**
         * @brief Loads game data from a file using libconfig and stores it in the given registry.
         */
        void loadFromFile();

        /**
         * @brief Returns the level parameters.
         *
         * @return The level parameters.
         */
        levelParams getLevelParams() const { return m_levelParams; };

    private:
        libconfig::Config m_config;
        Registry &m_registry;
        sf::RenderWindow &m_window;
        sf::Clock &m_clock;
        std::vector<std::string> m_filesContents;
        levelParams m_levelParams;

        /**
         * @brief Loads level parameters from the loaded game data and stores them in the given registry.
         */
        void loadLevelParams();

        /**
         * @brief Loads backgrounds from the loaded game data and stores them in the given registry.
         */
        void loadBackgrounds();

        /**
         * @brief Loads players from the loaded game data and stores them in the given registry.
         */
        void loadPlayers();

        /**
         * @brief Loads obstacles from the loaded game data and stores them in the given registry.
         */
        void loadObstacles();

        /**
         * @brief Loads enemies from the loaded game data and stores them in the given registry.
         */
        void loadEnemies();
};
