/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Registry
*/

#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <any>
#include "../SparseArrayClass/SparseArray.hpp"
#include "../EntityClass/Entity.hpp"

class Registry {
    public:
        using erase_function = std::function<void(Registry&, Entity const&)>;
        template <class Component>
        SparseArray<Component> &register_component();
        template <class Component>
        erase_function register_erase_function(erase_function function);
        template <class Component>
        void erase_entity(Entity const &entity);
        template <class Component>
        SparseArray<Component> &get_components();
        template <class Component>
        SparseArray<Component> const &get_components() const;

        Entity spawn_entity();
        Entity entity_from_index(std ::size_t idx);
        void kill_entity(Entity const &e);
        template <typename Component>
        typename SparseArray<Component>::reference_type add_component(Entity const &to,
                                                                       Component &&c);
        template <typename Component, typename... Params>
        typename SparseArray<Component>::reference_type emplace_component(Entity const &to, Params &&...p);
        template <typename Component>
        void remove_component(Entity const &from);

        template <class... Components, typename Function>
        void add_system(Function &&f);
        template <class... Components, typename Function>
        void add_system(Function const &f);
        void run_systems();
    private:
        std::unordered_map<std::type_index, std::any> m_components;
        std::unordered_map<std::type_index, erase_function> m_erase_functions;
        SparseArray<Entity> m_entities;
        std::vector<std::function<void(Registry&)>> m_systems;
};

#include "Registry.tpp"
