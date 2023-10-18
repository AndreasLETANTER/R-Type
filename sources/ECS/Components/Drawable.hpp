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
     *
     */
    typedef class Drawable {
        public:
            sf::Sprite sprite; /**< The sprite of the drawable object. */
            std::shared_ptr<sf::Texture> texture; /**< The texture of the drawable object. */
            std::string spriteName; /**< The name of the sprite. */
            sf::IntRect textureRect; /**< The rectangle of the texture. */
            sf::IntRect textureOffsetRect; /**< The offset rectangle of the texture. */
            Component::Position scale; /**< The scale values of the drawable object. */
            sf::RenderWindow *window; /**< The render window to draw the object on. */

            /**
             * @brief Construct a new Drawable object.
             *
             * @param sprite The sprite of the drawable object.
             * @param window The render window to draw the object on.
             * @param rect The rectangle of the sprite.
             * @param position The position of the drawable object.
             * @param texture The texture of the drawable object.
             */
            Drawable(std::string spriteName, sf::RenderWindow *window, sf::IntRect textureRect, sf::IntRect textureOffsetRect, Component::Position position, std::shared_ptr<sf::Texture> texture);

        private:
            std::map<std::string, std::pair<const unsigned char *, std::size_t>> assets;
    } Drawable;
}
