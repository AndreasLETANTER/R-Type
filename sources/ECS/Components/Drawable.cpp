/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Drawable
*/

#include "Drawable.hpp"
#include "../Assets.hpp"

#include <iostream>

Component::Drawable::Drawable(std::string spriteName, sf::RenderWindow *window, sf::IntRect rect, Component::Position scale, bool needToLoadTexture)
{
    this->spriteName = spriteName;
    this->window = window;
    this->rect = rect;
    this->scale = scale;
    assets["Space_Background.png"] = std::make_pair(___assets_Space_Background_png, ___assets_Space_Background_png_len);
    assets["SpaceShips.gif"] = std::make_pair(___assets_SpaceShips_gif, ___assets_SpaceShips_gif_len);
    assets["BurpTemporaryBullet.png"] = std::make_pair(___assets_BurpTemporaryBullet_png, ___assets_BurpTemporaryBullet_png_len);
    assets["GreyRobotObstacle.gif"] = std::make_pair(___assets_GreyRobotObstacle_gif, ___assets_GreyRobotObstacle_gif_len);
    assets["OrangeCrabEnemy.gif"] = std::make_pair(___assets_OrangeCrabEnemy_gif, ___assets_OrangeCrabEnemy_gif_len);
    assets["YellowPopcornEnemy.gif"] = std::make_pair(___assets_YellowPopcornEnemy_gif, ___assets_YellowPopcornEnemy_gif_len);
    assets["NugoTemporaryIcon.png"] = std::make_pair(___assets_NugoTemporaryIcon_png, ___assets_NugoTemporaryIcon_png_len);

    if (needToLoadTexture) {
        std::cout << "Loading texture: " << spriteName << std::endl;
        std::cout << "Texture length: " << spriteName.length() << std::endl;
        this->texture = std::make_shared<sf::Texture>();
        this->texture->loadFromMemory(assets[spriteName].first, assets[spriteName].second);
        this->sprite.setTexture(*this->texture);
    }
    if (static_cast<unsigned int>(this->rect.left) != 0 || static_cast<unsigned int>(this->rect.top) != 0) {
        this->sprite.setTextureRect(this->rect);
    }
    if (this->scale.x != 0 || this->scale.y != 0) {
        float scaleX = static_cast<float>(this->scale.x) / this->rect.width;
        float scaleY = static_cast<float>(this->scale.y) / this->rect.height;

        this->sprite.setScale(scaleX, scaleY);
    }
}
