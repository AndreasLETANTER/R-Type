/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** PositionSystemTests
*/

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#include <criterion/criterion.h>
#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"

Test(PositionSystem, basic_PositionSystem)
{
    Registry registry;
    registry.spawn_entity();
    registry.register_component<Component::Position>();
    registry.register_component<Component::Velocity>();
    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));
    registry.add_component<Component::Velocity>(registry.entity_from_index(0), Component::Velocity(1, 1));

    PositionSystem()(registry, registry.get_components<Component::Position>(), registry.get_components<Component::Velocity>());
    cr_assert_eq(registry.get_components<Component::Position>()[registry.entity_from_index(0)].value().x, 1);
    cr_assert_eq(registry.get_components<Component::Position>()[registry.entity_from_index(0)].value().y, 1);
}

Test(PositionSystem, no_velocity_PositionSystem)
{
    Registry registry;
    registry.spawn_entity();
    registry.register_component<Component::Position>();
    registry.register_component<Component::Velocity>();
    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));

    PositionSystem()(registry, registry.get_components<Component::Position>(), registry.get_components<Component::Velocity>());
    cr_assert_eq(registry.get_components<Component::Position>()[registry.entity_from_index(0)].value().x, 0);
    cr_assert_eq(registry.get_components<Component::Position>()[registry.entity_from_index(0)].value().y, 0);
}

Test(PositionSystem, no_position_PositionSystem)
{
    Registry registry;
    registry.spawn_entity();
    registry.register_component<Component::Position>();
    registry.register_component<Component::Velocity>();
    registry.add_component<Component::Velocity>(registry.entity_from_index(0), Component::Velocity(1, 1));

    PositionSystem()(registry, registry.get_components<Component::Position>(), registry.get_components<Component::Velocity>());
    cr_assert_eq(registry.get_components<Component::Velocity>()[registry.entity_from_index(0)].value().vx, 1);
    cr_assert_eq(registry.get_components<Component::Velocity>()[registry.entity_from_index(0)].value().vy, 1);
}
