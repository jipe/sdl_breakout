#include "BoundingObject.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"
#include "Vector2.h"

BoundingBox::BoundingBox(const Vector2 &translation, float x0, float y0, float x1, float y1) 
		: BoundingObject(translation), _x0(x0), _y0(y0), _x1(x1), _y1(y1) {
}

bool BoundingBox::intersects(const BoundingObject &boundingObject) const {
	const BoundingSphere *sphere;
	const BoundingBox *box;

	if ((sphere = dynamic_cast<const BoundingSphere*>(&boundingObject)) != 0) {
		return intersects(*sphere);	
	} else if ((box = dynamic_cast<const BoundingBox*>(&boundingObject)) != 0) {
		return intersects(*box);
	}

	return false;
}

bool BoundingBox::intersects(const BoundingBox &box) const {
	float ax0 = _x0 + getTranslation().x;
	float ay0 = _y0 + getTranslation().y;
	float ax1 = _x1 + getTranslation().x;
	float ay1 = _y1 + getTranslation().y;
	float bx0 = box._x0 + box.getTranslation().x;
	float by0 = box._y0 + box.getTranslation().y;
	float bx1 = box._x1 + box.getTranslation().x;
	float by1 = box._y1 + box.getTranslation().y;

	return !(ax1 < bx0 || ax0 > bx1 || ay1 < by0 || ay0 > by1);
}

bool BoundingBox::intersects(const BoundingSphere &sphere) const {

}

