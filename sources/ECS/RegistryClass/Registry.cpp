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


Registry::Registry(Assets assets) : m_assets(assets)
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
    return Entity();
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

    //get all dead entities
    for (unsigned int i = 0; i < m_previous_entities.size(); i++) {
        if (m_previous_entities[i].has_value() && m_entities[i].has_value()) {
            if (m_previous_entities[i].value().second != m_entities[i].value().second) {
                tempPacket.messageType = ENTITY_DEATH_CODE;
                tempPacket.message.entity_id = m_previous_entities[i].value().second;
                Packets.push_back(tempPacket);
            }
        }
        if (m_previous_entities[i].has_value() && m_entities[i].has_value() == false) {
            tempPacket.messageType = ENTITY_DEATH_CODE;
            tempPacket.message.entity_id = m_previous_entities[i].value().second;
            Packets.push_back(tempPacket);
        }
    }

    //get all spawned entities
    for (unsigned int i = 0; i < m_entities.size(); i++) {
        if (m_previous_entities.size() > i && m_previous_entities[i].has_value() && m_entities[i].has_value()) {
            if (m_previous_entities[i].value().second != m_entities[i].value().second) {
                tempPacket.messageType = ENTITY_SPAWN_CODE;
                tempPacket.message.entity_id = m_entities[i].value().second;
                strcpy(tempPacket.message.sprite_name, drawables[m_entities[i].value().first].value().spriteName.c_str());
                tempPacket.message.rect = drawables[m_entities[i].value().first].value().rect;
                tempPacket.message.position = drawables[m_entities[i].value().first].value().scale;
                tempPacket.message.x = positions[m_entities[i].value().first].value().x;
                tempPacket.message.y = positions[m_entities[i].value().first].value().y;
                Packets.push_back(tempPacket);
            }
        }
        if ((m_previous_entities.size() <= i || m_previous_entities[i].has_value() == false) && m_entities[i].has_value()) {
                tempPacket.messageType = ENTITY_SPAWN_CODE;
                tempPacket.message.entity_id = m_entities[i].value().second;
                strcpy(tempPacket.message.sprite_name, drawables[m_entities[i].value().first].value().spriteName.c_str());
                tempPacket.message.rect = drawables[m_entities[i].value().first].value().rect;
                tempPacket.message.position = drawables[m_entities[i].value().first].value().scale;
                tempPacket.message.x = positions[m_entities[i].value().first].value().x;
                tempPacket.message.y = positions[m_entities[i].value().first].value().y;
                Packets.push_back(tempPacket);
        }
    }

    //get all moved entities
    for (unsigned int i = 0; i < positions.size(); i++) {
        if (m_previous_positions.size() > i && positions[i].has_value() && m_previous_positions[i].has_value()) {
            if (positions[i].value().x != m_previous_positions[i].value().x || positions[i].value().y != m_previous_positions[i].value().y) {
                tempPacket.messageType = ENTITY_MOVE_CODE;
                tempPacket.message.entity_id = m_entities[i].value().second;
                tempPacket.message.x = positions[m_entities[i].value().first].value().x;
                tempPacket.message.y = positions[m_entities[i].value().first].value().y;
                Packets.push_back(tempPacket);
            }
        }
        if ((m_previous_positions.size() <= i || m_previous_positions[i].has_value() == false) && positions[i].has_value()) {
            tempPacket.messageType = ENTITY_MOVE_CODE;
            tempPacket.message.entity_id = m_entities[i].value().second;
            tempPacket.message.x = positions[m_entities[i].value().first].value().x;
            tempPacket.message.y = positions[m_entities[i].value().first].value().y;
            Packets.push_back(tempPacket);
        }
    }
    if (newClient == true) {
        for (unsigned int i = 0; i < m_entities.size(); i++) {
            if (m_entities[i].has_value()) {
                if (drawables[i].has_value() && positions[i].has_value()) {
                    tempPacket.messageType = ALL_GAME_INFO_CODE;
                    tempPacket.message.entity_id = m_entities[i].value().second;
                    strcpy(tempPacket.message.sprite_name, drawables[m_entities[i].value().first].value().spriteName.c_str());
                    tempPacket.message.rect = drawables[m_entities[i].value().first].value().rect;
                    tempPacket.message.position = drawables[m_entities[i].value().first].value().scale;
                    tempPacket.message.x = positions[m_entities[i].value().first].value().x;
                    tempPacket.message.y = positions[m_entities[i].value().first].value().y;
                    Packets.push_back(tempPacket);
                }
            }
        }
    }
    if (newClient == true) {
        tempPacket.messageType = NO_MORE_GAME_INFO_CODE;
        Packets.push_back(tempPacket);
    }
    m_previous_entities = m_entities;
    m_previous_positions = positions;
    return Packets;
}

void Registry::updateFromPacket(packet_t packet, sf::RenderWindow *window)
{
    if (packet.messageType == ALL_GAME_INFO_CODE) {
        auto entity = spawn_entity(packet.message.entity_id);
        add_component<Component::Drawable>(entity, Component::Drawable(packet.message.sprite_name, window, packet.message.rect, packet.message.position, m_assets.get_texture(packet.message.sprite_name)));
        add_component<Component::Position>(entity, Component::Position(packet.message.x, packet.message.y));
    }
    if (packet.messageType == ENTITY_SPAWN_CODE) {
        auto entity = spawn_entity(packet.message.entity_id);
        add_component<Component::Drawable>(entity, Component::Drawable(packet.message.sprite_name, window, packet.message.rect, packet.message.position, m_assets.get_texture(packet.message.sprite_name)));
        add_component<Component::Position>(entity, Component::Position(packet.message.x, packet.message.y));
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
        auto entity = entity_from_id(packet.message.entity_id);
        auto &positions = get_components<Component::Position>();
        positions[entity].value().x = packet.message.x;
        positions[entity].value().y = packet.message.y;
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
                        shoots[i].value().keyPressed = input.key;
                    }
                }
            }
            for (size_t i = 0; i < controllable.size(); i++) {
                if (controllable[i].has_value()) {
                    if (controllable[i].value().playerId == input.id) {
                        controllable[i].value().keyPressed = input.key;
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
        if (controllables[entity].has_value() == false && shoots[entity].has_value() == true) {
            nbEntitiesLeft++;
        }
    }
    if (nbEntitiesLeft == 0) {
        return true;
    }
    return false;
}
