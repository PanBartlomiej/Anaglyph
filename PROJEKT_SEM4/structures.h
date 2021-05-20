#pragma once

#include <stdio.h>

struct Point 
{
    double x, y, z;
    Point(const double nx = 0, const double ny = 0, const double nz = 0) : x(nx), y(ny), z(nz) {}
    
    void print()const 
    { 
        printf("%lg %lg %lg ", x, y, z); 
    }
    
    Point operator+(const Point& p) const
    {
        return Point(p.x+x, p.y+y, p.z+z);
    }
    
    Point operator*(const double d) const
    {
        return Point(d*x, d*y, d*z);
    }
    
};

struct Section {
    Point begin, end;
   // Color color; 
    double thickness;
    Section(Point nbegin, Point nend, double nthickness = 1) : begin(nbegin), end(nend), thickness(nthickness) {}
};

struct Sphere {
    Sphere(Point c, double r): center(c), ray(r) {};
    Sphere() : center(0, 0, 0), ray(1) {};
    
    Point center;
    double ray;
    void set(Point c, double r)
    {
        center = c;
        ray = r;
    }
    
};
