#pragma once

#include <cmath>
#include <vector>
#include "structures.h"
#include "wec.h"
/*
inline Point pointFromNormalVectors(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f, const double& angle)
{
    double ca = cos(angle);
    double sa = sin(angle);
    Point tmp = Point(a*ca+b*sa, c*ca+d*sa, e*ca+f*sa);
    return tmp/tmp.ray();
}

inline void makeSection(const Point pa, const Point pb, const double thickness, const unsigned int count, std::vector<Section>& out)
{
    out.push_back(Section(pa, pb));
    
    if (pa == pb || thickness == 0)
        return;
    
    Point normal = pb-pa;
    double length = normal.ray();
    normal /= length;
    
    normal.print();
    printf("\n");
    
    double &A = normal.x, &B = normal.y, &C = normal.z;
    
    const double pi = 3.141592653589793238462643383279502884197169399375105820974944592;
    
    Vector4 vNorm(A, B, C);
    Vector4 v1 = CreateRotationMatrix(pi/2, 0)*vNorm;
    Vector4 v2 = CreateRotationMatrix(pi/2, 1)*v1;
    
    double a=v1.data[0], b=v2.data[0], c=v1.data[1], d=v2.data[1], e=v1.data[2], f=v2.data[2];
    
    //std::cout << a << "\t"  << b << "\t"  << c << "\t"  << d << "\t"  << e << "\t"  << f << "\t" << std::endl;
    std::cout << a*b+c*d+d*e << "\t" << A*b+B*d+C*e << "\t" << a*A+c*B+d*C << "\t" << std::endl;
    
    Point tmp1, tmp2=pointFromNormalVectors(a, b, c, d, e, f, 0)*thickness;
    for (int i=0;i<count;i++)
    {
        tmp1 = tmp2;
        tmp2 = pointFromNormalVectors(a, b, c, d, e, f, (2*pi*(i+1))/count)*thickness;
        
        out.push_back(Section(pa+tmp1, pb+tmp2));
        out.push_back(Section(pa+tmp2, pb+tmp1));
        
        tmp1.print();
        printf("\n");
            
        out.push_back(Section(pa+tmp1+normal*(length*i/(count+1.0)), pa+tmp2+normal*(length*(i+1.0)/(count+1.0))));
    }
    
}*/

//inline void makeSphere(const Point center, const double ray, const unsigned int count, std::vector<Section>& out)
inline void makeSection(const Point pa, const Point pb, const double thickness, const unsigned int count, std::vector<Section>& out)
{
    out.push_back(Section(pa, pb));
    
    if (pa == pb || thickness == 0)
        return;
    
    double a1 = 0;
    double a2 = 0;
    double da1 = (3.1415926535897932384626433832795028841971693993751058209749445923)/count;
    double da2 = (3.1415926535897932384626433832795028841971693993751058209749445923)/count;
    for (int i=0;i<count;i++)
    {
        Point p1 = (pa + Point(sin(a2)*cos(a1)*thickness, cos(a2)*thickness, sin(a2)*sin(a1)*thickness));
        Point np1 = (pa + Point(sin(a2)*cos(-a1)*thickness, cos(a2)*thickness, sin(a2)*sin(-a1)*thickness));
        a1 += da1;
        a2 += da2;
        Point p2 = (pb + Point(sin(a2)*cos(a1)*thickness, cos(a2)*thickness, sin(a2)*sin(a1)*thickness));
        Point np2 = (pb + Point(sin(a2)*cos(-a1)*thickness, cos(a2)*thickness, sin(a2)*sin(-a1)*thickness));
        
        out.push_back(Section(p1, p2));
        out.push_back(Section(np1, np2));
    }
}
