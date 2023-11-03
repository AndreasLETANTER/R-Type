/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Drawable
*/

#include "Drawable.hpp"
#include "ECS/Assets/Assets.hpp"

#include <iostream>

Component::Drawable::Drawable(std::string spriteName, sf::RenderWindow *window, sf::IntRect rect, Component::Position scale, std::shared_ptr<sf::Texture> texture, bool isBackground)
{
    this->spriteName = spriteName;
    this->window = window;
    this->rect = rect;
    this->scale = scale;

    this->texture = texture;
    this->sprite.setTexture(*this->texture);
    if (static_cast<unsigned int>(this->rect.left) != 0 || static_cast<unsigned int>(this->rect.top) != 0) {
        this->sprite.setTextureRect(this->rect);
    }
    if (this->scale.x != 0 || this->scale.y != 0) {
        float scaleX = static_cast<float>(this->scale.x) / this->rect.width;
        float scaleY = static_cast<float>(this->scale.y) / this->rect.height;

        this->sprite.setScale(scaleX, scaleY);
    }
}
