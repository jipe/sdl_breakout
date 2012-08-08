#include "BoundingObject.h"
#include "BoundingSphere.h"
#include "BoundingBox.h"
#include "BoundingPlane.h"
#include "Vector2.h"

BoundingObject::BoundingObject(const Vector2 &translation) : _next(0), _translation(translation) {
}

BoundingObject::~BoundingObject() {
}

void BoundingObject::setNext(const BoundingObject *next) {
	_next = next;
}

const BoundingObject* BoundingObject::getNext() const {
	return _next;
}

const Vector2& BoundingObject::getTranslation() const {
	return _translation;
}

bool intersects(const BoundingSphere &sphere1, const BoundingSphere &sphere2) {
}

bool intersects(const BoundingSphere &sphere1, const BoundingBox &box2) {
}

bool intersects(const BoundingSphere &sphere1, const BoundingPlane &plane2) {
}

bool intersects(const BoundingBox &box1, const BoundingBox &box2) {
}

bool intersects(const BoundingBox &box1, const BoundingPlane &plane2) {
}

bool intersects(const BoundingPlane &plane1, const BoundingPlane &plane2) {
}

bool BoundingObject::intersects(const BoundingObject &object1, const BoundingObject &object2) {
	const BoundingObject *bo1 = &object1;
	const BoundingObject *bo2 = &object2;

	const BoundingSphere *sphere1, *sphere2;
	const BoundingBox *box1, *box2;
	const BoundingPlane *plane1, *plane2;

	while (bo1 != 0 && bo2 != 0) {
		if ((sphere1 = dynamic_cast<const BoundingSphere*>(bo1)) != 0) {
			if ((sphere2 = dynamic_cast<const BoundingSphere*>(bo2)) != 0) {
				if (!intersects(*sphere1, *sphere2)) { 
					return false; 
				}
			} else if ((box2 = dynamic_cast<const BoundingBox*>(bo2)) != 0) {
				if (!intersects(*sphere1, *box2)) {
					return false;
				}
			} else if ((plane2 = dynamic_cast<const BoundingPlane*>(bo2)) != 0) {
				if (!intersects(*sphere1, *plane2)) { 
					return false;
				}
			} else {
				return false;
			}
		} else if ((box1 = dynamic_cast<const BoundingBox*>(bo1)) != 0) {
			if ((sphere2 = dynamic_cast<const BoundingSphere*>(bo2)) != 0) {
				if (!intersects(*sphere2, *box1)) {
					return false;
				}
			} else if ((box2 = dynamic_cast<const BoundingBox*>(bo2)) != 0) {
				if (!intersects(*box1, *box2)) {
					return false;
				}
			} else if ((plane2 = dynamic_cast<const BoundingPlane*>(bo2)) != 0) {
				if (!intersects(*box1, *plane2)) {
					return false;
				}
			} else {
				return false;
			}
		} else if ((plane1 = dynamic_cast<const BoundingPlane*>(bo1)) != 0) {
			if ((sphere2 = dynamic_cast<const BoundingSphere*>(bo2)) != 0) {
				if (!intersects(*sphere2, *plane1)) {
					return false;
				}
			} else if ((box2 = dynamic_cast<const BoundingBox*>(bo2)) != 0) {
				if (!intersects(*box2, *plane1)) {
					return false;
				}
			} else if ((plane2 = dynamic_cast<const BoundingPlane*>(bo2)) != 0) {
				if (!intersects(*plane1, *plane2)) {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
		if (bo1->getNext()) {
			bo1 = bo1->getNext();
		}
		if (bo2->getNext()) {
			bo2 = bo2->getNext();
		}
	}

	return true;
}

bool BoundingObject::intersects(const BoundingObject &object) const {
	return intersects(*this, object);
}
