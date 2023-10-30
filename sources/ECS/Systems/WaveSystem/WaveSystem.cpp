/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** WaveSystem
*/

#include "WaveSystem.hpp"

WaveSystem WaveSystem::operator()(Registry &registry)
{
    std::vector<Component::EntityClass> m_enemy_vector;
    std::vector<Component::EntityClass> m_boss_vector;
    m_enemy_vector.push_back(Component::EntityClassFactory::CreateEntityClass(EntityClasses::MOB_ORANGE_CRAB));
    m_enemy_vector.push_back(Component::EntityClassFactory::CreateEntityClass(EntityClasses::MOB_YELLOW_POPCORN));
    static unsigned int current_wave_index = 20;
    unsigned int nb_enemies_for_wave = rand() % 6 + current_wave_index  + 3 + current_wave_index;

    if (registry.enemiesAreDead()) {
        for (unsigned int i = 0; i < nb_enemies_for_wave; i++) {
            unsigned int enemy_type = rand() % m_enemy_vector.size();
            unsigned int x_offset = rand() % (2000 - 1920) + 1 + 1920 + (i * 100);
            unsigned int x_start = rand() % (1000 - 400) + 1 + 400;
            unsigned int y_start = rand() % 1000;
            auto enemy = registry.spawn_entity();

            Component::EntityClass entityClassTmp = m_enemy_vector[enemy_type];
            registry.add_component<Component::Group>(enemy, Component::Group(2));
            registry.add_component<Component::Position>(enemy, Component::Position(x_offset, y_start));
            registry.add_component<Component::Velocity>(enemy, Component::Velocity(0, 0, entityClassTmp.speed));
            registry.add_component<Component::Shoot>(enemy, Component::Shoot(0, true, entityClassTmp.shootingPattern, registry.getClock(), sf::Time(sf::milliseconds(entityClassTmp.shootingDelay)), entityClassTmp.damage, entityClassTmp.projectileAssetName, -1, 0));
            registry.add_component<Component::Drawable>(enemy, Component::Drawable(entityClassTmp.assetName, registry.getWindow(), sf::IntRect(entityClassTmp.rect.left, entityClassTmp.rect.top, entityClassTmp.rect.width, entityClassTmp.rect.height), Component::Position(entityClassTmp.scale.x, entityClassTmp.scale.y), registry.get_assets().get_texture(entityClassTmp.assetName)));
            registry.add_component<Component::Collision>(enemy, Component::Collision(entityClassTmp.rect.height, entityClassTmp.rect.width));
            registry.add_component<Component::AutoMove>(enemy, Component::AutoMove(Component::Position(x_start, y_start), Component::Position(x_start - 300, y_start)));
            registry.add_component<Component::Health>(enemy, Component::Health(entityClassTmp.health));
        }
        current_wave_index += 1;
    }
    return *this;
}
