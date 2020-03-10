#include "vector_types.h"

#include <cmath>

Vector2::Vector2(float x, float y) : x(x), y(y) {
}

Vector2::Vector2(const Vector2& v1, const Vector2& v2) : x(v2.x - v1.x), y(v2.y - v1.y) {
}

Vector2& Vector2::operator += (const Vector2& v) {
  x += v.x;
  y += v.y;
  return (*this);
}

Vector2& Vector2::operator -= (const Vector2& v) {
  x -= v.x;
  y -= v.y;
  return (*this);
}

Vector2& Vector2::operator *= (const float r) {
  x *= r;
  y *= r;
  return (*this);
}

Vector2 Vector2::normalize() const {
  float length = sqrt(x*x + y*y);
  return Vector2(x/length, y/length);
}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {
}

Vector3::Vector3(const Vector3 &v1, const Vector3 &v2) : x(v2.x - v1.x), y(v2.y - v1.y), z(v2.z - v1.z) {
}

Vector3& Vector3::operator += (const Vector3 &v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return (*this);
}

Vector3& Vector3::operator -= (const Vector3 &v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return (*this);
}

Vector3& Vector3::operator *= (const float r) {
  x *= r;
  y *= r;
  z *= r;
  return (*this);
}

Vector3 Vector3::normalize() const {
  float length = sqrt(x*x + y*y + z*z);
  return Vector3(x/length, y/length, z/length);
}

Vector3 Vector3::cross(const Vector3 &v) const {
  float a = y*v.z - z*v.y;
  float b = z*v.x - x*v.z;
  float c = x*v.y - y*v.x;
  return Vector3(a, b, c);
}
