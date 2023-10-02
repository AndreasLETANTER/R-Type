/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Drawable
*/

#include "Drawable.hpp"
#include "../Assets.hpp"

Component::Drawable::Drawable(std::string spriteName, sf::RenderWindow *window, sf::IntRect rect, bool needToLoadTexture, bool needToScale)
{
    this->spriteName = spriteName;
    this->window = window;
    this->rect = rect;
    assets["Space_Background.png"] = std::make_pair(___assets_Space_Background_png, ___assets_Space_Background_png_len);
    assets["NugoTemporaryIcon.png"] = std::make_pair(___assets_NugoTemporaryIcon_png, ___assets_NugoTemporaryIcon_png_len);
    assets["BurpTemporaryBullet.png"] = std::make_pair(___assets_BurpTemporaryBullet_png, ___assets_BurpTemporaryBullet_png_len);

    if (needToLoadTexture) {
        this->texture = std::make_shared<sf::Texture>();
        this->texture->loadFromMemory(assets[spriteName].first, assets[spriteName].second);
        this->sprite.setTexture(*this->texture);
    }
    if (needToScale) {
        float scaleX = static_cast<float>(this->window->getSize().x) / this->rect.width;
        float scaleY = static_cast<float>(this->window->getSize().y) / this->rect.height;

        this->sprite.setScale(scaleX, scaleY);
    }
}
