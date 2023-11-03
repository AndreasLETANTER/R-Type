/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** AutoMoveSystem
*/

#include "ECS/Systems/AutoMoveSystem/AutoMoveSystem.hpp"
#include "ECS/Systems/AutoMoveSystem/MovePatterns/AMovePattern.hpp"
#include "ECS/Systems/AutoMoveSystem/MovePatterns/SemiCircularMovePattern.hpp"

AutoMoveSystem AutoMoveSystem::operator()(Registry &registry, SparseArray<Component::Position> &positions, SparseArray<Component::AutoMove> &autoMoves)
{
    (void) registry;
    for (size_t i = 0; i < positions.size() && i < autoMoves.size(); ++i) {
        auto &amv = autoMoves[i];
        auto &pos = positions[i];
        if (amv.has_value() && pos.has_value()) {
            //int dx = amv.value().end.x - pos.value().x;
            //int dy = amv.value().end.y - pos.value().y;
            //std::cout << "i: " << i << std::endl;
            //std::cout << "dx: " << dx << std::endl;
            //std::cout << "dy: " << dy << std::endl;
            std::cout << "x pos: " << pos.value().x << std::endl;
            std::cout << "y pos: " << pos.value().y << std::endl;
            auto movePattern = SemiCircularMovePattern(M_PI, 0.0f, pos, amv);
            movePattern.move(pos.value(), amv.value());
            std::cout << "new x pos: " << pos.value().x << std::endl;
            std::cout << "new y pos: " << pos.value().y << std::endl;
            //while(true) {}
            /* if (dx == 0 && dy == 0) {
                Component::Position tmp = amv.value().end;
                amv.value().end = amv.value().start;
                amv.value().start = tmp;
            } */
        }
    }
    return *this;
}

/* void AutoMoveSystem::moveInSinusoidalPattern(std::optional<Component::Position> &pos, int dx, int dy)
{
    int hypotenuse = sqrt(pow(dx, 2) + pow(dy, 2));
    double angle = getAngleFromCos(dx, hypotenuse);

    pos.value() = getNewPos(pos.value().x, pos.value().y, angle);
    std::cout << "new x pos: " << pos.value().x << std::endl;
    std::cout << "new y pos: " << pos.value().y << std::endl;
}   

Component::Position AutoMoveSystem::getNewPos(int x, int y, double angle)
{
    double new_x = x * cos(angle) - y * sin(angle);
    double new_y = x * sin(angle) + y * cos(angle);
    Component::Position new_pos(new_x, new_y);

    return new_pos;
}

double AutoMoveSystem::getAngleFromCos(int adjacent, int hypotenuse)
{
    return acos(adjacent / hypotenuse);
} */
