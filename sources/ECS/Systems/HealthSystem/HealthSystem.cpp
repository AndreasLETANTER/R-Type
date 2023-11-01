/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HealthSystem
*/

#include "ECS/Systems/HealthSystem/HealthSystem.hpp"
#include "ECS/Components/EntityClass.hpp"

#include "ECS/Components/Drawable.hpp"

HealthSystem HealthSystem::operator()(Registry &registry, SparseArray<Component::Health> &healths, SparseArray<Component::Position> &positions)
{
    auto &drawables = registry.get_components<Component::Drawable>();
    for (size_t i = 0; i < healths.size(); ++i)
    {
        auto &health = healths[i];
        auto &pos = positions[i];
        auto &draw = drawables[i];

        if (health.has_value() && health.value().health <= 0) {
            if (pos.has_value() && draw.has_value() && rand() % 100 <= 15) {
                auto entity = registry.spawn_entity();
                Component::EntityClass entityClassTmp = Component::EntityClassFactory::CreateEntityClass(EntityClasses(rand() % 3 + 6));
                int xPosDiff = (draw.value().sprite.getScale().x - entityClassTmp.scale.x) / 2;
                int yPosDiff = (draw.value().sprite.getScale().y - entityClassTmp.scale.y) / 2;

                xPosDiff = xPosDiff < 0 ? -xPosDiff : xPosDiff;
                yPosDiff = yPosDiff < 0 ? -yPosDiff : yPosDiff;

                registry.add_component<Component::Group>(entity, Component::Group(3));
                registry.add_component<Component::Position>(entity, Component::Position(pos.value().x + xPosDiff, pos.value().y + yPosDiff));
                registry.add_component<Component::Drawable>(entity, Component::Drawable(entityClassTmp.assetName, registry.getWindow(), sf::IntRect(entityClassTmp.rect.left, entityClassTmp.rect.top, entityClassTmp.rect.width, entityClassTmp.rect.height), Component::Position(entityClassTmp.scale.x, entityClassTmp.scale.y), registry.get_assets().get_texture(entityClassTmp.assetName)));
                registry.add_component<Component::Collision>(entity, Component::Collision(entityClassTmp.scale.y, entityClassTmp.scale.x));
                registry.add_component<Component::PowerUp>(entity, Component::PowerUp(entityClassTmp.delayForDispawn, entityClassTmp.powerUpType, registry.getClock(), entityClassTmp.stat));
            }
            registry.kill_entity(registry.entity_from_index(i));
        }
    }
    return *this;
}
