#include "../include/Point2f.h"
#include "../include/Segment2f.h"

Segment2f::Segment2f(float a, float b, float c, float x_start, float y_start, float x_end, float y_end)
{
    A = a;
    B = b;
    C = c;

    start = Point2f(x_start, y_start);
    end = Point2f(x_end, y_end);
}

Segment2f::Segment2f(const Segment2f& other)
{
    A = other.A;
    B = other.B;
    C = other.C;

    start = other.start;
    end = other.end;
}