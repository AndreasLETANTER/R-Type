/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Animation
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>

namespace Component {
    class Animation {
        public:
            /**
             * @brief Construct a new Animation object
             * 
             * @param sprite A sprite to animate
             * @param rect A part of the sprite to animate, in pixels
             */
            inline Animation(sf::IntRect textureRect, sf::IntRect textureOffsetRect, std::shared_ptr<sf::Texture> texture, sf::Clock *clock) { m_textureRect = textureRect; m_textureOffsetRect = textureOffsetRect; m_texture = texture; m_clock = clock; m_lastTime = m_clock->getElapsedTime(); }
            std::shared_ptr<sf::Texture> m_texture;
            sf::IntRect m_textureRect;
            sf::IntRect m_textureOffsetRect;
            sf::Clock *m_clock;
            sf::Time m_lastTime;
            ~Animation() = default;
    };
}