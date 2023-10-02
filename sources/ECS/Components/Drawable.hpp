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
            sf::IntRect rect; /**< The rectangle of the sprite. */
            Component::Position position; /**< The position of the drawable object. */
            sf::RenderWindow *window; /**< The render window to draw the object on. */
            /**
             * @brief Construct a new Drawable object.
             *
             * @param sprite The sprite of the drawable object.
             * @param window The render window to draw the object on.
             */
            Drawable(std::string spriteName, sf::RenderWindow *window, sf::IntRect rect, Component::Position position, bool needToLoadTexture);

        private:
            std::map<std::string, std::pair<const unsigned char *, std::size_t>> assets;
    } Drawable;
}
