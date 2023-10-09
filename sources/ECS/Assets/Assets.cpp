/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Assets
*/

#include "ECS/Assets/Assets.hpp"

Assets::Assets()
{
    m_textures["Space_Background.png"].loadFromMemory(___assets_Space_Background_png, ___assets_Space_Background_png_len);
    m_textures["SpaceShips.gif"].loadFromMemory(___assets_SpaceShips_gif, ___assets_SpaceShips_gif_len);
    m_textures["BurpTemporaryBullet.png"].loadFromMemory(___assets_BurpTemporaryBullet_png, ___assets_BurpTemporaryBullet_png_len);
    m_textures["GreyRobotObstacle.gif"].loadFromMemory(___assets_GreyRobotObstacle_gif, ___assets_GreyRobotObstacle_gif_len);
    m_textures["OrangeCrabEnemy.gif"].loadFromMemory(___assets_OrangeCrabEnemy_gif, ___assets_OrangeCrabEnemy_gif_len);
    m_textures["YellowPopcornEnemy.gif"].loadFromMemory(___assets_YellowPopcornEnemy_gif, ___assets_YellowPopcornEnemy_gif_len);
}

sf::Texture &Assets::get_texture(const std::string &name)
{
    return m_textures[name];
}
