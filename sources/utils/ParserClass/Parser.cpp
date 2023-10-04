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
    : m_registry(registry), m_filesPaths(filesPath)
{}

void Parser::loadFromFile()
{
    for (auto &filePath : m_filesPaths) {
        try {
            m_config.readFile(filePath.c_str());
            loadLevelParams();
            loadBackgrounds();
            loadPlayers();
            loadObstacles();
            loadEnemies();
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading the configuration file." << std::endl;
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Setting not found in configuration file." << std::endl;
        } catch (const libconfig::SettingTypeException &tex) {
            std::cerr << "Setting type mismatch in configuration file." << std::endl;
        } catch (const libconfig::SettingException &ex) {
            std::cerr << "Setting exception in configuration file." << std::endl;
        } catch (const libconfig::ConfigException &ex) {
            std::cerr << "Config exception in configuration file." << std::endl;
        }
    }
}

void Parser::loadLevelParams()
{
    const libconfig::Setting &params = m_config.lookup("params");

    int level = params["level"];
    int width = params["resolution"]["width"];
    int height = params["resolution"]["height"];

    std::cout << "===== Parsing: params =====" << std::endl;
    std::cout << "level: " << level << std::endl;
    std::cout << "resolution: " << width << ", " << height << "\n" << std::endl;
}

void Parser::loadBackgrounds()
{
    const libconfig::Setting &backgrounds = m_config.lookup("entities.backgrounds");
    basicEntity base;

    for (int i = 0; i < backgrounds.getLength(); i++) {
        base.assetName = backgrounds[i]["assetName"].c_str();
        base.posX = backgrounds[i]["position"]["x"];
        base.posY = backgrounds[i]["position"]["y"];
        base.scaleX = backgrounds[i]["scale"]["x"];
        base.scaleY = backgrounds[i]["scale"]["y"];
        base.rectX = backgrounds[i]["rect"]["x"];
        base.rectY = backgrounds[i]["rect"]["y"];
        base.rectWidth = backgrounds[i]["rect"]["width"];
        base.rectHeight = backgrounds[i]["rect"]["height"];
        int offsetLimitX = backgrounds[i]["offsetLimit"]["x"];
        int offsetLimitY = backgrounds[i]["offsetLimit"]["y"];

        std::cout << "===== Parsing: background(" << i << ") =====" << std::endl;
        std::cout << "assetName: " << base.assetName << std::endl;
        std::cout << "position: " << base.posX << ", " << base.posY << std::endl;
        std::cout << "scale: " << base.scaleX << ", " << base.scaleY << std::endl;
        std::cout << "rect: " << base.rectX << ", " << base.rectY << ", " << base.rectWidth << ", " << base.rectHeight << std::endl;
        std::cout << "offsetLimit: " << offsetLimitX << ", " << offsetLimitY << "\n" << std::endl;
    }
}

void Parser::loadPlayers()
{
    const libconfig::Setting &players = m_config.lookup("entities.players");
    basicEntity base;

    for (int i = 0; i < players.getLength(); i++) {
        base.assetName = players[i]["assetName"].c_str();
        std::string projectileAssetName = players[i]["projectileAssetName"];
        base.posX = players[i]["position"]["x"];
        base.posY = players[i]["position"]["y"];
        base.scaleX = players[i]["scale"]["x"];
        base.scaleY = players[i]["scale"]["y"];
        base.rectX = players[i]["rect"]["x"];
        base.rectY = players[i]["rect"]["y"];
        base.rectWidth = players[i]["rect"]["width"];
        base.rectHeight = players[i]["rect"]["height"];
        int health = players[i]["health"];

        std::cout << "===== Parsing: player(" << i << ") =====" << std::endl;
        std::cout << "assetName: " << base.assetName << std::endl;
        std::cout << "projectileAssetName: " << projectileAssetName << std::endl;
        std::cout << "position: " << base.posX << ", " << base.posY << std::endl;
        std::cout << "scale: " << base.scaleX << ", " << base.scaleY << std::endl;
        std::cout << "rect: " << base.rectX << ", " << base.rectY << ", " << base.rectWidth << ", " << base.rectHeight << std::endl;
        std::cout << "health: " << health << "\n" << std::endl;
    }
}

void Parser::loadObstacles()
{
    const libconfig::Setting &obstacles = m_config.lookup("entities.obstacles");
    basicEntity base;

    for (int i = 0; i < obstacles.getLength(); i++) {
        base.assetName = obstacles[i]["assetName"].c_str();
        std::string projectileAssetName = obstacles[i]["projectileAssetName"];
        base.posX = obstacles[i]["position"]["x"];
        base.posY = obstacles[i]["position"]["y"];
        base.scaleX = obstacles[i]["scale"]["x"];
        base.scaleY = obstacles[i]["scale"]["y"];
        base.rectX = obstacles[i]["rect"]["x"];
        base.rectY = obstacles[i]["rect"]["y"];
        base.rectWidth = obstacles[i]["rect"]["width"];
        base.rectHeight = obstacles[i]["rect"]["height"];
        int rotation = obstacles[i]["rotation"];
        int health = obstacles[i]["health"];

        std::cout << "===== Parsing: obstacle(" << i << ") =====" << std::endl;
        std::cout << "assetName: " << base.assetName << std::endl;
        std::cout << "projectileAssetName: " << projectileAssetName << std::endl;
        std::cout << "position: " << base.posX << ", " << base.posY << std::endl;
        std::cout << "scale: " << base.scaleX << ", " << base.scaleY << std::endl;
        std::cout << "rect: " << base.rectX << ", " << base.rectY << ", " << base.rectWidth << ", " << base.rectHeight << std::endl;
        std::cout << "rotation: " << rotation << std::endl;
        std::cout << "health: " << health << "\n" << std::endl;
    }
}

void Parser::loadEnemies()
{
    const libconfig::Setting &enemies = m_config.lookup("entities.enemies");
    basicEntity base;

    for (int i = 0; i < enemies.getLength(); i++) {
        base.assetName = enemies[i]["assetName"].c_str();
        std::string projectileAssetName = enemies[i]["projectileAssetName"];
        base.posX = enemies[i]["position"]["x"];
        base.posY = enemies[i]["position"]["y"];
        base.scaleX = enemies[i]["scale"]["x"];
        base.scaleY = enemies[i]["scale"]["y"];
        base.rectX = enemies[i]["rect"]["x"];
        base.rectY = enemies[i]["rect"]["y"];
        base.rectWidth = enemies[i]["rect"]["width"];
        base.rectHeight = enemies[i]["rect"]["height"];
        int rotation = enemies[i]["rotation"];
        int health = enemies[i]["health"];

        std::cout << "===== Parsing: ennemy(" << i << ") =====" << std::endl;
        std::cout << "assetName: " << base.assetName << std::endl;
        std::cout << "projectileAssetName: " << projectileAssetName << std::endl;
        std::cout << "position: " << base.posX << ", " << base.posY << std::endl;
        std::cout << "scale: " << base.scaleX << ", " << base.scaleY << std::endl;
        std::cout << "rect: " << base.rectX << ", " << base.rectY << ", " << base.rectWidth << ", " << base.rectHeight << std::endl;
        std::cout << "rotation: " << rotation << std::endl;
        std::cout << "health: " << health << "\n" << std::endl;
    }
}