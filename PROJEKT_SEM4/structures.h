#pragma once

#include <stdio.h>
#include <cmath>

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
    
    void operator+=(const Point& p) 
    {
        x += p.x;
        y += p.y;
        z += p.z;
    }
    
    Point operator-(const Point& p) const
    {
        return Point(x-p.x, y-p.y, z-p.z);
    }
    
    void operator-=(const Point& p) 
    {
        x -= p.x;
        y -= p.y;
        z -= p.z;
    }
    
    Point operator*(const double d) const
    {
        return Point(d*x, d*y, d*z);
    }
    
    void operator*=(const double d)
    {
        x *= d;
        y *= d;
        z *= d;
    }
    
    Point operator/(const double d) const
    {
        return Point(x/d, y/d, z/d);
    }
    
    void operator/=(const double d)
    {
        x /= d;
        y /= d;
        z /= d;
    }
    
    bool operator==(const Point& p) const
    {
        return (p.x==x && p.y==y && p.z==z);
    }
    
    double ray() const
    {
        return sqrt(x*x+y*y+z*z);
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
