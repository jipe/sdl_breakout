#include "Edge.h"
#include "Vector2.h"

Edge::Edge(const Vector2 &p1, const Vector2 &p2) : p1(p1), p2(p2) {
}

Edge::Edge(const Vector2 p1, const Vector2 p2) : p1(p1), p2(p2) {
}

const Vector2& Edge::getP1() {
	return p1;
}

const Vector2& Edge::getP2() {
	return p2;
}

bool Edge::intersects(const Edge &edge) const {
	Vector2 e1(p2 - p1);
	Vector2 e2(edge.p2 - edge.p1);
	Vector2 v1(edge.p1 - p1);
	Vector2 v2(edge.p2 - p2);

	return ((e1 * v1) * (e1 * v2) > 0) && ((e2 * v1) * (e2 * v2) > 0);
}
