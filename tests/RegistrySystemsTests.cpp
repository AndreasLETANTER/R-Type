/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** RegistrySystemsTests
*/

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#include <criterion/criterion.h>
#include "../src/EntityClass/Entity.hpp"
#include "../src/SparseArrayClass/SparseArray.hpp"
#include "../src/RegistryClass/Registry.hpp"
#include "../src/Systems/PositionSystem/PositionSystem.hpp"
#include "../src/Components/Position.hpp"
#include "../src/Components/Velocity.hpp"

Test(Registry, Basic_system_registry)
{
    Registry registry;
    registry.spawn_entity();
    registry.register_component<Component::Position>();
    registry.register_component<Component::Velocity>();
    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));
    registry.add_component<Component::Velocity>(registry.entity_from_index(0), Component::Velocity(1, 1));

    registry.add_system<Component::Position, Component::Velocity>(PositionSystem());
    registry.run_systems();
    cr_assert_eq(registry.get_components<Component::Position>()[registry.entity_from_index(0)].value().x, 1);
    cr_assert_eq(registry.get_components<Component::Position>()[registry.entity_from_index(0)].value().y, 1);
}
