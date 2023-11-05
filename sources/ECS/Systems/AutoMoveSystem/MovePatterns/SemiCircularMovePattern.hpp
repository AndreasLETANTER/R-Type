/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** SemiCircularMovePattern
*/

#pragma once
#include "AMovePattern.hpp"
#include <vector>

class SemiCircularMovePattern : public AMovePattern {
    public:
        SemiCircularMovePattern(std::optional<Component::AutoMove> &amv);
        ~SemiCircularMovePattern() = default;
        void setDiameter(double diameter);
        double getDiameter();
        void setRadius(double radius);
        double getRadius();
        void setCircleAngle(double angleStart, double angleEnd);
        double getXAxisDistance();
        double getYAxisDistance();
        void setCirclesCenter(Component::AutoMove &amv);
        std::vector<Component::Position> getCirclesCenter();
        void calculateOrientationAngle();
        void move(Component::Position &entityPos, Component::AutoMove &amv);
    protected:
    private:
        double circleCount; /**< The amount of circles to be browsed by the entity*/
        double diameter; /**< The diameter of the circle to be browsed by the entity*/
        double radius; /**< The radius of the circle to be browsed by the entity*/
        double dx; /**< The distance to travel on the x axis*/
        double dy; /**< The distance to travel on the y axis*/
        double circleAngleStart; /**< The starting value of the angle of the circle to be browsed by the entity*/
        double circleAngleEnd; /**< The maximum angle of the circle to be browsed by the entity*/
        double actualAngle; /**< The actual angle of the circle to be browsed by the entity*/
        double orientationAngle; /**< The orientation angle of the entity's move curve*/
        std::vector<Component::Position> circlesCenter; /**< The center of the circles to be browsed by the entity*/
};
