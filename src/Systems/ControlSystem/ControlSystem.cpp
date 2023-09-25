/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** ControlSystem
*/

#include "ControlSystem.hpp"
#include <SFML/Graphics.hpp>

ControlSystem ControlSystem::operator()(Registry &registry, SparseArray<Component::Controllable> &controllables, SparseArray<Component::Velocity> &velocities)
{
    (void)registry;
    for (size_t i = 0; i < controllables.size() && i < velocities.size(); ++i) {
        auto &con = controllables[i];
        auto &vel = velocities[i];
        if (con.has_value() && con.value().status && vel.has_value()) {
            vel.value().vx = 0;
            vel.value().vy = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                vel.value().vy = -5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                vel.value().vy = 5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                vel.value().vx = -5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                vel.value().vx = 5;
            }
        }
    }
    return *this;
}