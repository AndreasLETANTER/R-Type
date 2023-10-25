/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** WaveSystem
*/

#include "WaveSystem.hpp"

WaveSystem WaveSystem::operator()(Registry &registry)
{
    unsigned int nb_enemies_for_wave = rand() % 4 + 3;

    if (registry.enemiesAreDead()) {
        for (unsigned int i = 0; i < nb_enemies_for_wave; i++) {
            auto enemy = registry.spawn_entity();

            registry.add_component<Component::Position>(enemy, Component::Position(1920, rand() % 1080));
            registry.add_component<Component::Velocity>(enemy, Component::Velocity(0, 0));
            registry.add_component<Component::Drawable>(enemy, Component::Drawable("OrangeCrabEnemy.gif", registry.getWindow(), sf::IntRect(0, 0, 0, 0), Component::Position(0, 0), registry.get_assets().get_texture("OrangeCrabEnemy.gif")));
            registry.add_component<Component::Health>(enemy, Component::Health(100));
        }
    }
    return *this;
}
