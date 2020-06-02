#include <math.h>
#include "../include/SharedDefinitions.h"
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

Point2f Segment2f::Intersect(const Segment2f& other) const
{
    // Ax+By+C=0
    // Mx+Ny+Q=0
    // solve x and y
    // TODO add safeguards for case parameter is zero
    
    float x,y;
    if (abs(A) < EPSILON)
    {
        if (abs(B) < EPSILON)
        {
            // return illegal point - no intersection
            return Point2f(INFINITY, INFINITY);
        }

        y = C / B;

        if (abs(other.A) < EPSILON)
        {
            // return illegal point - no intersection
            return Point2f(INFINITY, INFINITY);
        }

        x = -(other.C + other.B * y) / other.A;
    }

    float first_coeff = other.A / A;
    float temp_B = B * first_coeff;
    float temp_C = C * first_coeff;

    float sum_B = temp_B - other.B;
    float sum_C = temp_C - other.C;

    y = sum_C / sum_B;
    x = -(B * y + C) / A;

    // TODO validate correctness
    return Point2f(x,y);
}

bool Segment2f::IsPointInSegmentBoundingBox(const Point2f& point) const
{
    if (point.GetX() >= start.GetX() && 
        point.GetX() <= end.GetX() &&
        point.GetY() >= start.GetY() &&
        point.GetY() <= end.GetY())
        {
            return true;
        }
        
    return false;
}