/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Registry
*/

#include <string.h>

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Components/Controllable.hpp"
#include "ECS/Components/Shoot.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Drawable.hpp"
#include "ECS/Components/Controllable.hpp"
#include "ECS/Components/Shoot.hpp"


Registry::Registry(Assets assets, sf::RenderWindow *window, sf::Clock *clock)
    : m_window(window), m_clock(clock), m_assets(assets)
{

}

Entity Registry::spawn_entity()
{
    unsigned int id = std::rand() % 10000000;

    for (std::size_t i = 0; i < m_entities.size(); i++) {
        if (!m_entities[i].has_value()) {
            m_entities[i] = std::make_pair(Entity(i), id);
            return m_entities[i].value().first;
        }
    }
    m_entities.insert_at(m_entities.size(), std::make_pair(Entity(m_entities.size()), id));
    return m_entities[m_entities.size() - 1].value().first;
}

Entity Registry::spawn_entity(unsigned int id)
{
    for (std::size_t i = 0; i < m_entities.size(); i++) {
        if (!m_entities[i].has_value()) {
            m_entities[i] = std::make_pair(Entity(i), id);
            return m_entities[i].value().first;
        }
    }
    m_entities.insert_at(m_entities.size(), std::make_pair(Entity(m_entities.size()), id));
    return m_entities[m_entities.size() - 1].value().first;
}

Entity Registry::entity_from_index(std::size_t idx)
{
    if (idx >= m_entities.size()) {
        throw std::runtime_error{"Entity index out of range"};
    } else if (m_entities[idx].has_value() == false) {
        throw std::runtime_error{"Entity no value"};
    } else {
        return m_entities[idx].value().first;
    }
}

Entity Registry::entity_from_id(unsigned int id)
{
    for (auto &entity : m_entities) {
        if (entity.has_value() && entity.value().second == id) {
            return entity.value().first;
        }
    }
    throw std::runtime_error{"Entity not found"};
}

void Registry::kill_entity(Entity const &e)
{
    m_entities[e].reset();

    for (auto &erase_func : m_erase_functions) {
        erase_func.second(*this, e);
    }
}

void Registry::run_systems()
{
    for (auto &system : m_systems) {
        system(*this);
    }
}

std::vector<packet_t> Registry::exportToPackets(bool newClient)
{
    std::vector<packet_t> Packets;
    packet_t tempPacket;
    auto &drawables = get_components<Component::Drawable>();
    auto &positions = get_components<Component::Position>();
    auto &scores = get_components<Component::Score>();

    //get all dead entities
    for (unsigned int i = 0; i < m_previous_entities.size(); i++) {
        if (m_previous_entities[i].has_value() && m_entities[i].has_value()) {
            if (m_previous_entities[i].value().second != m_entities[i].value().second) {
                tempPacket.messageType = ENTITY_DEATH_CODE;
                tempPacket.packet_id = rand() % 10000000;
                tempPacket.message.entity_id = m_previous_entities[i].value().second;
                m_recently_killed_entities.push_back(tempPacket);
                Packets.push_back(tempPacket);
            }
        }
        if (m_previous_entities[i].has_value() && m_entities[i].has_value() == false) {
            tempPacket.messageType = ENTITY_DEATH_CODE;
            tempPacket.packet_id = rand() % 10000000;
            tempPacket.message.entity_id = m_previous_entities[i].value().second;
            m_recently_killed_entities.push_back(tempPacket);
            Packets.push_back(tempPacket);
        }
    }

    //get all spawned entities
    for (unsigned int i = 0; i < m_entities.size(); i++) {
        if (m_previous_entities.size() > i && m_previous_entities[i].has_value() && m_entities[i].has_value()) {
            if (m_previous_entities[i].value().second != m_entities[i].value().second) {
                tempPacket.messageType = ENTITY_SPAWN_CODE;
                tempPacket.packet_id = rand() % 10000000;
                tempPacket.message.entity_id = m_entities[i].value().second;
                strcpy(tempPacket.message.sprite_name, drawables[m_entities[i].value().first].value().spriteName.c_str());
                tempPacket.message.rect = drawables[m_entities[i].value().first].value().rect;
                tempPacket.message.scale = drawables[m_entities[i].value().first].value().scale;
                tempPacket.message.x = positions[m_entities[i].value().first].value().x;
                tempPacket.message.y = positions[m_entities[i].value().first].value().y;
                tempPacket.message.isBackground = drawables[m_entities[i].value().first].value().isBackground;
                Packets.push_back(tempPacket);
            }
        }
        if ((m_previous_entities.size() <= i || m_previous_entities[i].has_value() == false) && m_entities[i].has_value()) {
                tempPacket.messageType = ENTITY_SPAWN_CODE;
                tempPacket.packet_id = rand() % 10000000;
                tempPacket.message.entity_id = m_entities[i].value().second;
                strcpy(tempPacket.message.sprite_name, drawables[m_entities[i].value().first].value().spriteName.c_str());
                tempPacket.message.rect = drawables[m_entities[i].value().first].value().rect;
                tempPacket.message.scale = drawables[m_entities[i].value().first].value().scale;
                tempPacket.message.x = positions[m_entities[i].value().first].value().x;
                tempPacket.message.y = positions[m_entities[i].value().first].value().y;
                tempPacket.message.isBackground = drawables[m_entities[i].value().first].value().isBackground;
                Packets.push_back(tempPacket);
        }
    }

    //get all moved entities
    for (unsigned int i = 0; i < positions.size(); i++) {
        if (m_previous_positions.size() > i && positions[i].has_value() && m_previous_positions[i].has_value()) {
            if (positions[i].value().x != m_previous_positions[i].value().x || positions[i].value().y != m_previous_positions[i].value().y) {
                tempPacket.messageType = ENTITY_MOVE_CODE;
                tempPacket.packet_id = rand() % 10000000;
                tempPacket.message.entity_id = m_entities[i].value().second;
                tempPacket.message.x = positions[m_entities[i].value().first].value().x;
                tempPacket.message.y = positions[m_entities[i].value().first].value().y;
                Packets.push_back(tempPacket);
            }
        }
        if ((m_previous_positions.size() <= i || m_previous_positions[i].has_value() == false) && positions[i].has_value()) {
            tempPacket.messageType = ENTITY_MOVE_CODE;
            tempPacket.packet_id = rand() % 10000000;
            tempPacket.message.entity_id = m_entities[i].value().second;
            tempPacket.message.x = positions[m_entities[i].value().first].value().x;
            tempPacket.message.y = positions[m_entities[i].value().first].value().y;
            Packets.push_back(tempPacket);
        }
    }

    //get all scores increases
    unsigned int player_count = 1;
    for (unsigned i = 0; i < scores.size(); i++) {
        if (m_previous_scores.size() > i && scores[i].has_value() && m_previous_scores[i].has_value()) {
            if (scores[i].value().score != m_previous_scores[i].value().score) {
                tempPacket.messageType = ENTITY_SCORE_CODE;
                tempPacket.packet_id = rand() % 10000000;
                tempPacket.message.entity_id = m_entities[i].value().second;
                tempPacket.message.score = scores[m_entities[i].value().first].value().score;
                tempPacket.message.client_id = player_count;
                Packets.push_back(tempPacket);
            }
            player_count++;
        }
        if ((m_previous_scores.size() <= i || m_previous_scores[i].has_value() == false) && scores[i].has_value()) {
            tempPacket.messageType = ENTITY_SCORE_CODE;
            tempPacket.packet_id = rand() % 10000000;
            tempPacket.message.entity_id = m_entities[i].value().second;
            tempPacket.message.score = scores[m_entities[i].value().first].value().score;
            tempPacket.message.client_id = player_count;
            Packets.push_back(tempPacket);
            player_count++;
        }
    }

    if (newClient == true) {
        for (unsigned int i = 0; i < m_entities.size(); i++) {
            if (m_entities[i].has_value()) {
                if (drawables[i].has_value() && positions[i].has_value()) {
                    tempPacket.messageType = ALL_GAME_INFO_CODE;
                    tempPacket.packet_id = rand() % 10000000;
                    tempPacket.message.entity_id = m_entities[i].value().second;
                    strcpy(tempPacket.message.sprite_name, drawables[m_entities[i].value().first].value().spriteName.c_str());
                    tempPacket.message.rect = drawables[m_entities[i].value().first].value().rect;
                    tempPacket.message.scale = drawables[m_entities[i].value().first].value().scale;
                    tempPacket.message.x = positions[m_entities[i].value().first].value().x;
                    tempPacket.message.y = positions[m_entities[i].value().first].value().y;
                    tempPacket.message.isBackground = drawables[m_entities[i].value().first].value().isBackground;
                    Packets.push_back(tempPacket);
                }
            }
        }
    }
    if (newClient == true) {
        tempPacket.messageType = NO_MORE_GAME_INFO_CODE;
        tempPacket.packet_id = rand() % 10000000;
        Packets.push_back(tempPacket);
    }
    m_previous_entities = m_entities;
    m_previous_positions = positions;
    m_previous_scores = scores;
    return Packets;
}

std::vector<packet_t> Registry::exportRecentlyKilledEntities()
{
    std::vector<packet_t> temp = m_recently_killed_entities;
    m_recently_killed_entities.clear();
    return temp;
}

void Registry::updateFromPacket(packet_t packet, sf::RenderWindow *window, std::unique_ptr<IButton> &scoreButton, unsigned int clientId)
{
    if (packet.messageType == ALL_GAME_INFO_CODE) {
        try
        {
            entity_from_id(packet.message.entity_id);
        }
        catch(const std::exception& e)
        {
            auto entity = spawn_entity(packet.message.entity_id);
            add_component<Component::Drawable>(entity, Component::Drawable(packet.message.sprite_name, window, packet.message.rect, packet.message.scale, m_assets.get_texture(packet.message.sprite_name), packet.message.isBackground));
            add_component<Component::Position>(entity, Component::Position(packet.message.x, packet.message.y));
            add_component<Component::Score>(entity, Component::Score(packet.message.score, m_clock));
        }
    }
    if (packet.messageType == ENTITY_SPAWN_CODE) {
        try
        {
            entity_from_id(packet.message.entity_id);
            return;
        }
        catch(const std::exception& e)
        {
            auto entity = spawn_entity(packet.message.entity_id);
            add_component<Component::Drawable>(entity, Component::Drawable(packet.message.sprite_name, window, packet.message.rect, packet.message.scale, m_assets.get_texture(packet.message.sprite_name), packet.message.isBackground));
            add_component<Component::Position>(entity, Component::Position(packet.message.x, packet.message.y));
            add_component<Component::Score>(entity, Component::Score(packet.message.score, m_clock));
            if (strncmp(packet.message.sprite_name, "PBullet", 7) == 0)
                m_assets.get_sound("LaserSoundEffect")->play();
            if (strncmp(packet.message.sprite_name, "PowerUp", 7) == 0) {
                m_assets.get_sound("RizzPowerUpSoundEffect")->play();
            }
        }
    }
    if (packet.messageType == ENTITY_DEATH_CODE) {
        for (unsigned int i = 0; i < m_entities.size(); i++) {
            if (m_entities[i].has_value() && m_entities[i].value().second == packet.message.entity_id) {
                kill_entity(m_entities[i].value().first);
                break;
            }
        }
    }
    if (packet.messageType == ENTITY_MOVE_CODE) {
        Entity entity;

        auto &positions = get_components<Component::Position>();
        try {
            entity = entity_from_id(packet.message.entity_id);
        }
        catch(const std::exception& e)
        {
            return;
        }
        positions[entity].value().x = packet.message.x;
        positions[entity].value().y = packet.message.y;
    }
    if (packet.messageType == ENTITY_SCORE_CODE) {
        Entity entity;

        auto &scores = get_components<Component::Score>();
        try {
            entity = entity_from_id(packet.message.entity_id);
        }
        catch(const std::exception& e)
        {
            return;
        }
        scores[entity].value().score = packet.message.score;
        if (clientId == packet.message.client_id) {
            scoreButton->setTextString("Score: " + std::to_string(scores[entity].value().score));
        }
    }
}

Assets &Registry::get_assets()
{
    return m_assets;
}

void Registry::updateEntityKeyPressed(input_t input)
{
    for (auto &entity : m_entities) {
        if (entity.has_value()) {
            auto &controllable = get_components<Component::Controllable>();
            auto &shoots = get_components<Component::Shoot>();
            for (size_t i = 0; i < shoots.size(); i++) {
                if (shoots[i].has_value()) {
                    if (shoots[i].value().playerId == input.id) {
                        shoots[i].value().m_keyMapState[input.key] = input.pressed;
                    }
                }
            }
            for (size_t i = 0; i < controllable.size(); i++) {
                if (controllable[i].has_value()) {
                    if (controllable[i].value().playerId == input.id) {
                        controllable[i].value().m_keyMapState[input.key] = input.pressed;
                    }
                }
            }
        }
    }
}

bool Registry::playersAreDead()
{
    SparseArray<Component::Controllable> &controllables = get_components<Component::Controllable>();

    for (size_t entity = 0; entity < controllables.size(); entity++) {
        if (controllables[entity].has_value() == false) {
            continue;
        }
        return false;
    }
    return true;
}

bool Registry::enemiesAreDead()
{
    int nbEntitiesLeft = 0;
    SparseArray<Component::Controllable> &controllables = get_components<Component::Controllable>();
    SparseArray<Component::Shoot> &shoots = get_components<Component::Shoot>();

    for (size_t entity = 0; entity < shoots.size(); entity++) {
        if ((entity >= controllables.size() || controllables[entity].has_value() == false) && shoots[entity].has_value() == true) {
            nbEntitiesLeft++;
        }
    }
    if (nbEntitiesLeft == 0) {
        return true;
    }
    return false;
}

sf::RenderWindow *Registry::getWindow() const
{
    return m_window;
}

sf::Clock *Registry::getClock() const
{
    return m_clock;
}

void Registry::setWindow(sf::RenderWindow *window)
{
    m_window = window;
}

void Registry::setClock(sf::Clock *clock)
{
    m_clock = clock;
}

void Registry::setNeedToRestart(bool needToRestart)
{
    m_needToRestart = needToRestart;
}

bool Registry::getNeedToRestart() const
{
    return m_needToRestart;
}

SparseArray<std::pair<Entity, unsigned int>> &Registry::getEntities()
{
    return m_entities;
}

Entity Registry::player_from_id(unsigned int id)
{
    auto &controllables = get_components<Component::Controllable>();

    for (size_t entity = 0; entity < controllables.size(); entity++) {
        if (controllables[entity].has_value() == false) {
            continue;
        }
        if (controllables[entity].value().playerId == id) {
            return m_entities[entity].value().first;
        }
    }
    throw std::runtime_error{"Player not found"};
}

void Registry::addPlayerClass(unsigned int id, EntityClasses entityClass)
{
    m_playersClasses.insert(std::make_pair(id, entityClass));
}

EntityClasses Registry::getPlayerClass(unsigned int id)
{
    return m_playersClasses.at(id);
}
