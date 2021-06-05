#include "StructureMakers.h"
#include <cmath>

void makeSphere(const Point center, const double ray, const unsigned int count, std::vector<Section>& out)
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

void makeSection(const Point pa, const Point pb, const double thickness, const unsigned int count, std::vector<Section>& out)
{    
    out.push_back(Section(pa, pb));
    
    if (pa == pb || thickness == 0)
        return;
    
    Point normal = pb-pa;
    double len = normal.ray();
    normal = normal / len;
    
    Point ray;
    if (normal.x != 0)
        ray = Point(normal.y/normal.x, 1, 0);
    else if (normal.y != 0)
        ray = Point(1, normal.x/normal.y, 0);
    else 
        ray = Point(0, 1, normal.y/normal.z);
    
    ray = ray * (thickness/ray.ray());
    
    std::vector<Vector4> rotationsRay;

    rotationsRay.resize(count);
    
    for (int i=0;i<count;i++)
        rotationsRay[i] = CreateRotationMatrixFromVector(normal*2*(3.1415926535897932384626433832795028841971693993751058209749445923)*(i+1)/(count))*(Vector4)ray;
    
    for (int i=0;i<count;i++)
        for (int j=0;j<count;j++)
        {
            {
                Point a = pa + (pb-pa)*i/count + rotationsRay[(i+j)%count];
                Point b = pa + (pb-pa)*(i+1)/count + rotationsRay[(i+j+1)%count];
                out.push_back(Section(a, b));
            }
            {
                Point a = pa + (pb-pa)*i/count - rotationsRay[(i+j)%count];
                Point b = pa + (pb-pa)*(i+1)/count - rotationsRay[(i+j+1)%count];
                out.push_back(Section(a, b));
            }
            {
                Point a = pa + (pb-pa)*i/count + rotationsRay[(i+j)%count];
                Point b = pa + (pb-pa)*(i+1)/count + rotationsRay[(i+j-1)%count];
                out.push_back(Section(a, b));
            }
            {
                Point a = pa + (pb-pa)*i/count - rotationsRay[(i+j)%count];
                Point b = pa + (pb-pa)*(i+1)/count - rotationsRay[(i+j-1)%count];
                out.push_back(Section(a, b));
            }
        }
            
    for (int i=0;i<count;i++)
    {
        {
            Point a = pa + rotationsRay[(i)%count];
            Point b = pa + rotationsRay[(i+1)%count];
            out.push_back(Section(a, b));
        }
        {
            Point a = pb + rotationsRay[(i)%count];
            Point b = pb + rotationsRay[(i+1)%count];
            out.push_back(Section(a, b));
        }
    }
    
}
