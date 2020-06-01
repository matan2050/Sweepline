#include "../include/Point2f.h"

Point2f::Point2f(float _x, float _y)
{
    x = _x;
    y = _y;
}

Point2f::Point2f(const Point2f& other)
{
    x = other.x;
    y = other.y;
}