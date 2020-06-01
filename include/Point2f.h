#ifndef _POINT2F_H_
#define _POINT2F_H_

class Point2f
{
    private:
    float x;
    float y;

    public:
    Point2f() {}
    Point2f(float _x, float _y);
    Point2f(const Point2f& other);
    
    float GetX() {return x;}
    float GetY() {return y;}
};

#endif