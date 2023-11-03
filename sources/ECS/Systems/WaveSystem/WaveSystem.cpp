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
    m_enemy_vector.push_back(Component::EntityClassFactory::CreateEntityClass(EntityClasses::MOB_GREEN_PLANT));
    m_enemy_vector.push_back(Component::EntityClassFactory::CreateEntityClass(EntityClasses::MOB_BLUE_D));
    m_boss_vector.push_back(Component::EntityClassFactory::CreateEntityClass(EntityClasses::FIRST_BOSS));
    static unsigned int current_wave_index = 1;
    unsigned int nb_enemies_for_wave = rand() % 3 + current_wave_index + current_wave_index;

    if (registry.enemiesAreDead()) {
        if (current_wave_index % 3 == 0) {
            unsigned int enemy_type = rand() % m_boss_vector.size();
            Component::EntityClass entityClassTmp = m_boss_vector[enemy_type];
            unsigned int x_offset = rand() % (2000 - 1920) + 1 + 1920;
            unsigned int x_start = 1920 - entityClassTmp.scale.x;
            unsigned int y_start = 1080 / 2 - entityClassTmp.scale.y / 2;
            auto enemy = registry.spawn_entity();

            registry.add_component<Component::Group>(enemy, Component::Group(2));
            registry.add_component<Component::Position>(enemy, Component::Position(x_offset, y_start));
            registry.add_component<Component::Velocity>(enemy, Component::Velocity(0, 0, entityClassTmp.speed));
            registry.add_component<Component::Shoot>(enemy, Component::Shoot(0, true, entityClassTmp.shootingPattern, registry.getClock(), sf::Time(sf::milliseconds(entityClassTmp.shootingDelay)), entityClassTmp.damage, entityClassTmp.projectileAssetName, -1, 0));
            registry.add_component<Component::Drawable>(enemy, Component::Drawable(entityClassTmp.assetName, registry.getWindow(), sf::IntRect(entityClassTmp.rect.left, entityClassTmp.rect.top, entityClassTmp.rect.width, entityClassTmp.rect.height), Component::Position(entityClassTmp.scale.x, entityClassTmp.scale.y), registry.get_assets().get_texture(entityClassTmp.assetName)));
            registry.add_component<Component::Collision>(enemy, Component::Collision(entityClassTmp.scale.y, entityClassTmp.scale.x));
            registry.add_component<Component::Scroll>(enemy, Component::Scroll(Component::Position(x_offset, y_start), Component::Position(0, 0), x_start));
            registry.add_component<Component::Health>(enemy, Component::Health(entityClassTmp.health));
        } else {
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
                registry.add_component<Component::Collision>(enemy, Component::Collision(entityClassTmp.scale.y, entityClassTmp.scale.x));
                registry.add_component<Component::AutoMove>(enemy, Component::AutoMove(Component::Position(x_start, y_start), Component::Position(x_start - 300, y_start)));
                registry.add_component<Component::Health>(enemy, Component::Health(entityClassTmp.health));
            }
        }
        current_wave_index += 1;
    }
    return *this;
}
