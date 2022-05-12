#ifndef SEGMENT2F_H
#define SEGMENT2F_H

#include "Point2f.h"

struct Segment2f
{    
    // line representation A*x+B*y+c=0
    float A;
    float B;
    float C;

    Point2f start;
    Point2f end;

    Segment2f();
    Segment2f(float a, float b, float c, float x_start, float y_start, float x_end, float y_end);
    Segment2f(const Segment2f& copied);    

    Point2f Intersect(const Segment2f& other) const;
    bool IsPointInSegmentBoundingBox(const Point2f& point) const;
};

#endif