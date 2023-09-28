/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Drawable
*/

#pragma once
#include <SFML/Graphics.hpp>

namespace Component {
    /**
     * @brief This component represents an entity's drawable object.
     * 
     */
    typedef class Drawable {
        public:
            sf::Sprite sprite; /**< The sprite of the drawable object. */
            std::string spriteName; /**< The name of the sprite. */
            sf::RenderWindow *window; /**< The render window to draw the object on. */
            /**
             * @brief Construct a new Drawable object.
             * 
             * @param sprite The sprite of the drawable object.
             * @param window The render window to draw the object on.
             */
            inline Drawable(sf::Sprite sprite, sf::RenderWindow *window) { this->sprite = sprite; this->window = window; }
    } Drawable;
}
