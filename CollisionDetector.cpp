#include "CollisionDetector.h"
#include "CollisionObject.h"
#include "Collision.h"

#include <vector>

using namespace std;

CollisionDetector::CollisionDetector() {
}

void CollisionDetector::add(CollisionObject &obj) {
  obj.setCollisionSystemHandle(_objects.size());
  _objects.push_back(&obj);
}

void CollisionDetector::remove(CollisionObject &obj) {

}

vector<Collision> update(float millis) {
}
