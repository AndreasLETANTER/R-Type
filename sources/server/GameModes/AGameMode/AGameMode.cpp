/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AGameMode
*/

#include "AGameMode.hpp"

#include "ECS/Systems/LoggingSystem/LoggingSystem.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"
#include "ECS/Systems/ControlSystem/ControlSystem.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Systems/AutoMoveSystem/AutoMoveSystem.hpp"
#include "ECS/Systems/ShootSystem/ShootSystem.hpp"
#include "ECS/Systems/ProjectileSystem/ProjectileSystem.hpp"
#include "ECS/Systems/CollisionSystem/CollisionSystem.hpp"
#include "ECS/RegistryClass/Registry.hpp"
#include "ECS/Systems/ScrollSystem/ScrollSystem.hpp"
#include "ECS/Systems/HealthSystem/HealthSystem.hpp"
#include "ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.hpp"
#include "ECS/Systems/ScoreSystem/ScoreSystem.hpp"

AGameMode::AGameMode(const char **av, int ac, bool isMultiplayer) : handleArgument()
{
    if (ac != 4) {
        throw std::runtime_error("AGameMode: Invalid number of arguments");
    }
    try {
        tcpServer = std::make_unique<tcpSocket>(handleArgument.getPort(av[1]), handleArgument.getIp(av[3]));
        udpServer = std::make_unique<udpSocket>(handleArgument.getPort(av[2]), handleArgument.getIp(av[3]));
    }
    catch(const std::exception& e) {
        std::cerr << "Error when running the tcp and udp server, " << e.what() << '\n';
        exit(84);
    }
    m_isMultiplayer = isMultiplayer;
}

void AGameMode::create_player(int x, int y, int id, EntityClasses classEnum)
{
    auto player = registry.spawn_entity();
    Component::EntityClass entityClassTmp = Component::EntityClassFactory::CreateEntityClass(classEnum);

    registry.add_component<Component::EntityClass>(player, Component::EntityClassFactory::CreateEntityClass(classEnum));
    registry.add_component<Component::Position>(player, Component::Position(x, y));
    registry.add_component<Component::Velocity>(player, Component::Velocity(0, 0, entityClassTmp.speed));
    registry.add_component<Component::Controllable>(player, Component::Controllable(true, id));
    registry.add_component<Component::Shoot>(player, Component::Shoot(id, true, LINEAR, &clock, sf::Time(sf::milliseconds(entityClassTmp.shootingDelay)), entityClassTmp.damage, entityClassTmp.projectileAssetName, 1, 1920));
    registry.add_component<Component::Drawable>(player, Component::Drawable(entityClassTmp.assetName, &window, sf::IntRect(entityClassTmp.rect.left, entityClassTmp.rect.top, entityClassTmp.rect.width, entityClassTmp.rect.height), Component::Position(entityClassTmp.scale.x, entityClassTmp.scale.y), registry.get_assets().get_texture(entityClassTmp.assetName)));
    registry.add_component<Component::Collision>(player, Component::Collision(entityClassTmp.rect.height, entityClassTmp.rect.width));
    registry.add_component<Component::Health>(player, Component::Health(entityClassTmp.health));
    registry.add_component<Component::Score>(player, Component::Score(0, &clock));
}

void AGameMode::create_background()
{
    auto background = registry.spawn_entity();
    registry.add_component<Component::Position>(background, Component::Position(0, 0));
    registry.add_component<Component::Drawable>(background, Component::Drawable("SpaceBackground.png", &window, sf::IntRect(0, 0, 300, 207), Component::Position(1920, 1080), registry.get_assets().get_texture("SpaceBackground.png")));
    registry.add_component<Component::Scroll>(background, Component::Scroll(Component::Position(0, 0), Component::Position(-5700, 0), 0));

    background = registry.spawn_entity();
    registry.add_component<Component::Position>(background, Component::Position(5700, 0));
    registry.add_component<Component::Drawable>(background, Component::Drawable("SpaceBackground.png", &window, sf::IntRect(0, 0, 300, 207), Component::Position(1920, 1080), registry.get_assets().get_texture("SpaceBackground.png")));
    registry.add_component<Component::Scroll>(background, Component::Scroll(Component::Position(0, 0), Component::Position(0, 0), 0));
}