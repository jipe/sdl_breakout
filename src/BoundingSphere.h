#ifndef BOUNDING_SPHERE_H
#define BOUNDING_SPHERE_H

#include "BoundingObject.h"
#include "BoundingBox.h"
#include "BoundingPlane.h"

class BoundingBox;
class BoundingPlane;

class BoundingSphere : public BoundingObject {
	public:
		BoundingSphere(const Vector2 &translation, float radius);

		bool intersects(const BoundingObject &boundingObject) const;
		bool intersects(const BoundingSphere &sphere) const;
		bool intersects(const BoundingBox &box) const;
		bool intersects(const BoundingPlane &plane) const;

	private:
		float radius, radiusSquared;
};

#endif
