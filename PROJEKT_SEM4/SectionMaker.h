#pragma once

#include <cmath>
#include <vector>
#include "structures.h"
#include "wec.h"

inline void makeSection(const Point pa, const Point pb, const double thickness, const unsigned int count, std::vector<Section>& out)
{    
    out.push_back(Section(pa, pb));
    
    if (pa == pb || thickness == 0)
        return;
    
    Point normal = pb-pa;
    double len = normal.ray();
    normal = normal / len;
    
    std::vector<Matrix4> rotations;
    rotations.resize(count);
    Point ray;
    if (normal.x != 0)
        ray = Point(normal.y/normal.x, 1, 0);
    else if (normal.y != 0)
        ray = Point(1, normal.x/normal.y, 0);
    else 
        ray = Point(0, 1, normal.y/normal.z);
    
    ray = ray * (thickness/ray.ray());
    
    for (int i=0;i<count;i++)
        rotations[i] = CreateRotationMatrixFromVector(normal*2*(3.1415926535897932384626433832795028841971693993751058209749445923)*(i+1)/(count));
    
    for (int i=0;i<count;i++)
        for (int j=0;j<count;j++)
        {
            {
                Point a = pa + (pb-pa)*i/count + rotations[(i+j)%count]*ray;
                Point b = pa + (pb-pa)*(i+1)/count + rotations[(i+j+1)%count]*ray;
                out.push_back(Section(a, b));
            }
            {
                Point a = pa + (pb-pa)*i/count - rotations[(i+j)%count]*ray;
                Point b = pa + (pb-pa)*(i+1)/count - rotations[(i+j+1)%count]*ray;
                out.push_back(Section(a, b));
            }
        }
            
    for (int i=0;i<count;i++)
    {
        {
            Point a = pa + rotations[(i)%count]*ray;
            Point b = pa + rotations[(i+1)%count]*ray;
            out.push_back(Section(a, b));
        }
        {
            Point a = pb + rotations[(i)%count]*ray;
            Point b = pb + rotations[(i+1)%count]*ray;
            out.push_back(Section(a, b));
        }
    }
    
}
