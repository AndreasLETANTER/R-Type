/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** AnimationSystem
*/

#include "ECS/Systems/AnimationSystem/AnimationSystem.hpp"
#include "ECS/Components/Drawable.hpp"

AnimationSystem AnimationSystem::operator()(Registry &registry, SparseArray<Component::Animation> &animations, SparseArray<Component::Drawable> &drawables)
{
    (void)registry;
    for (size_t i = 0; i < animations.size(); i++) {
        auto &animation = animations[i];
        auto &drawable = drawables[i];
        sf::Time delay = sf::seconds(0.1);
        sf::Time elapsed_seconds;
        
        if (animation.has_value()) {
            elapsed_seconds = animation.value().m_clock->getElapsedTime() - animation.value().m_lastTime;
            //std::cout << "elapsed seconds: " << elapsed_seconds.asSeconds() << std::endl;
            if (elapsed_seconds.asSeconds() > delay.asSeconds()) {
                std::cout << "elapsed seconds > delay" << std::endl;
                for (int j = elapsed_seconds.asSeconds() / delay.asSeconds(); j > 0; j--) {
                    std::cout << "j: " << j << std::endl;
                    animation.value().m_rect.left += animation.value().m_rect.width;
                    if (animation.value().m_rect.left >= (int)animation.value().m_texture->getSize().x || animation.value().m_rect.left + animation.value().m_rect.width > (int)animation.value().m_texture->getSize().x)
                        animation.value().m_rect.left = 0;
                }
                std::cout << "rect left after for loop: " << animation.value().m_rect.left << std::endl;
                animation.value().m_lastTime = (elapsed_seconds % delay) + animation.value().m_clock->getElapsedTime();
                std::cout << "last time: " << animation.value().m_lastTime.asSeconds() << "\n" << std::endl;
                std::cout << "sprite rect left: " << drawable.value().sprite.getTextureRect().left << std::endl;
                drawable.value().rect = animation.value().m_rect;  
            }
        }
    }

    return *this;
}
