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
        /**
         * @brief Default constructor for Score class.
         */
        Score() = default;
        int score;
        /**
         * @brief Constructor for Score class.
         * @param score The score of the entity.
         */
        inline Score(int score) { this->score = score; }
    };
}
