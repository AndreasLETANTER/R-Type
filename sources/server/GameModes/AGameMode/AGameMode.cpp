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
    tcpServer = std::make_unique<tcpSocket>(handleArgument.getPort(av[1]), handleArgument.getIp(av[3]));
    udpServer = std::make_unique<udpSocket>(handleArgument.getPort(av[2]), handleArgument.getIp(av[3]));
    m_isMultiplayer = isMultiplayer;
}

void AGameMode::create_player(int x, int y, int id)
{
    auto player = registry.spawn_entity();

    registry.add_component<Component::Position>(player, Component::Position(x, y));
    registry.add_component<Component::Velocity>(player, Component::Velocity(0, 0));
    registry.add_component<Component::Controllable>(player, Component::Controllable(true, id));
    registry.add_component<Component::Shoot>(player, Component::Shoot(id, true, LINEAR, &clock, sf::Time(sf::milliseconds(500)), damage, projectileAssetName, 1, 1920));
    registry.add_component<Component::Drawable>(player, Component::Drawable(assetName, &window, sf::IntRect(base.rectX, base.rectY, base.rectWidth, base.rectHeight), Component::Position(base.scaleX, base.scaleY), m_registry.get_assets().get_texture(base.assetName)));
    registry.add_component<Component::Collision>(m_registry.entity_from_index(base.id), Component::Collision(base.rectHeight, base.rectWidth));
    registry.add_component<Component::Health>(m_registry.entity_from_index(base.id), Component::Health(health));
    registry.add_component<Component::Score>(m_registry.entity_from_index(base.id), Component::Score(0, &clock));
}