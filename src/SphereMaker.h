#pragma once

#include <cmath>
#include <vector>
#include "structures.h"

inline void makeSphere(const Point center, const double ray, const unsigned int count, std::vector<Section>& out)
{
    double a1 = 0;
    double a2 = 0;
    double da1 = 2*(3.1415926535897932384626433832795028841971693993751058209749445923)/sqrt(count);
    double da2 = (3.1415926535897932384626433832795028841971693993751058209749445923)/count;
    for (int i=0;i<count;i++)
    {
        Point p1 = (center + Point(sin(a2)*cos(a1)*ray, cos(a2)*ray, sin(a2)*sin(a1)*ray));
        Point np1 = (center + Point(sin(a2)*cos(-a1)*ray, cos(a2)*ray, sin(a2)*sin(-a1)*ray));
        a1 += da1;
        a2 += da2;
        Point p2 = (center + Point(sin(a2)*cos(a1)*ray, cos(a2)*ray, sin(a2)*sin(a1)*ray));
        Point np2 = (center + Point(sin(a2)*cos(-a1)*ray, cos(a2)*ray, sin(a2)*sin(-a1)*ray));
        
        out.push_back(Section(p1, p2));
        out.push_back(Section(np1, np2));
    }
}