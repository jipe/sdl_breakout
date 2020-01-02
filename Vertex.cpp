#include "Vertex.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Color.h"

Vertex::Vertex(Vector3& point, Vector3& normal, Color& color, Vector2& texture_coord)
	: point(point),
	  normal(normal),
	  color(static_cast<float>(color.getR()) / 255.0f, static_cast<float>(color.getG()) / 255.0f, static_cast<float>(color.getB()) / 255.0f),
    texture_coord(texture_coord) {
}

Vertex::Vertex(Vector3& point, Vector3& normal, Vector3& color, Vector2& texture_coord)
	: point(point),
    normal(normal),
    color(color),
    texture_coord(texture_coord) {
}
