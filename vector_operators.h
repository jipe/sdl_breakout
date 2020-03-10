#ifndef VECTOR_OPERATORS_H
#define VECTOR_OPERATORS_H

#include "vector_types.h"

#include <iostream>

Vector2 operator + (const Vector2 &v1, const Vector2 &v2);
Vector2 operator - (const Vector2 &v1, const Vector2 &v2);
float operator * (const Vector2 &v1, const Vector2 &v2);
Vector2 operator * (float r, const Vector2 &v);
Vector2 operator * (const Vector2 &v, float r); 
Vector2 operator / (const Vector2 &v, float r); 

Vector3 operator + (const Vector3 &v1, const Vector3 &v2);
Vector3 operator - (const Vector3 &v1, const Vector3 &v2);
float operator * (const Vector3 &v1, const Vector3 &v2);
Vector3 operator * (float r, const Vector3 &v);
Vector3 operator * (const Vector3 &v, float r); 
Vector3 operator / (const Vector3 &v, float r); 

std::ostream& operator << (std::ostream& os, const Vector2& v);
std::ostream& operator << (std::ostream& os, const Vector3& v);

#endif
