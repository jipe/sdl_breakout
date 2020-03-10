#ifndef MATRIX_TYPES_H
#define MATRIX_TYPES_H

class Matrix2x2 {
  public:
    float m11, m12, m21, m22;

    Matrix2x2(float m11, float m12, float m21, float m22);

    float det() const;
};

class Matrix4x1;

class Matrix1x4 {
  public: 
    float m11, m12, m13, m14;
    
    Matrix1x4(float m11, float m12, float m13, float m14);
    
    Matrix1x4& operator += (const Matrix1x4& m);
    Matrix1x4& operator -= (const Matrix1x4& m);
    Matrix1x4& operator *= (float r);
    Matrix1x4& operator /= (float r);

    Matrix4x1 transpose() const;
};

class Matrix4x1 {
  public:
    float m11, m21, m31, m41;

    Matrix4x1(float m11, float m21, float m31, float m41);

    Matrix4x1& operator += (const Matrix4x1& m); 
    Matrix4x1& operator -= (const Matrix4x1& m); 
    Matrix4x1& operator *= (float r); 
    Matrix4x1& operator /= (float r); 

    Matrix1x4 transpose() const;
};

class Matrix4x4 {
  public:
    float m11, m12, m13, m14,
          m21, m22, m23, m24,
          m31, m32, m33, m34,
          m41, m42, m43, m44;

    Matrix4x4(float m11, float m12, float m13, float m14,
              float m21, float m22, float m23, float m24,
              float m31, float m32, float m33, float m34,
              float m41, float m42, float m43, float m44);

    Matrix4x4& operator += (const Matrix4x4& m); 
    Matrix4x4& operator -= (const Matrix4x4& m); 
    Matrix4x4& operator *= (float r); 
    Matrix4x4& operator /= (float r); 

    Matrix4x4 transpose() const;
};

#endif
