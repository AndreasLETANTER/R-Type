/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ProjectileCollisionSystemTests
*/

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#include <criterion/criterion.h>

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.hpp"

Test(ProjectileCollisionSystem, when_an_entity_is_in_collision_with_a_projectile_it_takes_damage)
{
    Registry registry;
    auto entityProjectile = registry.spawn_entity();
    auto entityTarget = registry.spawn_entity();

    registry.register_component<Component::Projectile>();
    registry.register_component<Component::Collision>();
    registry.register_component<Component::Health>();

    registry.add_component<Component::Projectile>(entityProjectile, Component::Projectile(Component::Position(10, 10), 10, 10));
    registry.add_component<Component::Collision>(entityProjectile, Component::Collision(10, 10));
    registry.add_component<Component::Collision>(entityTarget, Component::Collision(10, 10));
    registry.add_component<Component::Health>(entityTarget, Component::Health(100));

    registry.add_system<Component::Projectile, Component::Collision, Component::Health>(ProjectileCollisionSystem());

    registry.get_components<Component::Collision>()[entityProjectile].value().entities_in_collision.push_back(entityTarget);

    registry.run_systems();

    cr_assert_eq(registry.get_components<Component::Health>()[entityTarget].value().health, 90);
}

Test(ProjectileCollisionSystem, when_an_entity_is_not_in_collision_with_a_projectile_it_does_not_take_damage)
{
    Registry registry;
    auto entityProjectile = registry.spawn_entity();
    auto entityTarget = registry.spawn_entity();

    registry.register_component<Component::Projectile>();
    registry.register_component<Component::Collision>();
    registry.register_component<Component::Health>();

    registry.add_component<Component::Projectile>(entityProjectile, Component::Projectile(Component::Position(10, 10), 10, 10));
    registry.add_component<Component::Collision>(entityProjectile, Component::Collision(10, 10));
    registry.add_component<Component::Collision>(entityTarget, Component::Collision(10, 10));
    registry.add_component<Component::Health>(entityTarget, Component::Health(100));

    registry.add_system<Component::Projectile, Component::Collision, Component::Health>(ProjectileCollisionSystem());

    registry.run_systems();

    cr_assert_eq(registry.get_components<Component::Health>()[entityTarget].value().health, 100);
}
