/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** ControlSystem
*/

#include <map>
#include <SFML/Window/Keyboard.hpp>

#include "ECS/Systems/ControlSystem/ControlSystem.hpp"

ControlSystem ControlSystem::operator()(Registry &registry, SparseArray<Component::Controllable> &controllables, SparseArray<Component::Velocity> &velocities)
{
    (void)registry;
    std::map<sf::Keyboard::Key, std::pair<int, int>> KeyMap;

    for (size_t i = 0; i < controllables.size() && i < velocities.size(); ++i) {
        auto &con = controllables[i];
        auto &vel = velocities[i];
        if (con.has_value() && con.value().status && vel.has_value()) {
            KeyMap[sf::Keyboard::Z] = std::make_pair(0, -vel.value().speed);
            KeyMap[sf::Keyboard::S] = std::make_pair(0, vel.value().speed);
            KeyMap[sf::Keyboard::Q] = std::make_pair(-vel.value().speed, 0);
            KeyMap[sf::Keyboard::D] = std::make_pair(vel.value().speed, 0);
            vel.value().vx = 0;
            vel.value().vy = 0;
            for (auto &key : con.value().m_keyMapState) {
                if (key.second == true) {
                    vel.value().vx += KeyMap[key.first].first;
                    vel.value().vy += KeyMap[key.first].second;
                }
            }
        }
    }
    return *this;
}
