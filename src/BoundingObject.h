#ifndef BOUNDING_OBJECT_H
#define BOUNDING_OBJECT_H

#include "Vector2.h"

class BoundingObject {
	const BoundingObject *_next;
	const Vector2 &_translation;
	
	static bool intersects(const BoundingObject& object1, const BoundingObject& object2);

	public:
		BoundingObject(const Vector2 &translation);
		virtual ~BoundingObject();

		const BoundingObject* getNext() const;
		void setNext(const BoundingObject *next);
		const Vector2& getTranslation() const;

		bool intersects(const BoundingObject &object) const;

};

#endif
