/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** SparseArray
*/

#include "SparseArray.hpp"

template <typename Component>
SparseArray<Component>::SparseArray()
{
}

template <typename Component>
SparseArray<Component>::SparseArray(SparseArray const &other)
{
    m_data = other.m_data;
}

template <typename Component>
SparseArray<Component>::SparseArray(SparseArray &&other) noexcept
{
    m_data = std::move(other.m_data);
}

template <typename Component>
SparseArray<Component>::~SparseArray()
{
}

template <typename Component>
SparseArray<Component> &SparseArray<Component>::operator=(SparseArray const &other)
{
    m_data = other.m_data;
    return *this;
}

template <typename Component>
SparseArray<Component> &SparseArray<Component>::operator=(SparseArray &&other) noexcept
{
    m_data = std::move(other.m_data);
    return *this;
}

template <typename Component>
typename SparseArray<Component>::reference_type SparseArray<Component>::operator[](size_t idx)
{
    return m_data[idx];
}

template <typename Component>
typename SparseArray<Component>::const_reference_type SparseArray<Component>::operator[](size_t idx) const
{
    return m_data[idx];
}

template <typename Component>
typename SparseArray<Component>::iterator SparseArray<Component>::begin()
{
    return m_data.begin();
}

template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::begin() const
{
    return m_data.begin();
}

template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::cbegin() const
{
    return m_data.cbegin();
}

template <typename Component>
typename SparseArray<Component>::iterator SparseArray<Component>::end()
{
    return m_data.end();
}

template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::end() const
{
    return m_data.end();
}

template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::cend() const
{
    return m_data.cend();
}

template <typename Component>
typename SparseArray<Component>::size_type SparseArray<Component>::size() const
{
    return m_data.size();
}

template <typename Component>
typename SparseArray<Component>::reference_type SparseArray<Component>::insert_at(size_type pos, Component const &component)
{
    if (pos >= m_data.size()) {
        m_data.resize(pos);
    }
    if (m_data.size() > pos) {
        m_data[pos].~value_type();
        m_data.erase(m_data.begin() + pos);
    }
    m_data.insert(m_data.begin() + pos, component);
    return m_data[pos];
}

template <typename Component>
typename SparseArray<Component>::reference_type SparseArray<Component>::insert_at(size_type pos, Component &&component)
{
    if (pos >= m_data.size()) {
        m_data.resize(pos);
    }
    if (m_data.size() > pos) {
        m_data[pos].~value_type();
        m_data.erase(m_data.begin() + pos);
    }
    m_data.insert(m_data.begin() + pos, component);
    return m_data[pos];
}

template <typename Component>
void SparseArray<Component>::erase(size_type pos)
{
    m_data.erase(m_data.begin() + pos);
}

template <typename Component>
template <class... Params>
typename SparseArray<Component>::reference_type SparseArray<Component>::emplace_at(size_type pos, Params &&...params)
{
    if (pos >= m_data.size()) {
        m_data.resize(pos);
    }
    if (m_data.size() > pos) {
        m_data[pos].~value_type();
        m_data.erase(m_data.begin() + pos);
    }
    m_data.insert(m_data.begin() + pos, Component(std::forward<Params>(params)...));
    return m_data[pos];
}

template <typename Component>
typename SparseArray<Component>::size_type SparseArray<Component>::get_index(value_type const &value) const
{
    for (unsigned int i = 0; i < m_data.size(); i++) {
        if (m_data[i].has_value() && std::addressof(m_data[i]) == std::addressof(value)) {
            return i;
        }
    }

    throw std::runtime_error("Value not found");
}
