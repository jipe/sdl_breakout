#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
public:
  float x, y, z;

  Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
  Vector3(const Vector3 &v1, const Vector3 &v2);

  Vector3& operator += (const Vector3 &v);
  Vector3& operator -= (const Vector3 &v);
  Vector3& operator *= (const float r);
  Vector3& operator /= (const float r);

  Vector3 normalize() const;
  Vector3 cross(const Vector3 &v) const;
};

const Vector3 operator + (const Vector3 &v1, const Vector3 &v2);
const Vector3 operator - (const Vector3 &v1, const Vector3 &v2);
float operator * (const Vector3 &v1, const Vector3 &v2);
const Vector3 operator * (float r, const Vector3 &v);
const Vector3 operator * (const Vector3 &v, float r);
const Vector3 operator / (const Vector3 &v, float r);

#endif
