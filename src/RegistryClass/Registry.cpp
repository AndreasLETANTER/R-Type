/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Registry
*/

#include "Registry.hpp"

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
    if (m_entities[idx].has_value() == false) {
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
