/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Group
*/

#pragma once

namespace Component {
    /**
     * @brief This component is used to represent the group of an entity (generally used for separating players and enemies)
     */
    class Group {
        public:
            Group() = default;
            unsigned int groupId;

            /**
             * @brief Constructor for Group that sets the group ID
             *
             * @param id The ID of the group
             */
            inline Group(unsigned int id) { this->groupId = id; }
    };
}
