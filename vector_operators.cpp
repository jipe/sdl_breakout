#include "vector_operators.h"

#include <iostream>

Vector2 operator + (const Vector2& v1, const Vector2& v2) {
  return Vector2(v1.x + v2.x, v1.y + v2.y);
}

Vector2 operator - (const Vector2& v1, const Vector2& v2) {
  return Vector2(v1.x - v2.x, v1.y - v2.y);
}

float operator * (const Vector2& v1, const Vector2& v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

Vector2 operator * (const float r, const Vector2& v) {
  return Vector2(r*v.x, r*v.y);
}

Vector2 operator * (const Vector2& v, const float r) {
  return Vector2(r*v.x, r*v.y);
}

Vector2 operator / (const Vector2& v, float r) {
  return Vector2(v.x/r, v.y/r);
}

Vector3 operator + (const Vector3 &v1, const Vector3 &v2) {
  return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3 operator - (const Vector3 &v1, const Vector3 &v2) {
  return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

float operator * (const Vector3 &v1, const Vector3 &v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3 operator * (const float r, const Vector3 &v) {
  return Vector3(r * v.x, r * v.y, r * v.z);
}

Vector3 operator * (const Vector3 &v, float r) {
  return Vector3(r * v.x, r * v.y, r * v.z);
}

Vector3 operator / (const Vector3 &v, float r) {
  return Vector3(v.x / r, v.y / r, v.z / r); 
}

std::ostream& operator << (std::ostream& os, const Vector2& v) {
  return os << "(" << v.x << "," << v.y << ")";
}

std::ostream& operator << (std::ostream& os, const Vector3& v) {
  return os << "(" << v.x << "," << v.y << "," << v.z << ")";
}
