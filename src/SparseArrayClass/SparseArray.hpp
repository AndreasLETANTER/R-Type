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

/**
 * @brief A sparse array implementation that stores optional values of a given component type.
 * 
 * @tparam Component The type of the component to store in the sparse array.
 */
template <typename Component>
class SparseArray
{
public:
    using value_type = std::optional<Component>; /**< The type of the stored optional value. */
    using reference_type = value_type &; /**< The type of the reference to the stored optional value. */
    using const_reference_type = value_type const &; /**< The type of the const reference to the stored optional value. */
    using container_t = std::vector<value_type>; /**< The type of the underlying container used to store the optional values. */
    using size_type = typename container_t::size_type; /**< The type of the size of the underlying container. */
    using iterator = typename container_t::iterator; /**< The type of the iterator for the underlying container. */
    using const_iterator = typename container_t::const_iterator; /**< The type of the const iterator for the underlying container. */

    /**
     * @brief Default constructor for the sparse array.
     */
    SparseArray();

    /**
     * @brief Copy constructor for the sparse array.
     * 
     * @param other The sparse array to copy.
     */
    SparseArray(SparseArray const &other);

    /**
     * @brief Move constructor for the sparse array.
     * 
     * @param other The sparse array to move.
     */
    SparseArray(SparseArray &&other) noexcept;

    /**
     * @brief Destructor for the sparse array.
     */
    ~SparseArray();

    /**
     * @brief Copy assignment operator for the sparse array.
     * 
     * @param other The sparse array to copy.
     * @return SparseArray& A reference to the copied sparse array.
     */
    SparseArray &operator=(SparseArray const &other);

    /**
     * @brief Move assignment operator for the sparse array.
     * 
     * @param other The sparse array to move.
     * @return SparseArray& A reference to the moved sparse array.
     */
    SparseArray &operator=(SparseArray &&other) noexcept;

    /**
     * @brief Access operator for the sparse array.
     * 
     * @param idx The index of the optional value to access.
     * @return reference_type A reference to the optional value at the given index.
     */
    reference_type operator[](size_t idx);

    /**
     * @brief Const access operator for the sparse array.
     * 
     * @param idx The index of the optional value to access.
     * @return const_reference_type A const reference to the optional value at the given index.
     */
    const_reference_type operator[](size_t idx) const;

    /**
     * @brief Returns an iterator to the beginning of the underlying container.
     * 
     * @return iterator An iterator to the beginning of the underlying container.
     */
    iterator begin();

    /**
     * @brief Returns a const iterator to the beginning of the underlying container.
     * 
     * @return const_iterator A const iterator to the beginning of the underlying container.
     */
    const_iterator begin() const;

    /**
     * @brief Returns a const iterator to the beginning of the underlying container.
     * 
     * @return const_iterator A const iterator to the beginning of the underlying container.
     */
    const_iterator cbegin() const;

    /**
     * @brief Returns an iterator to the end of the underlying container.
     * 
     * @return iterator An iterator to the end of the underlying container.
     */
    iterator end();

    /**
     * @brief Returns a const iterator to the end of the underlying container.
     * 
     * @return const_iterator A const iterator to the end of the underlying container.
     */
    const_iterator end() const;

    /**
     * @brief Returns a const iterator to the end of the underlying container.
     * 
     * @return const_iterator A const iterator to the end of the underlying container.
     */
    const_iterator cend() const;

    /**
     * @brief Returns the size of the underlying container.
     * 
     * @return size_type The size of the underlying container.
     */
    size_type size() const;

    /**
     * @brief Inserts an optional value at the given position in the underlying container.
     * 
     * @param pos The position to insert the optional value at.
     * @param value The optional value to insert.
     * @return reference_type A reference to the inserted optional value.
     */
    reference_type insert_at(size_type pos, Component const &value);

    /**
     * @brief Inserts an optional value at the given position in the underlying container.
     * 
     * @param pos The position to insert the optional value at.
     * @param value The optional value to insert.
     * @return reference_type A reference to the inserted optional value.
     */
    reference_type insert_at(size_type pos, Component &&value);

    /**
     * @brief Emplaces an optional value at the given position in the underlying container.
     * 
     * @tparam Params The types of the parameters to forward to the constructor of the optional value.
     * @param pos The position to emplace the optional value at.
     * @param params The parameters to forward to the constructor of the optional value.
     * @return reference_type A reference to the emplaced optional value.
     */
    template <class... Params>
    reference_type emplace_at(size_type pos, Params &&...params);

    /**
     * @brief Erases the optional value at the given position in the underlying container.
     * 
     * @param pos The position of the optional value to erase.
     */
    void erase(size_type pos);

    /**
     * @brief Returns the index of the given optional value in the underlying container.
     * 
     * @param value The optional value to find the index of.
     * @return size_type The index of the given optional value in the underlying container.
     */
    size_type get_index(value_type const &value) const;

private:
    container_t m_data; /**< The underlying container used to store the optional values. */
};


#include "SparseArray.tpp"
