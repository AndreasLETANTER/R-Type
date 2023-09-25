/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** SparseArray
*/

#pragma once
#include <vector>
#include <iostream>
#include <optional>
#include <string>

template <typename Component>
class SparseArray
{
    public:
        using value_type = std::optional<Component>;
        using reference_type = value_type &;
        using const_reference_type = value_type const &;
        using container_t = std::vector<value_type>;
        using size_type = typename container_t::size_type;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;
        SparseArray();
        SparseArray(SparseArray const &);
        SparseArray(SparseArray &&) noexcept;
        ~SparseArray();
        SparseArray &operator=(SparseArray const &);
        SparseArray &operator=(SparseArray &&) noexcept;
        reference_type operator[](size_t idx);
        const_reference_type operator[](size_t idx) const;
        iterator begin();
        const_iterator begin() const;
        const_iterator cbegin() const;
        iterator end();
        const_iterator end() const;
        const_iterator cend() const;
        size_type size() const;
        reference_type insert_at(size_type pos, Component const &);
        reference_type insert_at(size_type pos, Component &&);
        template <class... Params>
        reference_type emplace_at(size_type pos, Params &&...);
        void erase(size_type pos);
        size_type get_index(value_type const &) const;

    protected:
    private:
        container_t m_data;
};

#include "SparseArray.tpp"
