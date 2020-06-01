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

Point2f Segment2f::Intersect(const Segment2f& other)
{
    // Ax+By+C=0
    // Mx+Ny+Q=0
    
    // TODO add safeguards for case parameter is zero
    float first_coeff = other.A / A;
    float temp_B = B * first_coeff;
    float temp_C = C * first_coeff;

    float sum_B = temp_B - other.B;
    float sum_C = temp_C - other.C;

    float y = sum_C / sum_B;
    float x = -(B * y + C) / A;

    // TODO validate correctness
    return Point2f(x,y);
}

bool Segment2f::IsPointInSegmentBoundingBox(const Point2f point)
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