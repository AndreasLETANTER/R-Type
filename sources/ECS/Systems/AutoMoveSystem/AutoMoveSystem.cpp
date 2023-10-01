/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** AutoMoveSystem
*/

#include "ECS/Systems/AutoMoveSystem/AutoMoveSystem.hpp"

AutoMoveSystem AutoMoveSystem::operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::AutoMove> &autoMoves)
{
    (void) registry;
    for (size_t i = 0; i < positions.size() && i < autoMoves.size(); ++i) {
        auto &amv = autoMoves[i];
        auto &pos = positions[i];
        if (amv.has_value() && pos.has_value()) {
            int dx = amv.value().end.x - pos.value().x;
            int dy = amv.value().end.y - pos.value().y;

            pos.value().x += dx > 0 ? 1 : -1;
            pos.value().y += dy > 0 ? 1 : -1;
            if (amv.value().end.x == pos.value().x && amv.value().end.y == pos.value().y) {
                Component::Position tmp = amv.value().end;
                amv.value().end = amv.value().start;
                amv.value().start = tmp;
            }
        }
    }
    return *this;
}
