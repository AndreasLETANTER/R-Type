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
#include "ECS/Components/Score.hpp"

Test(HealthSystem, when_a_projectile_does_not_kill_an_entity)
{
    Registry registry;
    auto entityProjectile = registry.spawn_entity();
    auto entityTarget = registry.spawn_entity();

    registry.register_component<Component::Projectile>();
    registry.register_component<Component::Collision>();
    registry.register_component<Component::Health>();
    registry.register_component<Component::Score>();

    registry.add_component<Component::Score>(entityTarget, Component::Score(0, std::nullptr_t()));
    registry.add_component<Component::Projectile>(entityProjectile, Component::Projectile(Component::Position(0, 10), Component::Position(10, 10), 10, 10, 2));
    registry.add_component<Component::Collision>(entityProjectile, Component::Collision(10, 10));
    registry.add_component<Component::Collision>(entityTarget, Component::Collision(10, 10));
    registry.add_component<Component::Health>(entityTarget, Component::Health(100));

    registry.add_system<Component::Projectile, Component::Collision, Component::Health, Component::Score>(ProjectileCollisionSystem());

    registry.get_components<Component::Collision>()[entityProjectile].value().entities_in_collision.push_back(entityTarget);

    registry.run_systems();

    cr_assert_eq(registry.entity_from_index(entityTarget), entityTarget);
}

Test(HealthSystem, when_a_projectile_kills_an_entity)
{
    Registry registry;
    auto entityProjectile = registry.spawn_entity();
    auto entityTarget = registry.spawn_entity();

    registry.register_component<Component::Projectile>();
    registry.register_component<Component::Collision>();
    registry.register_component<Component::Health>();
    registry.register_component<Component::Score>();

    registry.add_component<Component::Score>(entityTarget, Component::Score(0, std::nullptr_t()));
    registry.add_component<Component::Projectile>(entityProjectile, Component::Projectile(Component::Position(0, 10), Component::Position(10, 10), 10, 10, 2));
    registry.add_component<Component::Collision>(entityProjectile, Component::Collision(10, 10));
    registry.add_component<Component::Collision>(entityTarget, Component::Collision(10, 10));
    registry.add_component<Component::Health>(entityTarget, Component::Health(10));

    registry.add_system<Component::Projectile, Component::Collision, Component::Health, Component::Score>(ProjectileCollisionSystem());
    registry.add_system<Component::Health>(HealthSystem());

    registry.get_components<Component::Collision>()[entityProjectile].value().entities_in_collision.push_back(entityTarget);

    registry.run_systems();

    cr_assert_throw(registry.entity_from_index(entityTarget), std::runtime_error);
}
