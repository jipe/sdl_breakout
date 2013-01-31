#include "Matrix2x2.h"

Matrix2x2::Matrix2x2(float m11, float m12, float m21, float m22) : _m11(m11), _m12(m12), _m21(m21), _m22(m22) {
}

float Matrix2x2::det() const {
  return _m11 * _m22 - _m12 * _m21;
}
