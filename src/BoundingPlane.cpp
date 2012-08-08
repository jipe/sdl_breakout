#include "BoundingPlane.h"
#include "BoundingObject.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"

BoundingPlane::BoundingPlane(const Vector2 &translation, const Vector2 &normal) : BoundingObject(translation), normal(normal) {
}

bool BoundingPlane::intersects(const BoundingObject &object) const {
	const BoundingBox *box;
	const BoundingSphere * sphere;
	const BoundingPlane *plane;

	if ((box = dynamic_cast<const BoundingBox*>(&object)) != 0) {
		return intersects(*box);
	} else if ((sphere = dynamic_cast<const BoundingSphere*>(&object)) != 0) {
		return intersects(*sphere);
	} else if ((plane = dynamic_cast<const BoundingPlane*>(&object)) != 0) {
		return intersects(*plane);
	}
}

bool BoundingPlane::intersects(const BoundingBox &box) const {
	return false;
}

bool BoundingPlane::intersects(const BoundingSphere &sphere) const {
	return false;
}

bool BoundingPlane::intersects(const BoundingPlane &plane) const {
	Vector2 p1p2(plane.getTranslation() - getTranslation());
	return normal * p1p2 > 0;
}

const Vector2 BoundingPlane::getNormal() const {
	return normal;
}
