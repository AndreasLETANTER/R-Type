/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** SemiCircularMovePattern
*/

#include "SemiCircularMovePattern.hpp"
#include <iostream>

SemiCircularMovePattern::SemiCircularMovePattern(std::optional<Component::AutoMove> &amv)
{
    this->circleCount = amv.value().circleCount;
    setDiameter(getDistancetoTravel(amv.value().start, amv.value().end) / this->circleCount);
    setRadius(this->diameter / 2);
    this->dx = amv.value().end.x - amv.value().start.x;
    this->dy = amv.value().end.y - amv.value().start.y;
    calculateOrientationAngle();
    setCircleAngle(M_PI, 0.0f);
    if (!amv.value().isEntityMoving) {
        amv.value().browsedDistance = circleAngleStart;
        amv.value().isEntityMoving = true;
    }
    this->actualAngle = amv.value().browsedDistance;
    setCirclesCenter(amv.value());
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
        if (dy > 0) {
            this->circleAngleStart = angleStart - this->orientationAngle;
            this->circleAngleEnd = angleEnd - this->orientationAngle;
        } else if (dy < 0)
        {
            this->circleAngleStart = angleStart + this->orientationAngle;
            this->circleAngleEnd = angleEnd + this->orientationAngle;
        } else {
            this->circleAngleStart = angleStart;
            this->circleAngleEnd = angleEnd;
        }
    } else if (dx < 0) {
        if (dy > 0) {
            this->circleAngleStart = angleEnd + this->orientationAngle;
            this->circleAngleEnd = angleStart + this->orientationAngle;
        } else if (dy < 0) {
            this->circleAngleStart = angleEnd - this->orientationAngle;
            this->circleAngleEnd = angleStart - this->orientationAngle;
        } else {
            this->circleAngleStart = angleEnd;
            this->circleAngleEnd = angleStart;
        }
    } else {
        if (dy > 0) {
            this->circleAngleStart = angleStart - (M_PI / 2);
            this->circleAngleEnd = angleEnd - (M_PI / 2);
        } else if (dy < 0) {
            this->circleAngleStart = angleEnd - (M_PI / 2);
            this->circleAngleEnd = angleStart - (M_PI / 2);
        } else {
            this->circleAngleStart = angleStart;
            this->circleAngleEnd = angleEnd;
        }
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
    }
}

std::vector<Component::Position> SemiCircularMovePattern::getCirclesCenter()
{
    return this->circlesCenter;
}

void SemiCircularMovePattern::calculateOrientationAngle()
{
    this->orientationAngle = atan2(abs(this->dy), abs(this->dx));
}

void SemiCircularMovePattern::move(Component::Position &entityPos, Component::AutoMove &amv)
{
    sf::Time elapsedTimeSinceLastMove = amv.clock->getElapsedTime() - amv.lastMove;

    if (amv.shapeIndex < circleCount) {
        if (elapsedTimeSinceLastMove.asSeconds() >= 0.001) {
            if (dx > 0 || dy > 0) {
                this->actualAngle -= 1 * amv.speed * elapsedTimeSinceLastMove.asSeconds();
            } else if (dx < 0 || dy < 0) {
                this->actualAngle += 1 * amv.speed * elapsedTimeSinceLastMove.asSeconds();
            }
            amv.browsedDistance = this->actualAngle;
            entityPos.x = circlesCenter[amv.shapeIndex].x + this->radius * cos(this->actualAngle);
            entityPos.y = circlesCenter[amv.shapeIndex].y - this->radius * sin(this->actualAngle);
            amv.lastMove = amv.clock->getElapsedTime();
        }
        if (dx > 0 && this->actualAngle <= circleAngleEnd) {
            amv.browsedDistance = circleAngleStart;
            amv.shapeIndex += 1;
        } else if (dx < 0 && this->actualAngle >= circleAngleEnd) {
            amv.browsedDistance = circleAngleStart;
            amv.shapeIndex += 1;
        } else {
            if (dy > 0 && this->actualAngle <= circleAngleEnd) {
                amv.browsedDistance = circleAngleStart;
                amv.shapeIndex += 1;
            } else if (dy < 0 && this->actualAngle >= circleAngleEnd) {
                amv.browsedDistance = circleAngleStart;
                amv.shapeIndex += 1;
            }
        }
    } else {
        Component::Position tmp = amv.end;
        amv.end = amv.start;
        amv.start = tmp;
        amv.shapeIndex = 0;
        amv.browsedDistance = circleAngleEnd;
        setCirclesCenter(amv);
    }
    
}
