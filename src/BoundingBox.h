#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include "BoundingObject.h"
#include "Vector2.h"

using namespace std;

class BoundingSphere;

class BoundingBox : public BoundingObject {
	float _x0, _y0, _x1, _y1;

	public:
		BoundingBox(const Vector2 &translation, float x0, float y0, float x1, float y1);

		bool intersects(const BoundingObject &boundingObject) const;
		bool intersects(const BoundingSphere &boundingSphere) const;
		bool intersects(const BoundingBox &boundingBox) const;

};

#endif
