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
             * @brief Constructor for the Controllable component.
             * @param status The initial status of the component.
             */
            inline Controllable(bool status) { this->status = status; }
    };
}
