/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Assets
*/

#pragma once

// Backgrounds
#include "../../build/assets/Space_Background.hpp"

// Players
#include "../../build/assets/SpaceShips.hpp"
#include "../../build/assets/BurpTemporaryBullet.hpp"

// Obstacles
#include "../../build/assets/GreyRobotObstacle.hpp"

// Enemies
#include "../../build/assets/OrangeCrabEnemy.hpp"
#include "../../build/assets/YellowPopcornEnemy.hpp"

// Icons
#include "../../build/assets/NugoTemporaryIcon.hpp"

#include <SFML/Graphics.hpp>

class Assets {
    public:
        Assets();
        ~Assets() = default;
    private:
        std::map<std::string, sf::Texture> m_textures;
};
