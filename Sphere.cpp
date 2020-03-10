#include "Sphere.h"
#include "vector.h"

Sphere::Sphere(float x, float y, float radius) : Sphere(Vector2(x,y), radius) {
}

Sphere::Sphere(Vector2 center, float radius) : _center(center), _radius(radius) {
}
