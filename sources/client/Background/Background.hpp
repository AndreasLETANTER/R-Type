/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Background
*/

#pragma once

#include <SFML/Graphics.hpp>

/**
 * @class Background
 * @brief The Background class represents the background of the game.
 */
class Background {
    public:
        /**
         * @brief Constructs a new Background object.
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

        /**
         * @brief Moves the background by the given x offset.
         *
         * @param xOffset The x offset to move the background by.
         */
        void move(float xOffset);

        /**
         * @brief Resets the position of the background to its initial position.
         */
        void resetPosition();
    private:
        sf::Texture m_texture; /**< The texture of the background. */
        sf::Texture m_texture_duplicated; /**< The duplicated texture of the background. */
        sf::Sprite m_sprite; /**< The sprite of the background. */
        sf::Sprite m_sprite_duplicated; /**< The duplicated sprite of the background. */
};
