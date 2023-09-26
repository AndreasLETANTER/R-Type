/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Background
*/

#pragma once

#include <SFML/Graphics.hpp>

class Background {
    public:
        Background();
        void loadTexture(const unsigned char* data, std::size_t size);
        void setSize(sf::Vector2u windowSize);
        void draw(sf::RenderWindow& window);
        void move(float xOffset);
        void resetPosition();
    private:
        sf::Texture m_texture;
        sf::Texture m_texture_duplicated;
        sf::Sprite m_sprite;
        sf::Sprite m_sprite_duplicated;
};
