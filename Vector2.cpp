#include "Vector2.h"

#include <cmath>

Vector2::Vector2(float x, float y) : x(x), y(y) {
}

Vector2::Vector2(const Vector2& v1, const Vector2& v2) : x(v2.x - v1.x), y(v2.y - v1.y) {
}

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
