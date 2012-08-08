#ifndef BOUNDING_PLANE_H
#define BOUNDING_PLANE_H

#include "Vector2.h"
#include "BoundingObject.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"

class BoundingPlane : public BoundingObject {
	public:
		BoundingPlane(const Vector2 &center, const Vector2 &normal);

		bool intersects(const BoundingObject &object) const;
		bool intersects(const BoundingBox &box) const;
		bool intersects(const BoundingSphere &sphere) const;
		bool intersects(const BoundingPlane &plane) const;

		const Vector2 getNormal() const;
	private:
		const Vector2 &normal;
};

#endif
