#include "BoundingObject.h"
#include "BoundingSphere.h"
#include "BoundingBox.h"
#include "BoundingPlane.h"
#include "Vector2.h"
#include "Edge.h"

BoundingSphere::BoundingSphere(const Vector2 &translation, float radius) : BoundingObject(translation), radius(radius), radiusSquared(radius*radius) {
}

bool BoundingSphere::intersects(const BoundingObject &boundingObject) const {
	const BoundingSphere *sphere;
	const BoundingBox *box;
	const BoundingPlane *plane;
	
	if ((sphere = dynamic_cast<const BoundingSphere*>(&boundingObject)) != 0) {
		return intersects(*sphere);
	} else if ((box = dynamic_cast<const BoundingBox*>(&boundingObject)) != 0) {
		return intersects(*box);
	} else if ((plane = dynamic_cast<const BoundingPlane*>(&boundingObject)) != 0) {
		return intersects(*plane);
	}

	return false;
}

bool BoundingSphere::intersects(const BoundingSphere &sphere) const {
}

bool BoundingSphere::intersects(const BoundingBox &box) const {
}

bool BoundingSphere::intersects(const BoundingPlane &plane) const {
}
