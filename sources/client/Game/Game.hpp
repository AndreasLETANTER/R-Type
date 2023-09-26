/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Game
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "../Background/Background.hpp"

class Game {
    public:
        /**
         * @brief Constructs a new Game object.
         */
        Game();

        /**
         * @brief Runs the game loop.
         */
        void run();
    private:
        /**
         * @brief Processes all events in the event queue.
         */
        void processEvents();

        /**
         * @brief Performs the parallax effect by moving the background layers at different speeds.
         *
         * This function is called every frame to update the position of the background layers
         * based on the current camera position. The parallax effect is achieved by moving the
         * layers at different speeds, creating an illusion of depth and movement.
         */
        void doParallax();

        /**
         * @brief Renders the game state to the screen.
         *
         * This method is responsible for rendering the current game state to the screen.
         * It should be called once per frame to ensure that the screen is updated with the
         * latest game state.
         */
        void render();

        sf::RenderWindow m_window;
        Background m_background;
        float m_timeAccumulator;
        float m_scrollSpeed;
        sf::Clock m_clock;
};
