#ifndef EDGE_H
#define EDGE_H

#include "Vector2.h"

class Edge {
	const Vector2 &p1, &p2;

	public:
		Edge(const Vector2 &p1, const Vector2 &p2);
		Edge(const Vector2 p1, const Vector2 p2);

		const Vector2& getP1();
		const Vector2& getP2();

		bool intersects(const Edge &edge) const;

};

#endif
