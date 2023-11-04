/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Drawable
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <map>

#include "Position.hpp"

namespace Component {
    /**
     * @brief This component represents an entity's drawable object.
     */
    typedef class Drawable {
        public:
            sf::Sprite sprite;
            std::shared_ptr<sf::Texture> texture;
            std::string spriteName;
            sf::IntRect rect;
            Component::Position scale;
            sf::RenderWindow *window;
            bool isBackground;

            /**
             * @brief Construct a new Drawable object.
             *
             * @param spriteName The sprite of the drawable object.
             * @param window The render window to draw the object on.
             * @param rect The rectangle of the sprite.
             * @param position The position of the drawable object.
             * @param texture The texture of the drawable object.
             * @param isBackground Whether the drawable object is a background or not.
             */
            Drawable(std::string spriteName, sf::RenderWindow *window, sf::IntRect rect, Component::Position position, std::shared_ptr<sf::Texture> texture, bool isBackground = false);

        private:
            std::map<std::string, std::pair<const unsigned char *, std::size_t>> assets;
    } Drawable;
}
