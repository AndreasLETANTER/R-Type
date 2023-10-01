/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Background
*/

#include "client/Background/Background.hpp"

void Background::loadTexture(const unsigned char* data, std::size_t size)
{
    m_texture.loadFromMemory(data, size);
    m_sprite.setTexture(m_texture);
    m_texture_duplicated.loadFromMemory(data, size);
    m_sprite_duplicated.setTexture(m_texture_duplicated);
}

void Background::setSize(sf::Vector2u windowSize)
{
    sf::IntRect desiredRect(0, 0, 300, 207);
    float scaleX = static_cast<float>(windowSize.x) / desiredRect.width;
    float scaleY = static_cast<float>(windowSize.y) / desiredRect.height;

    m_sprite.setScale(scaleX, scaleY);
    m_sprite.setPosition(0, 0);
    m_sprite_duplicated.setScale(scaleX, scaleY);
    m_sprite_duplicated.setPosition(5700, 0);
}

void Background::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
    window.draw(m_sprite_duplicated);
}

void Background::move(float xOffset)
{
    m_sprite.move(xOffset, 0.0f);
    m_sprite_duplicated.move(xOffset, 0.0f);
}

void Background::resetPosition()
{
    if (m_sprite.getPosition().x <= -5700 && m_sprite_duplicated.getPosition().x <= 0) {
        m_sprite.setPosition(0.0f, 0.0f);
        m_sprite_duplicated.setPosition(5700.0f, 0.0f);
    }
}
