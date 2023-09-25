#include <SFML/Graphics.hpp>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    sf::Texture texture;
    texture.loadFromFile("assets/Space_Background.png");
    sf::Sprite sprite(texture);
    sf::IntRect desiredRect(0, 0, 300, 207);
    float scaleX = static_cast<float>(window.getSize().x) / desiredRect.width;
    float scaleY = static_cast<float>(window.getSize().y) / desiredRect.height;

    sprite.setScale(scaleX, scaleY);
    sprite.setPosition(0, 0);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
