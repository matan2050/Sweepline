#ifndef POINT2F_H
#define POINT2F_H

struct Point2f
{
    float x;
    float y;

    public:
    Point2f() {}
    Point2f(float _x, float _y);
    Point2f(const Point2f& other);
};

#endif