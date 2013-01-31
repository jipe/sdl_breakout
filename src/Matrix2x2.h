#ifndef MATRIX_2x2_H
#define MATRIX_2x2_H

class Matrix2x2 {
  float _m11, _m12, _m21, _m22;

  public:
    Matrix2x2(float m11, float m12, float m21, float m22);

    float det() const;
};

#endif
