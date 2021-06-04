#include "wec.h"
#include <cmath>

inline double sqr(const double x)
{
    return x*x;
}

Vector4::Vector4()
{
    data[0] = 0.0; data[1] = 0.0; data[2] = 0.0; data[3] = 1.0;
}

Vector4::Vector4(const double x, const double y, const double z)
{
    data[0] = x; data[1] = y; data[2] = z; data[3] = 1.0;
}

void Vector4::Print(void)
{
    printf("(%2.3lf,%2.3lf,%2.3lf,%2.3lf)\n", data[0], data[1], data[2], data[3]);
}

void Vector4::Set(double d1, double d2, double d3)
{
    data[0] = d1; data[1] = d2; data[2] = d3;
}

double Vector4::GetX()
{
    return data[0];
}

double Vector4::GetY()
{
    return data[1];
}

double Vector4::GetZ()
{
    return data[2];
}

Vector4 Vector4::operator+ (const Vector4& gVector) const
{
    unsigned int i;
    Vector4 Result;
    for (i = 0; i < 4; i++) Result.data[i] = data[i] + gVector.data[i];
    return Result;
}

Vector4 Vector4::operator- (const Vector4& gVector) const
{
    unsigned int i;
    Vector4 Result;
    for (i = 0; i < 4; i++) Result.data[i] = data[i] - gVector.data[i];
    return Result;
}

Vector4 Vector4::operator*(const double x) const
{
    unsigned int i;
    Vector4 Result;
    for (i = 0; i < 4; i++) Result.data[i] = data[i] * x;
    return Result;
}

Vector4 Vector4::operator/(const double x) const
{
    unsigned int i;
    Vector4 Result;
    for (i = 0; i < 4; i++) Result.data[i] = data[i] / x;
    return Result;
}

Matrix4::Matrix4()
{
    data[0][0] = 0.0; data[0][1] = 0.0; data[0][2] = 0.0; data[0][3] = 0.0;
    data[1][0] = 0.0; data[1][1] = 0.0; data[1][2] = 0.0; data[1][3] = 0.0;
    data[2][0] = 0.0; data[2][1] = 0.0; data[2][2] = 0.0; data[2][3] = 0.0;
    data[3][0] = 0.0; data[3][1] = 0.0; data[3][2] = 0.0; data[3][3] = 1.0;
}

void Matrix4::Print(void)
{
    printf("\n|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[0][0], data[0][1], data[0][2], data[0][3]);
    printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[1][0], data[1][1], data[1][2], data[1][3]);
    printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[2][0], data[2][1], data[2][2], data[2][3]);
    printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[3][0], data[3][1], data[3][2], data[2][3]);
}

Matrix4 Matrix4::operator* (const Matrix4 gMatrix)
{
    int i, j, k;
    Matrix4 tmp;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            tmp.data[i][j] = 0.0;
            for (k = 0; k < 4; k++)
                tmp.data[i][j] = tmp.data[i][j] + (data[i][k] * gMatrix.data[k][j]);
        }
    return tmp;
}

Vector4 operator* (const Matrix4 gMatrix, const Vector4 gVector)
{
    unsigned int i, j;
    Vector4 tmp;

    for (i = 0; i < 4; i++)
    {
        tmp.data[i] = 0.0;
        for (j = 0; j < 4; j++) tmp.data[i] = tmp.data[i] + (gMatrix.data[i][j] * gVector.data[j]);
    }
    return tmp;
}

Matrix4 CreateRotationMatrix(const double angle, const int axis)
{
    double c = cos(angle);
    double s = sin(angle);
    
    int newX = (axis+0) % 3;
    int newY = (axis+1) % 3;
    int newZ = (axis+2) % 3;
    
    Matrix4 result;
    result.data[3][3] = 1;
    
    result.data[newX][newX] = 1;
    result.data[newY][newY] = c;
    result.data[newY][newZ] = -s;
    result.data[newZ][newY] = s;
    result.data[newZ][newZ] = c;     
    
    return result;
}

Matrix4 CreateRotationMatrixFromVector(const Vector4 vector)
{
  double angle = sqrt(vector.data[0]*vector.data[0]+vector.data[1]*vector.data[1]+vector.data[2]*vector.data[2]);
  double c = cos(angle);
  double s = sin(angle);
  Vector4 u = vector/angle;

  Matrix4 Result;
  Result.data[3][3] = 0;
  
  Result.data[0][0] = c+sqr(u.data[0])*(1-c);
  Result.data[0][1] = u.data[0]*u.data[1]*(1-c)-u.data[2]*s;
  Result.data[0][2] = u.data[0]*u.data[2]*(1-c)+u.data[1]*s;

  Result.data[1][0] = u.data[1]*u.data[0]*(1-c)+u.data[2]*s;
  Result.data[1][1] = c+sqr(u.data[1])*(1-c);
  Result.data[1][2] = u.data[1]*u.data[2]*(1-c)-u.data[0]*s;

  Result.data[2][0] = u.data[2]*u.data[0]*(1-c)-u.data[1]*s;
  Result.data[2][1] = u.data[2]*u.data[1]*(1-c)+u.data[0]*s;
  Result.data[2][2] = c+sqr(u.data[2])*(1-c);
  
  return Result;
}

Matrix4 CreateMoveMatrix(const double x, const double y, const double z)
{
    Matrix4 temp;
    temp.data[0][0] = 1;
    temp.data[1][1] = 1;
    temp.data[2][2] = 1;
    
    temp.data[0][3] = x;
    temp.data[1][3] = y;
    temp.data[2][3] = z;
    
    return temp;
}

Matrix4 CreateScaleMatrix(const double kx, const double ky, const double kz)
{
    Matrix4 temp;
    temp.data[0][0] = kx;
    temp.data[1][1] = ky;
    temp.data[2][2] = kz;
    return temp;
}

Matrix4 IdentityMatrix()
{
    Matrix4 temp;
    temp.data[0][0] = 1;
    temp.data[1][1] = 1;
    temp.data[2][2] = 1;
    return temp;
}
