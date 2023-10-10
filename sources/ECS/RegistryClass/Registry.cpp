/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Registry
*/

#include <string.h>

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Drawable.hpp"


Registry::Registry(Assets assets) : m_assets(assets)
{
}

Entity Registry::spawn_entity()
{
    for (std::size_t i = 0; i < m_entities.size(); i++) {
        if (!m_entities[i].has_value()) {
            m_entities[i] = Entity(i);
            return m_entities[i].value();
        }
    }
    m_entities.insert_at(m_entities.size(), Entity(m_entities.size()));
    return m_entities[m_entities.size() - 1].value();
}

Entity Registry::entity_from_index(std::size_t idx)
{
    if (idx >= m_entities.size()) {
        throw std::runtime_error{"Entity index out of range"};
    } else if (m_entities[idx].has_value() == false) {
        throw std::runtime_error{"Entity no value"};
    } else {
        return m_entities[idx].value();
    }
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

std::pair<message_t *, size_t>Registry::exportToMessages()
{
    message_t *messages = new message_t[m_entities.size()];
    size_t size = 0;
    auto &drawables = get_components<Component::Drawable>();
    auto &positions = get_components<Component::Position>();

    for (size_t i = 0; i < drawables.size() && i < positions.size(); ++i) {
        auto &drawable = drawables[i];
        auto &position = positions[i];
        if (drawable.has_value() && position.has_value()) {
            strcpy(messages[i].sprite_name, drawable.value().spriteName.c_str());
            messages[i].x = position.value().x;
            messages[i].y = position.value().y;
            size++;
        }
    }
    return std::make_pair(messages, size);
}

void Registry::importFromMessages(message_t *messages, size_t size, sf::RenderWindow *window, sf::IntRect rect, Component::Position position)
{
    register_component<Component::Position>();
    register_component<Component::Drawable>();
    for (size_t i = 0; i < size; ++i) {
        auto entity = spawn_entity();
        add_component<Component::Drawable>(entity, Component::Drawable(messages[i].sprite_name, window, rect, position, true, m_assets.get_texture(messages[i].sprite_name)));
        add_component<Component::Position>(entity, Component::Position(messages[i].x, messages[i].y));
    }
}
Assets &Registry::get_assets()
{
    return m_assets;
}
