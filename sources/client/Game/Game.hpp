/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Game
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "client/Background/Background.hpp"

/**
 * @class Game
 * @brief Represents the main game loop and manages the game state.
 */
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

		sf::RenderWindow m_window; /**< The main game window. */
		Background m_background; /**< The game background. */
		float m_timeAccumulator; /**< The time accumulator used to update the game state. */
		float m_scrollSpeed; /**< The speed at which the background scrolls. */
		sf::Clock m_clock; /**< The game clock used to measure time. */
};
