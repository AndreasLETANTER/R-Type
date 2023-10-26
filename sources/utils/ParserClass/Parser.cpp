/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Parser
*/

#include <SFML/Graphics.hpp>

#include "Parser.hpp"
#include "ECS/Components/EntityClass.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Drawable.hpp"
#include "ECS/Components/Scroll.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Controllable.hpp"
#include "ECS/Components/Shoot.hpp"
#include "ECS/Components/Collision.hpp"
#include "ECS/Components/AutoMove.hpp"
#include "ECS/Components/Health.hpp"
#include "ECS/Components/Score.hpp"

std::map<std::string, EntityClasses> entityClassesMap = {
    {"NUGO", EntityClasses::NUGO},
    {"ANDREAS", EntityClasses::ANDREAS},
    {"ELIOT", EntityClasses::ELIOT},
    {"LOUIS", EntityClasses::LOUIS},
    {"MOB_ORANGE_CRAB", EntityClasses::MOB_ORANGE_CRAB},
    {"MOB_YELLOW_POPCORN", EntityClasses::MOB_YELLOW_POPCORN}
};

Parser::Parser(Registry &registry, sf::RenderWindow &window, sf::Clock &clock, std::vector<std::string> filesContents) :
    m_registry(registry),
    m_window(window),
    m_clock(clock),
    m_filesContents(filesContents)
{}

void Parser::loadFromFile()
{
    for (auto &filePath : m_filesContents) {
        try {
            m_config.readString(filePath.c_str());
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
        int pauseX = backgrounds[i]["pauseX"];

        m_registry.spawn_entity();
        m_registry.add_component<Component::Position>(m_registry.entity_from_index(base.id), Component::Position(base.posX, base.posY));
        m_registry.add_component<Component::Drawable>(m_registry.entity_from_index(base.id), Component::Drawable(base.assetName, &m_window, sf::IntRect(base.rectX, base.rectY, base.rectWidth, base.rectHeight), Component::Position(base.scaleX, base.scaleY), m_registry.get_assets().get_texture(base.assetName)));
        m_registry.add_component<Component::Scroll>(m_registry.entity_from_index(base.id), Component::Scroll(Component::Position(base.posX, base.posY), Component::Position(offsetLimitX, offsetLimitY), pauseX));
    }
}

void Parser::loadPlayers()
{
    const libconfig::Setting &players = m_config.lookup("entities.players");
    basicEntity base;

    for (int i = 0; i < players.getLength(); i++) {
        base.id = players[i]["id"];
        std::string classValue = players[i]["class"];
        EntityClasses classEnum = entityClassesMap[classValue];
        base.posX = players[i]["position"]["x"];
        base.posY = players[i]["position"]["y"];
        base.rectX = players[i]["rect"]["x"];
        base.rectY = players[i]["rect"]["y"];
        base.rectWidth = players[i]["rect"]["width"];
        base.rectHeight = players[i]["rect"]["height"];

        m_registry.spawn_entity();
        Component::EntityClass entityClassTmp = Component::EntityClassFactory::CreateEntityClass(classEnum);
        m_registry.add_component<Component::EntityClass>(m_registry.entity_from_index(base.id), Component::EntityClassFactory::CreateEntityClass(classEnum));
        m_registry.add_component<Component::Position>(m_registry.entity_from_index(base.id), Component::Position(base.posX, base.posY));
        m_registry.add_component<Component::Velocity>(m_registry.entity_from_index(base.id), Component::Velocity(0, 0, entityClassTmp.speed));
        m_registry.add_component<Component::Controllable>(m_registry.entity_from_index(base.id), Component::Controllable(true, i + 1));
        m_registry.add_component<Component::Shoot>(m_registry.entity_from_index(base.id), Component::Shoot(i + 1, true, LINEAR, &m_clock, sf::Time(sf::milliseconds(entityClassTmp.shootingDelay)), entityClassTmp.damage, entityClassTmp.projectileAssetName, 1, 1920));
        m_registry.add_component<Component::Drawable>(m_registry.entity_from_index(base.id), Component::Drawable(entityClassTmp.assetName, &m_window, sf::IntRect(base.rectX, base.rectY, base.rectWidth, base.rectHeight), Component::Position(entityClassTmp.scale.x, entityClassTmp.scale.y), m_registry.get_assets().get_texture(entityClassTmp.assetName)));
        m_registry.add_component<Component::Collision>(m_registry.entity_from_index(base.id), Component::Collision(base.rectHeight, base.rectWidth));
        m_registry.add_component<Component::Health>(m_registry.entity_from_index(base.id), Component::Health(entityClassTmp.health));
        m_registry.add_component<Component::Score>(m_registry.entity_from_index(base.id), Component::Score(0, &m_clock));
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
        int pauseX = obstacles[i]["pauseX"];
        (void) rotation;

        m_registry.spawn_entity();
        m_registry.add_component<Component::Position>(m_registry.entity_from_index(base.id), Component::Position(base.posX, base.posY));
        m_registry.add_component<Component::Drawable>(m_registry.entity_from_index(base.id), Component::Drawable(base.assetName, &m_window, sf::IntRect(base.rectX, base.rectY, base.rectWidth, base.rectHeight), Component::Position(base.scaleX, base.scaleY), m_registry.get_assets().get_texture(base.assetName)));
        m_registry.add_component<Component::Collision>(m_registry.entity_from_index(base.id), Component::Collision(base.rectHeight, base.rectWidth));
        m_registry.add_component<Component::Scroll>(m_registry.entity_from_index(base.id), Component::Scroll(Component::Position(base.posX, base.posY), Component::Position(0, 0), pauseX));
        m_registry.add_component<Component::Health>(m_registry.entity_from_index(base.id), Component::Health(health));
    }
}

void Parser::loadEnemies()
{
    const libconfig::Setting &enemies = m_config.lookup("entities.enemies");
    basicEntity base;

    for (int i = 0; i < enemies.getLength(); i++) {
        base.id = enemies[i]["id"];
        std::string classValue = enemies[i]["class"];
        EntityClasses classEnum = entityClassesMap[classValue];
        base.posX = enemies[i]["position"]["x"];
        base.posY = enemies[i]["position"]["y"];
        int automove_x = enemies[i]["autoMove"]["x"];
        int automove_y = enemies[i]["autoMove"]["y"];

        m_registry.spawn_entity();
        Component::EntityClass entityClassTmp = Component::EntityClassFactory::CreateEntityClass(classEnum);
        m_registry.add_component<Component::EntityClass>(m_registry.entity_from_index(base.id), Component::EntityClassFactory::CreateEntityClass(classEnum));
        m_registry.add_component<Component::Position>(m_registry.entity_from_index(base.id), Component::Position(base.posX, base.posY));
        m_registry.add_component<Component::Velocity>(m_registry.entity_from_index(base.id), Component::Velocity(0, 0, entityClassTmp.speed));
        m_registry.add_component<Component::Shoot>(m_registry.entity_from_index(base.id), Component::Shoot(0, true, entityClassTmp.shootingPattern, &m_clock, sf::Time(sf::milliseconds(entityClassTmp.shootingDelay)), entityClassTmp.damage, entityClassTmp.projectileAssetName, -1, 0));
        m_registry.add_component<Component::Drawable>(m_registry.entity_from_index(base.id), Component::Drawable(entityClassTmp.assetName, &m_window, sf::IntRect(entityClassTmp.rect.top, entityClassTmp.rect.left, entityClassTmp.rect.width, entityClassTmp.rect.height), Component::Position(entityClassTmp.scale.x, entityClassTmp.scale.y), m_registry.get_assets().get_texture(entityClassTmp.assetName)));
        m_registry.add_component<Component::Collision>(m_registry.entity_from_index(base.id), Component::Collision(entityClassTmp.rect.height, entityClassTmp.rect.width));
        m_registry.add_component<Component::AutoMove>(m_registry.entity_from_index(base.id), Component::AutoMove(Component::Position(base.posX, base.posY), Component::Position(automove_x, automove_y)));
        m_registry.add_component<Component::Health>(m_registry.entity_from_index(base.id), Component::Health(entityClassTmp.health));
    }
}
