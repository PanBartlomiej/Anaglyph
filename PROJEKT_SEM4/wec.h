#pragma once
#include <stdio.h>

class Vector4
{
public:
    double data[4];
    Vector4();
    Vector4(const double x, const double y, const double z);
    void Print(void);
    void Set(double d1, double d2, double d3);
    double GetX();
    double GetY();
    double GetZ();
    Vector4 operator-(const Vector4&);
    friend Vector4 operator*(const Vector4&, double);
};

class Matrix4
{
public:
    double data[4][4];
    Matrix4();
    void Print(void);
    Matrix4 operator*(const Matrix4);
    friend Vector4 operator*(const Matrix4, const Vector4);
};


Matrix4 CreateRotationMatrix(const double angle, const int axis);
Matrix4 CreateMoveMatrix(const double x, const double y, const double z);
Matrix4 CreateScaleMatrix(const double kx, const double ky, const double kz);
Matrix4 IdentityMatrix();
