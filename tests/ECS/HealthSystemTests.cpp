/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HealthSystemTests
*/

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#include <criterion/criterion.h>

#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.hpp"
#include "ECS/Systems/HealthSystem/HealthSystem.hpp"

Test(HealthSystem, when_a_projectile_does_not_kill_an_entity)
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

    cr_assert_eq(registry.m_entities[entityTarget].has_value(), true);
}

Test(HealthSystem, when_a_projectile_kills_an_entity)
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
    registry.add_component<Component::Health>(entityTarget, Component::Health(10));

    registry.add_system<Component::Projectile, Component::Collision, Component::Health>(ProjectileCollisionSystem());
    registry.add_system<Component::Health>(HealthSystem());

    registry.get_components<Component::Collision>()[entityProjectile].value().entities_in_collision.push_back(entityTarget);

    registry.run_systems();

    cr_assert_eq(registry.m_entities[entityTarget].has_value(), false);
}
