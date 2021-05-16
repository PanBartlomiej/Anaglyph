#pragma once

struct Point 
{
    double x, y, z;
    Point(const double nx = 0, const double ny = 0, const double nz = 0) : x(nx), y(ny), z(nz) {}
    
    void print()const 
    { 
        printf("%lg %lg %lg ", x, y, z); 
    }
};

struct Section {
    Point begin, end;
   // Color color; 
    double thickness;
    Section(Point nbegin, Point nend, double nthickness) : begin(nbegin), end(nend), thickness(nthickness) {}
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
