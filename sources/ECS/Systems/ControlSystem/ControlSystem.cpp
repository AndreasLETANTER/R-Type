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

    KeyMap[sf::Keyboard::Z] = std::make_pair(0, -5);
    KeyMap[sf::Keyboard::S] = std::make_pair(0, 5);
    KeyMap[sf::Keyboard::Q] = std::make_pair(-5, 0);
    KeyMap[sf::Keyboard::D] = std::make_pair(5, 0);
    for (size_t i = 0; i < controllables.size() && i < velocities.size(); ++i) {
        auto &con = controllables[i];
        auto &vel = velocities[i];
        if (con.has_value() && con.value().status && vel.has_value()) {
            vel.value().vx = 0;
            vel.value().vy = 0;
            if (KeyMap.find(con.value().keyPressed) == KeyMap.end())
                continue;
            vel.value().vx += KeyMap[con.value().keyPressed].first;
            vel.value().vy += KeyMap[con.value().keyPressed].second;
        }
    }
    return *this;
}
