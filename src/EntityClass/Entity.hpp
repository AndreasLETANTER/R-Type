/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** entity
*/

#pragma once
#include <cstddef>

class Entity {
    public:
        ~Entity() = default;
        inline operator std::size_t() const { return m_id; };

    protected:
    private:
        friend class Registry;
        explicit Entity(const std::size_t id);
        explicit Entity();
        std::size_t m_id;
};
