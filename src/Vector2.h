#ifndef VECTOR2_H
#define VECTOR2_H

#include "Screen.h"

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

    // For visual debugging
    void render(Screen &screen, int x, int y) const;
};

const Vector2 operator + (const Vector2 &v1, const Vector2 &v2);
const Vector2 operator - (const Vector2 &v1, const Vector2 &v2);
float operator * (const Vector2 &v1, const Vector2 &v2);
const Vector2 operator * (float r, const Vector2 &v);
const Vector2 operator * (const Vector2 &v, float r);

#endif
