/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Assets
*/

#include "ECS/Assets/Assets.hpp"
#include <iostream>

Assets::Assets()
{
    this->load_texture("BurpTemporaryBullet.png", "assets/BurpTemporaryBullet.png");
    this->load_texture("GreyRobotObstacle.gif", "assets/GreyRobotObstacle.gif");
    this->load_texture("OrangeCrabEnemy.gif", "assets/OrangeCrabEnemy.gif");
    this->load_texture("Space_Background.png", "assets/Space_Background.png");
    this->load_texture("SpaceShips.gif", "assets/SpaceShips.gif");
    this->load_texture("YellowPopcornEnemy.gif", "assets/YellowPopcornEnemy.gif");

    this->load_font("font.ttf", "assets/font.ttf");
}

std::shared_ptr<sf::Texture> &Assets::get_texture(const std::string &name)
{
    if (m_textures.find(name) == m_textures.end()) {
        throw std::runtime_error{"Texture: " + name + " not found"};
    }
    return m_textures[name];
}

sf::Font &Assets::get_font(const std::string &name)
{
    if (m_fonts.find(name) == m_fonts.end()) {
        throw std::runtime_error{"Font: " + name + " not found"};
    }
    return m_fonts[name];
}

void Assets::load_texture(const std::string &name, const std::string &path)
{
    auto texture = m_fs.open(path);
    if (texture.size() == 0) {
        throw std::runtime_error{"Texture file: " + path + " not found"};
    }
    m_textures[name] = std::make_shared<sf::Texture>();
    m_textures[name]->loadFromMemory(texture.begin(), texture.size());
}

void Assets::load_font(const std::string &name, const std::string &path)
{
    auto font = m_fs.open(path);
    if (font.size() == 0) {
        throw std::runtime_error{"Font file " + path + " not found"};
    }
    m_fonts[name] = sf::Font();
    m_fonts[name].loadFromMemory(font.begin(), font.size());
}
