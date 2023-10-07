/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Parser
*/

#include <SFML/Graphics.hpp>

#include "Parser.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Drawable.hpp"
#include "ECS/Components/Scroll.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Controllable.hpp"
#include "ECS/Components/Shoot.hpp"
#include "ECS/Components/Collision.hpp"
#include "ECS/Components/AutoMove.hpp"

Parser::Parser(Registry &registry, sf::RenderWindow &window, sf::Clock &clock, std::vector<std::string> filesPath) :
    m_registry(registry),
    m_window(window),
    m_clock(clock),
    m_filesPaths(filesPath)
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

    m_levelParams.level = params["level"];
    m_levelParams.width = params["resolution"]["width"];
    m_levelParams.height = params["resolution"]["height"];
}

void Parser::loadBackgrounds()
{
    const libconfig::Setting &backgrounds = m_config.lookup("entities.backgrounds");
    basicEntity base;

    for (int i = 0; i < backgrounds.getLength(); i++) {
        base.id = backgrounds[i]["id"];
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

        m_registry.spawn_entity();
        m_registry.add_component<Component::Position>(m_registry.entity_from_index(base.id), Component::Position(base.posX, base.posY));
        m_registry.add_component<Component::Drawable>(m_registry.entity_from_index(base.id), Component::Drawable(base.assetName, &m_window, sf::IntRect(base.rectX, base.rectY, base.rectWidth, base.rectHeight), Component::Position(base.scaleX, base.scaleY), true));
        m_registry.add_component<Component::Scroll>(m_registry.entity_from_index(base.id), Component::Scroll(Component::Position(base.posX, base.posY), Component::Position(offsetLimitX, offsetLimitY)));
    }
}

void Parser::loadPlayers()
{
    const libconfig::Setting &players = m_config.lookup("entities.players");
    basicEntity base;

    for (int i = 0; i < players.getLength(); i++) {
        base.id = players[i]["id"];
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
        (void)health;

        m_registry.spawn_entity();
        m_registry.add_component<Component::Position>(m_registry.entity_from_index(base.id), Component::Position(base.posX, base.posY));
        m_registry.add_component<Component::Velocity>(m_registry.entity_from_index(base.id), Component::Velocity(0, 0));
        m_registry.add_component<Component::Controllable>(m_registry.entity_from_index(base.id), Component::Controllable(true));
        m_registry.add_component<Component::Drawable>(m_registry.entity_from_index(base.id), Component::Drawable(base.assetName, &m_window, sf::IntRect(base.rectX, base.rectY, base.rectWidth, base.rectHeight), Component::Position(base.scaleX, base.scaleY), true));
        m_registry.add_component<Component::Shoot>(m_registry.entity_from_index(base.id), Component::Shoot(true, &m_clock, sf::Time(sf::milliseconds(250)), 20, projectileAssetName, false));
        m_registry.add_component<Component::Collision>(m_registry.entity_from_index(base.id), Component::Collision(base.rectHeight, base.rectWidth));
    }
}

void Parser::loadObstacles()
{
    const libconfig::Setting &obstacles = m_config.lookup("entities.obstacles");
    basicEntity base;

    for (int i = 0; i < obstacles.getLength(); i++) {
        base.id = obstacles[i]["id"];
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
        (void) rotation;
        (void) health;

        m_registry.spawn_entity();
        m_registry.add_component<Component::Position>(m_registry.entity_from_index(base.id), Component::Position(base.posX, base.posY));
        m_registry.add_component<Component::Drawable>(m_registry.entity_from_index(base.id), Component::Drawable(base.assetName, &m_window, sf::IntRect(base.rectX, base.rectY, base.rectWidth, base.rectHeight), Component::Position(base.scaleX, base.scaleY), true));
        m_registry.add_component<Component::Collision>(m_registry.entity_from_index(base.id), Component::Collision(base.rectHeight, base.rectWidth));
        m_registry.add_component<Component::Scroll>(m_registry.entity_from_index(base.id), Component::Scroll(Component::Position(base.posX, base.posY), Component::Position(0, 0)));
    }
}

void Parser::loadEnemies()
{
    const libconfig::Setting &enemies = m_config.lookup("entities.enemies");
    basicEntity base;

    for (int i = 0; i < enemies.getLength(); i++) {
        base.id = enemies[i]["id"];
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
        (void) rotation;
        (void) health;

        m_registry.spawn_entity();
        m_registry.add_component<Component::Position>(m_registry.entity_from_index(base.id), Component::Position(base.posX, base.posY));
        m_registry.add_component<Component::Velocity>(m_registry.entity_from_index(base.id), Component::Velocity(0, 0));
        m_registry.add_component<Component::Drawable>(m_registry.entity_from_index(base.id), Component::Drawable(base.assetName, &m_window, sf::IntRect(base.rectX, base.rectY, base.rectWidth, base.rectHeight), Component::Position(base.scaleX, base.scaleY), true));
        m_registry.add_component<Component::Shoot>(m_registry.entity_from_index(base.id), Component::Shoot(true, &m_clock, sf::Time(sf::milliseconds(250)), 20, projectileAssetName, true));
        m_registry.add_component<Component::Collision>(m_registry.entity_from_index(base.id), Component::Collision(base.rectHeight, base.rectWidth));
        m_registry.add_component<Component::AutoMove>(m_registry.entity_from_index(base.id), Component::AutoMove(Component::Position(base.posX, base.posY), Component::Position(0, 0)));
    }
}
