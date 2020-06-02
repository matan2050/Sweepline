#ifndef _SEGMENT2F_H_
#define _SEGMENT2F_H_

#include "Point2f.h"

class Segment2f
{
    private:
    
    // line representation A*x+B*y+c=0
    float A;
    float B;
    float C;

    Point2f start;
    Point2f end;

    public:
    Segment2f();
    Segment2f(float a, float b, float c, float x_start, float y_start, float x_end, float y_end);
    Segment2f(const Segment2f& copied);    

    Point2f Intersect(const Segment2f& other) const;
    bool IsPointInSegmentBoundingBox(const Point2f& point) const;
};

#endif