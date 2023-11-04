/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Score
*/

#pragma once

/**
    * @brief Score component that holds the score of an entity.
    */
namespace Component {
    class Score {
        public:
            /**
             * @brief Default constructor for Score class.
             */
            Score() = default;

            int score;
            sf::Clock *clock;
            sf::Time lastScoreIncrease;

            /**
             * @brief Constructor for Score class.
             *
             * @param score The score of the entity.
             * @param clock A pointer to the clock used to measure time.
             */
            inline Score(int score, sf::Clock *clock) { this->score = score, this->clock = clock, this->lastScoreIncrease = clock->getElapsedTime(); }
    };
}
