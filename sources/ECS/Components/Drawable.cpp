/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Drawable
*/

#include "Drawable.hpp"
#include "../Assets.hpp"

Component::Drawable::Drawable(std::string spriteName, sf::RenderWindow *window, bool needToLoadTexture)
{
    this->spriteName = spriteName;
    this->window = window;
    assets["NugoTemporaryIcon.png"] = std::make_pair(___assets_NugoTemporaryIcon_png, ___assets_NugoTemporaryIcon_png_len);
    assets["BurpTemporaryBullet.png"] = std::make_pair(___assets_BurpTemporaryBullet_png, ___assets_BurpTemporaryBullet_png_len);

    if (needToLoadTexture) {
        this->texture = std::make_shared<sf::Texture>();
        this->texture->loadFromMemory(assets[spriteName].first, assets[spriteName].second); 
        this->sprite.setTexture(*this->texture);
    }
}
