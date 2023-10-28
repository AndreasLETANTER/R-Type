/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Controllable
*/

#pragma once

namespace Component {
    /**
     * @brief A component that represents whether an entity is controllable or not.
     */
    class Controllable {
        public:
            /**
             * @brief The status of the controllable component.
             */
            bool status;
            /**
             * @brief The ID of the player controlling the entity.
             */
            unsigned int playerId;

            /**
             * @brief The key map of the controllable component.
             */
            std::map<sf::Keyboard::Key, bool> m_keyMapState = {
                {sf::Keyboard::Z, false},
                {sf::Keyboard::S, false},
                {sf::Keyboard::Q, false},
                {sf::Keyboard::D, false},
                {sf::Keyboard::Space, false}
            };

            /**
             * @brief Constructor for the Controllable component.
             * @param status The initial status of the component.
             * @param playerId The ID of the player controlling the entity.
             */
            inline Controllable(bool status, unsigned int playerId) { this->status = status; this->playerId = playerId; }
    };
}
