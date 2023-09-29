/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Registry
*/

#include "ECS/RegistryClass/Registry.hpp"

template <class Component>
SparseArray<Component> &Registry::register_component()
{
    auto typeIdx = std::type_index(typeid(Component));

    if (m_components.find(typeIdx) != m_components.end()) {
        throw std::runtime_error{"Component already registered"};
    }
    register_erase_function<Component>([](Registry &registry, Entity const &entity) {
        if (registry.get_components<Component>().size() < entity || registry.get_components<Component>()[entity].has_value() == false) {
            return;
        }
        registry.get_components<Component>()[entity].reset();
    });
    m_components[typeIdx] = SparseArray<Component>();
    return std::any_cast<SparseArray<Component> &>(m_components[typeIdx]);
}

template <class Component>
Registry::erase_function Registry::register_erase_function(erase_function function)
{
    auto typeIdx = std::type_index(typeid(Component));

    if (m_erase_functions.find(typeIdx) != m_erase_functions.end()) {
        throw std::runtime_error{"Erase function already registered"};
    }
    m_erase_functions[typeIdx] = function;
    return m_erase_functions[typeIdx];
}

template <class Component>
void Registry::erase_entity(Entity const &entity)
{
    auto typeIdx = std::type_index(typeid(Component));

    if (m_erase_functions.find(typeIdx) == m_erase_functions.end()) {
        throw std::runtime_error{"Erase not registered"};
    }
    m_erase_functions[typeIdx](*this, entity);
}

template <class Component>
SparseArray<Component> &Registry::get_components()
{
    auto typeIdx = std::type_index(typeid(Component));

    if (m_components.find(typeIdx) == m_components.end()) {
        throw std::runtime_error{"Component not registered" };
    }
    return std::any_cast<SparseArray<Component> &>(m_components[typeIdx]);
}

template <class Component>
SparseArray<Component> const &Registry::get_components() const
{
    auto typeIdx = std::type_index(typeid(Component));

    if (m_components.find(typeIdx) == m_components.end()) {
        throw std::runtime_error{"Component not registered"};
    }
    return std::any_cast<SparseArray<Component> const &>(m_components.at(typeIdx));
}

template <typename Component>
typename SparseArray<Component>::reference_type Registry::add_component(Entity const &to, Component &&c)
{
    return get_components<Component>().emplace_at(to, std::forward<Component>(c));
}

template <typename Component, typename... Params>
typename SparseArray<Component>::reference_type Registry::emplace_component(Entity const &to, Params &&...p)
{
    return get_components<Component>().emplace_at(to, std::forward<Params>(p)...);
}

template <typename Component>
void Registry::remove_component(Entity const &from)
{
    get_components<Component>()[from].reset();
}

template <class... Components, typename Function>
void Registry::add_system(Function &&f)
{
    auto system = [&](Registry &r) {
        f(r, r.get_components<Components>()...);
    };

    m_systems.emplace_back(system);
}

template <class... Components, typename Function>
void Registry::add_system(Function const &f)
{
    auto system = [&](Registry &r) {
        f(r, r.get_components<Components>()...);
    };

    m_systems.emplace_back(system);
}
