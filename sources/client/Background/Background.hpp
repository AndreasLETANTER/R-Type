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
        /**
         * @brief The Background class represents the background of the game.
         */
        Background() = default;

        /**
         * @brief Loads a texture from the given data.
         *
         * @param data Pointer to the data containing the texture.
         * @param size Size of the data in bytes.
         */
        void loadTexture(const unsigned char* data, std::size_t size);

        /**
         * @brief Sets the size of the background to match the size of the window.
         *
         * @param windowSize The size of the window as a 2D vector of unsigned integers.
         */
        void setSize(sf::Vector2u windowSize);

        /**
         * @brief Draws the background on the given window.
         *
         * @param window The window to draw the background on.
         */
        void draw(sf::RenderWindow& window);
    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
};
