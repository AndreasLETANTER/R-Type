/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Parser
*/

#pragma once

#include <libconfig.h++>

#include "ECS/RegistryClass/Registry.hpp"

/**
 * @brief The Parser class is responsible for loading game data from a file using libconfig.
 */
class Parser {
    public:
        /**
         * @brief Constructs a Parser object with the given registry and files path.
         *
         * @param registry The registry to use for parsing.
         * @param filesPath A vector of file paths to parse.
         */
        Parser(Registry &registry, std::vector<std::string> filesPath);

        /**
         * @brief Default destructor for Parser class.
         */
        ~Parser() = default;

        /**
         * @brief Loads game data from a file using libconfig and stores it in the given registry.
         */
        void loadFromFile();

    private:
        libconfig::Config m_config;
        Registry &m_registry;
        std::vector<std::string> m_filesPaths;

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
