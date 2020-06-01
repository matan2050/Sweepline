#include <iostream>

#include "../include/Point2f.h"
#include "../include/Segment2f.h"

int main()
{
    Point2f pnt_a = Point2f(100.0f, 2500.0f);
    Point2f pnt_b = Point2f(600.0f, 1042.0f);
    std::cout << "point a" << pnt_a.GetX() << ", " << pnt_a.GetY() << "\n";
    std::cout << "point b" << pnt_b.GetX() << ", " << pnt_b.GetY() << "\n";

    Segment2f seg_a = Segment2f(10,20,30,10,20,30,40);

    return 0;
}