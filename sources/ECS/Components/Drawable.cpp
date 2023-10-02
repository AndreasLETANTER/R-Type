/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Drawable
*/

#include "Drawable.hpp"
#include "../Assets.hpp"

Component::Drawable::Drawable(std::string spriteName, sf::RenderWindow *window, sf::IntRect rect, Component::Position position, bool needToLoadTexture)
{
    this->spriteName = spriteName;
    this->window = window;
    this->rect = rect;
    this->position = position;
    assets["Space_Background.png"] = std::make_pair(___assets_Space_Background_png, ___assets_Space_Background_png_len);
    assets["SpaceShips.gif"] = std::make_pair(___assets_SpaceShips_gif, ___assets_SpaceShips_gif_len);
    assets["BurpTemporaryBullet.png"] = std::make_pair(___assets_BurpTemporaryBullet_png, ___assets_BurpTemporaryBullet_png_len);

    if (needToLoadTexture) {
        this->texture = std::make_shared<sf::Texture>();
        this->texture->loadFromMemory(assets[spriteName].first, assets[spriteName].second);
        this->sprite.setTexture(*this->texture);
    }
    if (this->position.x != this->window->getSize().x && this->position.y != this->window->getSize().y
    && this->position.x != 0 && this->position.y != 0) {
        this->sprite.setTextureRect(this->rect);
    }
    if (this->position.x != 0 || this->position.y != 0) {
        float scaleX = static_cast<float>(this->position.x) / this->rect.width;
        float scaleY = static_cast<float>(this->position.y) / this->rect.height;

        this->sprite.setScale(scaleX, scaleY);
    }
}
