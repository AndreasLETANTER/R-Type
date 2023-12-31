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

Test(Registry, basic_importFromMessages)
{
    Registry reg;
    Registry importReg;
    TextButton button;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();
    reg.register_component<Component::Score>();

    importReg.register_component<Component::Position>();
    importReg.register_component<Component::Velocity>();
    importReg.register_component<Component::Drawable>();
    importReg.register_component<Component::Score>();
    auto entity1 = reg.spawn_entity();
    reg.add_component<Component::Position>(entity1, Component::Position(0, 0));
    reg.add_component<Component::Velocity>(entity1, Component::Velocity(0, 0, 0));
    reg.add_component<Component::Drawable>(entity1, Component::Drawable("PBulletNugo.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), reg.get_assets().get_texture("NugoBullet.png")));

    std::vector<packet_t> packets = reg.exportToPackets();

    for (unsigned int i = 0; i < packets.size(); i++) {
        importReg.updateFromPacket(packets[i], nullptr, button);
    }

    auto &positions = importReg.get_components<Component::Position>();
    auto &drawables = importReg.get_components<Component::Drawable>();

    cr_assert_eq(positions.size(), 1);
    cr_assert_eq(drawables.size(), 1);
    cr_assert_eq(positions[0].value().x, 0);
    cr_assert_eq(positions[0].value().y, 0);
    cr_assert_eq(strcmp(drawables[0].value().spriteName.c_str(), "PBulletNugo.png"), 0);
}

Test(Registry, 2_spawn_importFromMessages)
{
    Registry reg;
    Registry importReg;
    TextButton button;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();
    reg.register_component<Component::Score>();

    importReg.register_component<Component::Position>();
    importReg.register_component<Component::Velocity>();
    importReg.register_component<Component::Drawable>();
    importReg.register_component<Component::Score>();
    auto entity1 = reg.spawn_entity();
    reg.add_component<Component::Position>(entity1, Component::Position(0, 0));
    reg.add_component<Component::Velocity>(entity1, Component::Velocity(0, 0, 0));
    reg.add_component<Component::Drawable>(entity1, Component::Drawable("PBulletNugo.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), reg.get_assets().get_texture("NugoBullet.png")));

    auto entity2 = reg.spawn_entity();
    reg.add_component<Component::Position>(entity2, Component::Position(1, 1));
    reg.add_component<Component::Velocity>(entity2, Component::Velocity(0, 0, 0));
    reg.add_component<Component::Drawable>(entity2, Component::Drawable("PBulletNugo.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), reg.get_assets().get_texture("NugoBullet.png")));

    std::vector<packet_t> packets = reg.exportToPackets();

    for (unsigned int i = 0; i < packets.size(); i++) {
        importReg.updateFromPacket(packets[i], nullptr, button);
    }
    auto &positions = importReg.get_components<Component::Position>();
    auto &drawables = importReg.get_components<Component::Drawable>();

    cr_assert_eq(positions.size(), 2);
    cr_assert_eq(drawables.size(), 2);
    cr_assert_eq(positions[0].value().x, 0);
    cr_assert_eq(positions[0].value().y, 0);
    cr_assert_eq(positions[1].value().x, 1);
    cr_assert_eq(positions[1].value().y, 1);
    cr_assert_eq(strcmp(drawables[0].value().spriteName.c_str(), "PBulletNugo.png"), 0);
    cr_assert_eq(strcmp(drawables[1].value().spriteName.c_str(), "PBulletNugo.png"), 0);
}

Test(Registry, 50_spawn_importFromMessages)
{
    Registry reg;
    Registry importReg;
    TextButton button;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();
    reg.register_component<Component::Score>();

    importReg.register_component<Component::Position>();
    importReg.register_component<Component::Velocity>();
    importReg.register_component<Component::Drawable>();
    importReg.register_component<Component::Score>();

    for (int i = 0; i < 50; i++) {
        auto entity = reg.spawn_entity();
        reg.add_component<Component::Position>(entity, Component::Position(i, i));
        reg.add_component<Component::Velocity>(entity, Component::Velocity(0, 0, 0));
        reg.add_component<Component::Drawable>(entity, Component::Drawable("PBulletNugo.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), reg.get_assets().get_texture("NugoBullet.png")));
    }

    std::vector<packet_t> packets = reg.exportToPackets();

    for (unsigned int i = 0; i < packets.size(); i++) {
        importReg.updateFromPacket(packets[i], nullptr, button);
    }

    auto &positions = importReg.get_components<Component::Position>();
    auto &drawables = importReg.get_components<Component::Drawable>();

    for (int i = 0; i < 50; i++) {
        cr_assert_eq(positions[i].value().x, i);
        cr_assert_eq(positions[i].value().y, i);
        cr_assert_eq(strcmp(drawables[i].value().spriteName.c_str(), "PBulletNugo.png"), 0);
    }
}

Test(Registry, 800_spawn_importFromMessages)
{
    Registry reg;
    Registry importReg;
    TextButton button;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();
    reg.register_component<Component::Score>();

    importReg.register_component<Component::Position>();
    importReg.register_component<Component::Velocity>();
    importReg.register_component<Component::Drawable>();
    importReg.register_component<Component::Score>();

    for (int i = 0; i < 800; i++) {
        auto entity = reg.spawn_entity();
        reg.add_component<Component::Position>(entity, Component::Position(i, i));
        reg.add_component<Component::Velocity>(entity, Component::Velocity(0, 0, 0));
        reg.add_component<Component::Drawable>(entity, Component::Drawable("PBulletNugo.png", nullptr, sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), reg.get_assets().get_texture("NugoBullet.png")));
    }

    std::vector<packet_t> packets = reg.exportToPackets();

    for (unsigned int i = 0; i < packets.size(); i++) {
        importReg.updateFromPacket(packets[i], nullptr, button);
    }

    auto &positions = importReg.get_components<Component::Position>();
    auto &drawables = importReg.get_components<Component::Drawable>();

    for (int i = 0; i < 800; i++) {
        cr_assert_eq(positions[i].value().x, i);
        cr_assert_eq(positions[i].value().y, i);
        cr_assert_eq(strcmp(drawables[i].value().spriteName.c_str(), "PBulletNugo.png"), 0);
    }
}

Test(Registry, no_spawn_importFromMessages)
{
    Registry reg;
    TextButton button;

    reg.register_component<Component::Position>();
    reg.register_component<Component::Velocity>();
    reg.register_component<Component::Drawable>();
    reg.register_component<Component::Score>();

    std::vector<packet_t> packets = reg.exportToPackets();

    Registry importReg;
    importReg.register_component<Component::Position>();
    importReg.register_component<Component::Velocity>();
    importReg.register_component<Component::Drawable>();
    importReg.register_component<Component::Score>();
    for (unsigned int i = 0; i < packets.size(); i++) {
        importReg.updateFromPacket(packets[i], nullptr, button);
    }

    auto &positions = importReg.get_components<Component::Position>();
    auto &drawables = importReg.get_components<Component::Drawable>();

    cr_assert_eq(positions.size(), 0);
    cr_assert_eq(drawables.size(), 0);
}
