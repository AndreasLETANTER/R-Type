/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** PositionSystemTests
*/

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#include <criterion/criterion.h>
#include "../sources/ECS/RegistryClass/Registry.hpp"
#include "../sources/ECS/Systems/CollisionSystem/CollisionSystem.hpp"

Test(CollisionSystem, basic_CollisionSystem)
{
    Registry registry;
    auto entity1 = registry.spawn_entity();
    auto entity2 = registry.spawn_entity();

    registry.register_component<Component::Position>();
    registry.register_component<Component::Collision>();


    registry.add_component<Component::Position>(entity1, Component::Position(0, 0));
    registry.add_component<Component::Collision>(entity1, Component::Collision(10, 10));
    registry.add_component<Component::Position>(entity2, Component::Position(0, 0));
    registry.add_component<Component::Collision>(entity2, Component::Collision(10, 10));

    registry.add_system<Component::Position, Component::Collision>(CollisionSystem());

    registry.run_systems();

    cr_assert_eq(registry.get_components<Component::Collision>()[entity1].value().entities_in_collision[0], entity2);
    cr_assert_eq(registry.get_components<Component::Collision>()[entity2].value().entities_in_collision[0], entity1);
}

Test(CollisionSystem, CollisionSystem_no_collision)
{
    Registry registry;
    auto entity1 = registry.spawn_entity();
    auto entity2 = registry.spawn_entity();

    registry.register_component<Component::Position>();
    registry.register_component<Component::Collision>();


    registry.add_component<Component::Position>(entity1, Component::Position(11, 0));
    registry.add_component<Component::Collision>(entity1, Component::Collision(10, 10));
    registry.add_component<Component::Position>(entity2, Component::Position(0, 0));
    registry.add_component<Component::Collision>(entity2, Component::Collision(10, 10));

    registry.add_system<Component::Position, Component::Collision>(CollisionSystem());

    registry.run_systems();

    cr_assert_eq(registry.get_components<Component::Collision>()[entity1].value().entities_in_collision.size(), 0);
    cr_assert_eq(registry.get_components<Component::Collision>()[entity2].value().entities_in_collision.size(), 0);
}

Test(CollisionSystem, CollisionSystem_no_collision_after_one)
{
    Registry registry;
    auto entity1 = registry.spawn_entity();
    auto entity2 = registry.spawn_entity();

    registry.register_component<Component::Position>();
    registry.register_component<Component::Collision>();


    registry.add_component<Component::Position>(entity1, Component::Position(0, 0));
    registry.add_component<Component::Collision>(entity1, Component::Collision(10, 10));
    registry.add_component<Component::Position>(entity2, Component::Position(0, 0));
    registry.add_component<Component::Collision>(entity2, Component::Collision(10, 10));

    registry.add_system<Component::Position, Component::Collision>(CollisionSystem());

    registry.run_systems();

    cr_assert_eq(registry.get_components<Component::Collision>()[entity1].value().entities_in_collision[0], entity2);
    cr_assert_eq(registry.get_components<Component::Collision>()[entity2].value().entities_in_collision[0], entity1);

    registry.get_components<Component::Position>()[entity1].value().x = 11;

    registry.run_systems();

    cr_assert_eq(registry.get_components<Component::Collision>()[entity1].value().entities_in_collision.size(), 0);
    cr_assert_eq(registry.get_components<Component::Collision>()[entity2].value().entities_in_collision.size(), 0);
}

Test(CollisionSystem, CollisionSystem_collision_after_one)
{
    Registry registry;
    auto entity1 = registry.spawn_entity();
    auto entity2 = registry.spawn_entity();

    registry.register_component<Component::Position>();
    registry.register_component<Component::Collision>();


    registry.add_component<Component::Position>(entity1, Component::Position(0, 0));
    registry.add_component<Component::Collision>(entity1, Component::Collision(10, 10));
    registry.add_component<Component::Position>(entity2, Component::Position(0, 0));
    registry.add_component<Component::Collision>(entity2, Component::Collision(10, 10));

    registry.add_system<Component::Position, Component::Collision>(CollisionSystem());

    registry.run_systems();

    cr_assert_eq(registry.get_components<Component::Collision>()[entity1].value().entities_in_collision[0], entity2);
    cr_assert_eq(registry.get_components<Component::Collision>()[entity2].value().entities_in_collision[0], entity1);

    registry.get_components<Component::Position>()[entity1].value().x = 5;

    registry.run_systems();

    cr_assert_eq(registry.get_components<Component::Collision>()[entity1].value().entities_in_collision[0], entity2);
    cr_assert_eq(registry.get_components<Component::Collision>()[entity2].value().entities_in_collision[0], entity1);
}
