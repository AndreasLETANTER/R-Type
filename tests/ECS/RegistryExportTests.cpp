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

Test(Registry, basic_exportToPackets)
{
    Registry reg;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();
    reg.register_component<Component::Score>();

    auto entity1 = reg.spawn_entity();
    reg.add_component<Component::Position>(entity1, Component::Position(0, 0));
    reg.add_component<Component::Velocity>(entity1, Component::Velocity(0, 0, 0));
    reg.add_component<Component::Drawable>(entity1, Component::Drawable("NugoBullet.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), reg.get_assets().get_texture("NugoBullet.png")));

    std::vector<packet_t> packets = reg.exportToPackets();

    cr_assert_eq(strcmp(packets[0].message.sprite_name, "NugoBullet.png"), 0);
    cr_assert_eq(packets[0].message.x, 0);
    cr_assert_eq(packets[0].message.y, 0);
    cr_assert_eq(packets.size(), 2);
}

Test(Registry, 2_spawn_exportToPackets)
{
    Registry reg;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();
    reg.register_component<Component::Score>();

    auto entity1 = reg.spawn_entity();
    auto entity2 = reg.spawn_entity();
    reg.add_component<Component::Position>(entity1, Component::Position(0, 0));
    reg.add_component<Component::Velocity>(entity1, Component::Velocity(0, 0, 0));
    reg.add_component<Component::Drawable>(entity1, Component::Drawable("NugoBullet.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), reg.get_assets().get_texture("NugoBullet.png")));
    reg.add_component<Component::Position>(entity2, Component::Position(3, 5));
    reg.add_component<Component::Velocity>(entity2, Component::Velocity(0, 0, 0));
    reg.add_component<Component::Drawable>(entity2, Component::Drawable("NugoBullet.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), reg.get_assets().get_texture("NugoBullet.png")));

    std::vector<packet_t> packets = reg.exportToPackets();

    cr_assert_eq(strcmp(packets[0].message.sprite_name, "NugoBullet.png"), 0);
    cr_assert_eq(packets[0].message.x, 0);
    cr_assert_eq(packets[0].message.y, 0);
    cr_assert_eq(strcmp(packets[1].message.sprite_name, "NugoBullet.png"), 0);
    cr_assert_eq(packets[1].message.x, 3);
    cr_assert_eq(packets[1].message.y, 5);
    cr_assert_eq(packets.size(), 4);
}

Test(Registry, 50_spawn_exportToPackets)
{
    Registry reg;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();
    reg.register_component<Component::Score>();

    for (int i = 0; i < 50; i++) {
        auto entity = reg.spawn_entity();
        reg.add_component<Component::Position>(entity, Component::Position(i, i));
        reg.add_component<Component::Velocity>(entity, Component::Velocity(0, 0, 0));
        reg.add_component<Component::Drawable>(entity, Component::Drawable("NugoBullet.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), reg.get_assets().get_texture("NugoBullet.png")));
    }

    std::vector<packet_t> packets = reg.exportToPackets();

    for (int i = 0; i < 50; i++) {
        cr_assert_eq(strcmp(packets[i].message.sprite_name, "NugoBullet.png"), 0);
        cr_assert_eq(packets[i].message.x, i);
        cr_assert_eq(packets[i].message.y, i);
    }
    cr_assert_eq(packets.size(), 100);
}

Test(Registry, 800_spawn_exportToPackets)
{
    Registry reg;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();
    reg.register_component<Component::Score>();

    for (int i = 0; i < 800; i++) {
        auto entity = reg.spawn_entity();
        reg.add_component<Component::Position>(entity, Component::Position(i, i));
        reg.add_component<Component::Velocity>(entity, Component::Velocity(0, 0, 0));
        reg.add_component<Component::Drawable>(entity, Component::Drawable("NugoBullet.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), reg.get_assets().get_texture("NugoBullet.png")));
    }

    std::vector<packet_t> packets = reg.exportToPackets();

    for (int i = 0; i < 800; i++) {
        cr_assert_eq(strcmp(packets[i].message.sprite_name, "NugoBullet.png"), 0);
        cr_assert_eq(packets[i].message.x, i);
        cr_assert_eq(packets[i].message.y, i);
    }
    cr_assert_eq(packets.size(), 1600);
}

Test(Registry, no_spawn_exportToPackets)
{
    Registry reg;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();
    reg.register_component<Component::Score>();

    std::vector<packet_t> packets = reg.exportToPackets();

    cr_assert_eq(packets.size(), 0);
}
