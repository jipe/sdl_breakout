#include "CollisionDetector.h"
#include "CollisionObject.h"
#include "Collision.h"

#include <vector>

using namespace std;

CollisionDetector::CollisionDetector() {
}

void CollisionDetector::add(CollisionObject &obj) {
	obj.setCollisionSystemHandle(objects.size());
	objects.push_back(&obj);
}

void CollisionDetector::remove(CollisionObject &obj) {

}

vector<Collision> update(float millis) {
}
