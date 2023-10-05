/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Registry
*/

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#include <criterion/criterion.h>
#include "../../sources/ECS/EntityClass/Entity.hpp"
#include "../../sources/ECS/SparseArrayClass/SparseArray.hpp"
#include "../../sources/ECS/RegistryClass/Registry.hpp"
#include "../../sources/ECS/Components/Position.hpp"
#include "../../sources/ECS/Components/Velocity.hpp"
#include "../../sources/ECS/Components/Drawable.hpp"

Test(Registry, basic_exportToMessages)
{
    Registry reg;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();

    auto entity1 = reg.spawn_entity();
    reg.add_component<Component::Position>(entity1, Component::Position(0, 0));
    reg.add_component<Component::Velocity>(entity1, Component::Velocity(0, 0));
    reg.add_component<Component::Drawable>(entity1, Component::Drawable("NugoTemporaryIcon.png", &window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), false));

    message_t *messages = reg.exportToMessages().first;
    size_t size = reg.exportToMessages().second;

    cr_assert_eq(strcmp(messages[0].sprite_name, "NugoTemporaryIcon.png"), 0);
    cr_assert_eq(messages[0].x, 0);
    cr_assert_eq(messages[0].y, 0);
    cr_assert_eq(size, 1);
}

Test(Registry, 2_spawn_exportToMessages)
{
    Registry reg;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();

    auto entity1 = reg.spawn_entity();
    auto entity2 = reg.spawn_entity();
    reg.spawn_entity();
    reg.add_component<Component::Position>(entity1, Component::Position(0, 0));
    reg.add_component<Component::Velocity>(entity1, Component::Velocity(0, 0));
    reg.add_component<Component::Drawable>(entity1, Component::Drawable("NugoTemporaryIcon.png", &window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), false));
    reg.add_component<Component::Position>(entity2, Component::Position(3, 5));
    reg.add_component<Component::Velocity>(entity2, Component::Velocity(0, 0));
    reg.add_component<Component::Drawable>(entity2, Component::Drawable("ZBOUBZBOUB.png", &window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), false));

    message_t *messages = reg.exportToMessages().first;
    size_t size = reg.exportToMessages().second;

    cr_assert_eq(strcmp(messages[0].sprite_name, "NugoTemporaryIcon.png"), 0);
    cr_assert_eq(messages[0].x, 0);
    cr_assert_eq(messages[0].y, 0);
    cr_assert_eq(strcmp(messages[1].sprite_name, "ZBOUBZBOUB.png"), 0);
    cr_assert_eq(messages[1].x, 3);
    cr_assert_eq(messages[1].y, 5);
    cr_assert_eq(size, 2);
}

Test(Registry, 50_spawn_exportToMessages)
{
    Registry reg;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();

    for (int i = 0; i < 50; i++) {
        auto entity = reg.spawn_entity();
        reg.add_component<Component::Position>(entity, Component::Position(i, i));
        reg.add_component<Component::Velocity>(entity, Component::Velocity(0, 0));
        reg.add_component<Component::Drawable>(entity, Component::Drawable("NugoTemporaryIcon.png", &window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), false));
    }

    message_t *messages = reg.exportToMessages().first;
    size_t size = reg.exportToMessages().second;

    for (int i = 0; i < 50; i++) {
        cr_assert_eq(strcmp(messages[i].sprite_name, "NugoTemporaryIcon.png"), 0);
        cr_assert_eq(messages[i].x, i);
        cr_assert_eq(messages[i].y, i);
    }
    cr_assert_eq(size, 50);
}

Test(Registry, 800_spawn_exportToMessages)
{
    Registry reg;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();

    for (int i = 0; i < 800; i++) {
        auto entity = reg.spawn_entity();
        reg.add_component<Component::Position>(entity, Component::Position(i, i));
        reg.add_component<Component::Velocity>(entity, Component::Velocity(0, 0));
        reg.add_component<Component::Drawable>(entity, Component::Drawable("NugoTemporaryIcon.png", &window, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), false));
    }

    message_t *messages = reg.exportToMessages().first;
    size_t size = reg.exportToMessages().second;

    for (int i = 0; i < 800; i++) {
        cr_assert_eq(strcmp(messages[i].sprite_name, "NugoTemporaryIcon.png"), 0);
        cr_assert_eq(messages[i].x, i);
        cr_assert_eq(messages[i].y, i);
    }
    cr_assert_eq(size, 800);
}

Test(Registry, no_spawn_exportToMessages)
{
    Registry reg;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();

    size_t size = reg.exportToMessages().second;

    cr_assert_eq(size, 0);
}
