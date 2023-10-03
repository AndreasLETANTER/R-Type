/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Parser
*/

#include <SFML/Graphics.hpp>

#include "Parser.hpp"
#include "ECS/Components/Position.hpp"

Parser::Parser(Registry &registry, std::vector<std::string> filesPath)
    : m_registry(registry), m_filesPath(filesPath)
{}

void Parser::loadFromFile()
{
    for (auto &filePath : m_filesPaths) {
        m_config.readFile(filePath.c_str());
        loadLevelParams();
        loadBackgrounds();
        loadPlayers();
        loadObstacles();
    }
}

void Parser::loadBackgrounds()
{
    const libconfig::Setting &backgrounds = m_config.lookup("backgrounds");
    for (int i = 0; i < backgrounds.getLength(); i++) {
        std::string backgroundName = backgrounds[i]["assetName"];
        Component::Position position = Component::Position(backgrounds[i]["position"]["x"], backgrounds[i]["position"]["y"]);
        Component::Position scale = Component::Position(backgrounds[i]["scale"]["x"], backgrounds[i]["scale"]["y"]);
        sf::IntRect rect = sf::IntRect(backgrounds[i]["rect"]["x"], backgrounds[i]["rect"]["y"], backgrounds[i]["rect"]["width"], backgrounds[i]["rect"]["height"]);
        Component::Position offsetLimit = Component::Position(backgrounds[i]["offsetLimit"]["x"], backgrounds[i]["offsetLimit"]["y"]);

        std::cout << "backgroundName: " << backgroundName << std::endl;
        std::cout << "position: " << position.x << ", " << position.y << std::endl;
        std::cout << "scale: " << scale.x << ", " << scale.y << std::endl;
        std::cout << "rect: " << rect.left << ", " << rect.top << ", " << rect.width << ", " << rect.height << std::endl;
        std::cout << "offsetLimit: " << offsetLimit.x << ", " << offsetLimit.y << std::endl;
    }
}
