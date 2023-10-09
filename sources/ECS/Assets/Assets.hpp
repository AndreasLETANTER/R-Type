/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Assets
*/

#pragma once

// Backgrounds
#include "assets/Space_Background.hpp"

// Players
#include "assets/SpaceShips.hpp"
#include "assets/BurpTemporaryBullet.hpp"

// Obstacles
#include "assets/GreyRobotObstacle.hpp"

// Enemies
#include "assets/OrangeCrabEnemy.hpp"
#include "assets/YellowPopcornEnemy.hpp"

#include <SFML/Graphics.hpp>


/// @brief The Assets class is used to store all the assets of the game.
class Assets {
    public:
        /// @brief The constructor of Assets, it loads all the assets.
        Assets();
        /// @brief The destructor of Assets.
        ~Assets() = default;

        /**
         * @brief Retrieves a texture by name.
         *
         * @param name The name of the texture to retrieve.
         * @return A reference to the texture.
         */
        sf::Texture &get_texture(const std::string &name);

    private:
        std::map<std::string, sf::Texture> m_textures;
};
