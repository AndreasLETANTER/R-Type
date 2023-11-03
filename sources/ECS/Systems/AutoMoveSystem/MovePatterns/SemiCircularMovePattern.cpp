/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** SemiCircularMovePattern
*/

#include "SemiCircularMovePattern.hpp"
#include <iostream>

SemiCircularMovePattern::SemiCircularMovePattern(double angleStart, double angleEnd, std::optional<Component::Position> entityPos, std::optional<Component::AutoMove> &amv)
{
    this->circleCount = amv.value().circleCount;
    setDiameter(getDistancetoTravel(amv.value().start, amv.value().end) / this->circleCount);
    setRadius(this->diameter / 2);
    // this->dx = amv.value().end.x - entityPos.value().x;
    // this->dy = amv.value().end.y - entityPos.value().y;
    this->dx = amv.value().end.x - amv.value().start.x;
    this->dy = amv.value().end.y - amv.value().start.y;
    std::cout << entityPos.value().x << " " << entityPos.value().y << std::endl;
    std::cout << "dx: " << dx << std::endl;
    std::cout << "dy: " << dy << std::endl;
    //exit(0);
    //this->angle = amv.value().browsedDistance;
    setCircleAngle(angleStart, angleEnd);
    if (!amv.value().isEntityMoving) {
        amv.value().browsedDistance = circleAngleStart;
        std::cout << "browsed distance: " << amv.value().browsedDistance << std::endl;
        amv.value().isEntityMoving = true;
    }
    this->actualAngle = amv.value().browsedDistance;
    std::cout << "actual angle: " << this->actualAngle << std::endl;
    //this->circleIndex = amv.value().shapeIndex;
    setCirclesCenter(amv.value());
    //exit(0);
    //this->isEntityMovingForward = amv.value().isEntityMovingForward;
}

void SemiCircularMovePattern::setDiameter(double diameter)
{
    this->diameter = diameter;
}

double SemiCircularMovePattern::getDiameter()
{
    return this->diameter;
}

void SemiCircularMovePattern::setRadius(double radius)
{
    this->radius = radius;
}

double SemiCircularMovePattern::getRadius()
{
    return this->radius;
}

void SemiCircularMovePattern::setCircleAngle(double angleStart, double angleEnd)
{
    if (dx > 0) {
        this->circleAngleStart = angleStart;
        this->circleAngleEnd = angleEnd;
    } else if (dx < 0) {
        this->circleAngleStart = angleEnd;
        this->circleAngleEnd = angleStart;
    }
}

double SemiCircularMovePattern::getXAxisDistance()
{
    return this->dx;
}

double SemiCircularMovePattern::getYAxisDistance()
{
    return this->dy;
}

void SemiCircularMovePattern::setCirclesCenter(Component::AutoMove &amv)
{
    for (int i = 0; i < circleCount; i++) {
        Component::Position pos;
        pos.x = (amv.start.x + ((this->dx / this->circleCount) / 2)) + ((this->dx / this->circleCount) * i);
        pos.y = (amv.start.y + ((this->dy / this->circleCount) / 2)) + ((this->dy / this->circleCount) * i);
        this->circlesCenter.push_back(pos);
        std::cout << "circle center: " << pos.x << " " << pos.y << std::endl;
    }
}

std::vector<Component::Position> SemiCircularMovePattern::getCirclesCenter()
{
    return this->circlesCenter;
}

void SemiCircularMovePattern::move(Component::Position &entityPos, Component::AutoMove &amv)
{
    //std::cout << "is entity moving forward: " << amv.isEntityMovingForward << std::endl;
    sf::Time elapsedTimeSinceLastMove = amv.clock->getElapsedTime() - amv.lastMove;
    std::cout << "elapsed time since last move: " << elapsedTimeSinceLastMove.asSeconds() << std::endl;
    std::cout << "amv last move: " << amv.lastMove.asSeconds() << std::endl;
    std::cout << "amv clock: " << amv.clock->getElapsedTime().asSeconds() << std::endl;

    /* if (amv.isEntityMovingForward) {
        if (amv.shapeIndex < circleCount) {
            std::cout << "circle angle start: " << circleAngleStart << std::endl;
            std::cout << "circle angle end: " << circleAngleEnd << std::endl;
            std::cout << "shape index: " << amv.shapeIndex << std::endl;
            std::cout << "actual angle: " << this->actualAngle << std::endl;
            if (elapsedTimeSinceLastMove.asSeconds() >= 0.001) {
                if (dx > 0) {
                    std::cout << "to the right" << std::endl;
                    this->actualAngle -= 1 * elapsedTimeSinceLastMove.asSeconds();
                } else if (dx < 0) {
                    std::cout << "to the left" << std::endl;
                    this->actualAngle += 1 * elapsedTimeSinceLastMove.asSeconds();
                }
                amv.browsedDistance = this->actualAngle;
                entityPos.x = circlesCenter[amv.shapeIndex].x + this->radius * cos(this->actualAngle);
                entityPos.y = circlesCenter[amv.shapeIndex].y + this->radius * sin(this->actualAngle);
                //amv.browsedDistance += 1 * elapsedTimeSinceLastMove.asSeconds();
                amv.lastMove = amv.clock->getElapsedTime();
            }
            if (dx > 0 && this->actualAngle <= circleAngleEnd) {
                amv.browsedDistance = circleAngleStart;
                amv.shapeIndex += 1;
            } else if (dx < 0 && this->actualAngle >= circleAngleEnd) {
                amv.browsedDistance = circleAngleStart;
                amv.shapeIndex += 1;
            }
        } else {
            Component::Position tmp = amv.end;
            amv.end = amv.start;
            amv.start = tmp;
            amv.isEntityMovingForward = false;
            amv.shapeIndex -= 1;
            amv.browsedDistance = circleAngleEnd;
            std::cout << "end position : " << amv.end.x << " " << amv.end.y << std::endl;
            std::cout << "start position : " << amv.start.x << " " << amv.start.y << std::endl;
            std::cout << "shape index: " << amv.shapeIndex << std::endl;
            std::cout << "actual angle: " << amv.browsedDistance << std::endl;
            std::cout << "is entity moving forward: " << amv.isEntityMovingForward << std::endl;
            std::cout << "changed direction" << std::endl;
            //exit(0);
        }
    } else {
        if (amv.shapeIndex >= 0) {
            std::cout << "circle angle start: " << circleAngleStart << std::endl;
            std::cout << "circle angle end: " << circleAngleEnd << std::endl;
            std::cout << "shape index: " << amv.shapeIndex << std::endl;
            std::cout << "actual angle: " << this->actualAngle << std::endl;
            if (elapsedTimeSinceLastMove.asSeconds() >= 0.1) {
                if (dx > 0) {
                    std::cout << "to the left" << std::endl;
                    this->actualAngle += 0.1 * elapsedTimeSinceLastMove.asSeconds();
                } else if (dx < 0) {
                    std::cout << "to the right" << std::endl;
                    this->actualAngle -= 0.1 * elapsedTimeSinceLastMove.asSeconds();
                }
                amv.browsedDistance = this->actualAngle;
                entityPos.x = circlesCenter[amv.shapeIndex].x + this->radius * cos(this->actualAngle);
                entityPos.y = circlesCenter[amv.shapeIndex].y + this->radius * sin(this->actualAngle);
                //amv.browsedDistance += 1 * elapsedTimeSinceLastMove.asSeconds();
                amv.lastMove = amv.clock->getElapsedTime();
            }
            if (dx > 0 && this->actualAngle >= circleAngleEnd) {
                amv.browsedDistance = circleAngleStart;
                amv.shapeIndex += 1;
            } else if (dx < 0 && this->actualAngle <= circleAngleEnd) {
                amv.browsedDistance = circleAngleStart;
                amv.shapeIndex += 1;
            }
            //exit(0);
        } else {
            Component::Position tmp = amv.end;
            amv.end = amv.start;
            amv.start = tmp;
            amv.isEntityMovingForward = true;
            amv.shapeIndex = 0;
            this->actualAngle = circleAngleStart;
        }
    } */
    if (amv.shapeIndex < circleCount) {
        //std::cout << "circle angle start: " << circleAngleStart << std::endl;
        //std::cout << "circle angle end: " << circleAngleEnd << std::endl;
        std::cout << "shape index: " << amv.shapeIndex << std::endl;
        std::cout << "actual angle: " << this->actualAngle << std::endl;
        if (elapsedTimeSinceLastMove.asSeconds() >= 0.001) {
            std::cout << "elapsed time since last move: " << elapsedTimeSinceLastMove.asSeconds() << std::endl;
            if (dx > 0) {
                std::cout << "to the right" << std::endl;
                this->actualAngle -= 1 * elapsedTimeSinceLastMove.asSeconds();
            } else if (dx < 0) {
                std::cout << "to the left" << std::endl;
                this->actualAngle += 1 * elapsedTimeSinceLastMove.asSeconds();
            }
            amv.browsedDistance = this->actualAngle;
            std::cout << "actual angle: " << this->actualAngle << std::endl;
            entityPos.x = circlesCenter[amv.shapeIndex].x + this->radius * cos(this->actualAngle);
            entityPos.y = circlesCenter[amv.shapeIndex].y - this->radius * sin(this->actualAngle);
            //amv.browsedDistance += 1 * elapsedTimeSinceLastMove.asSeconds();
            amv.lastMove = amv.clock->getElapsedTime();
        }
        if (dx > 0 && this->actualAngle <= circleAngleEnd) {
            amv.browsedDistance = circleAngleStart;
            amv.shapeIndex += 1;
            //exit(0);
            //while (1) {}
        } else if (dx < 0 && this->actualAngle >= circleAngleEnd) {
            amv.browsedDistance = circleAngleStart;
            amv.shapeIndex += 1;
        }
    } else {
        Component::Position tmp = amv.end;
        amv.end = amv.start;
        amv.start = tmp;
        //amv.isEntityMovingForward = false;
        //amv.shapeIndex -= 1;
        amv.shapeIndex = 0;
        amv.browsedDistance = circleAngleEnd;
        setCirclesCenter(amv);
        std::cout << "\nchanged direction\n" << std::endl;
        std::cout << "end position : " << amv.end.x << " " << amv.end.y << std::endl;
        std::cout << "start position : " << amv.start.x << " " << amv.start.y << std::endl;
        std::cout << "shape index: " << amv.shapeIndex << std::endl;
        std::cout << "actual angle: " << amv.browsedDistance << std::endl;
        std::cout << "is entity moving forward: " << amv.isEntityMovingForward << std::endl;
    }
    
}
