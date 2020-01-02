#include "Vector3.h"

#include <cmath>

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {
}

Vector3::Vector3(const Vector3 &v1, const Vector3 &v2) : x(v2.x - v1.x), y(v2.y - v1.y), z(v2.z - v1.z) {
}

const Vector3 operator + (const Vector3 &v1, const Vector3 &v2) {
	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

const Vector3 operator - (const Vector3 &v1, const Vector3 &v2) {
	return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

float operator * (const Vector3 &v1, const Vector3 &v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

const Vector3 operator * (const float r, const Vector3 &v) {
	return Vector3(r * v.x, r * v.y, r * v.z);
}

const Vector3 operator * (const Vector3 &v, float r) {
	return Vector3(r * v.x, r * v.y, r * v.z);
}

const Vector3 operator / (const Vector3 &v, float r) {
  return Vector3(v.x / r, v.y / r, v.z / r);
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
