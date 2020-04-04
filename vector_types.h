#ifndef VECTOR_TYPES_H
#define VECTOR_TYPES_H

class Vector2 {
  public:
    float x, y;

    Vector2(float x, float y); 
    Vector2(const Vector2 &v1, const Vector2 &v2);

    Vector2& operator += (const Vector2 &v);
    Vector2& operator -= (const Vector2 &v);
    Vector2& operator *= (const float r); 
    Vector2& operator /= (const float r); 

    Vector2 normalize() const;
};

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

#endif
