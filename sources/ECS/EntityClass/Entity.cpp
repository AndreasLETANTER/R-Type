/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** entity
*/

#include "ECS/EntityClass/Entity.hpp"

Entity::Entity(const std::size_t id)
{
    m_id = id;
}

Entity::Entity()
{
    m_id = 0;
}
