/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Background
*/

#include "Background.hpp"

Background::Background()
{}

void Background::loadTexture(const unsigned char* data, std::size_t size)
{
    m_texture.loadFromMemory(data, size);
    m_sprite.setTexture(m_texture);
}

void Background::setSize(sf::Vector2u windowSize)
{
    sf::IntRect desiredRect(0, 0, 300, 207);
    float scaleX = static_cast<float>(windowSize.x) / desiredRect.width;
    float scaleY = static_cast<float>(windowSize.y) / desiredRect.height;

    m_sprite.setScale(scaleX, scaleY);
    m_sprite.setPosition(0, 0);
}

void Background::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

void Background::move(float xOffset)
{
    m_sprite.move(xOffset, 0.0f);
}

void Background::resetPosition()
{
    if (m_sprite.getPosition().x <= -m_sprite.getLocalBounds().width) {
        m_sprite.setPosition(0.0f, 0.0f);
    }
}
