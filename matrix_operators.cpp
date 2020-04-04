#include "matrix_operators.h"
#include <iostream>

Matrix1x4 operator + (const Matrix1x4& m1, const Matrix1x4& m2) {
  return Matrix1x4(m1.m11 + m2.m11, m1.m12 + m2.m12, m1.m13 + m2.m12, m1.m14 + m2.m14);
}

Matrix1x4 operator - (const Matrix1x4& m1, const Matrix1x4& m2) {
  return Matrix1x4(m1.m11 - m2.m11, m1.m12 - m2.m12, m1.m13 - m2.m12, m1.m14 - m2.m14);
}

Matrix1x4 operator * (const Matrix1x4& m, float r) {
  return Matrix1x4(m.m11 * r, m.m12 * r, m.m13 * r, m.m14 * r);
}

Matrix1x4 operator * (float r, const Matrix1x4& m) {
  return Matrix1x4(m.m11 * r, m.m12 * r, m.m13 * r, m.m14 * r);
}

Matrix1x4 operator / (const Matrix1x4& m, float r) {
  return Matrix1x4(m.m11 / r, m.m12 / r, m.m13 / r, m.m14 / r);
}

Matrix4x1 operator + (const Matrix4x1& m1, const Matrix4x1& m2) {
  return Matrix4x1(m1.m11 + m2.m11, m1.m21 + m2.m21, m1.m31 + m2.m31, m1.m41 + m2.m41);
}

Matrix4x1 operator - (const Matrix4x1& m1, const Matrix4x1& m2) {
  return Matrix4x1(m1.m11 - m2.m11, m1.m21 - m2.m21, m1.m31 - m2.m31, m1.m41 - m2.m41);
}

Matrix4x1 operator * (const Matrix4x1& m, float r) {
  return Matrix4x1(m.m11 * r, m.m21 * r, m.m31 * r, m.m41 * r);
}
 
Matrix4x1 operator * (float r, const Matrix4x1& m) {
  return Matrix4x1(m.m11 * r, m.m21 * r, m.m31 * r, m.m41 * r);
}
 
Matrix4x1 operator / (const Matrix4x1& m, float r) {
  return Matrix4x1(m.m11 / r, m.m21 / r, m.m31 / r, m.m41 / r);
}

Matrix4x4 operator + (const Matrix4x4& m1, const Matrix4x4& m2) {
  return Matrix4x4(m1.m11 + m2.m11, m1.m12 + m2.m12, m1.m13 + m2.m13, m1.m14 + m2.m14,
                   m1.m21 + m2.m21, m1.m22 + m2.m22, m1.m23 + m2.m23, m1.m24 + m2.m24,
                   m1.m31 + m2.m31, m1.m32 + m2.m32, m1.m33 + m2.m33, m1.m34 + m2.m34,
                   m1.m41 + m2.m41, m1.m42 + m2.m42, m1.m43 + m2.m43, m1.m44 + m2.m44);
}

Matrix4x4 operator - (const Matrix4x4& m1, const Matrix4x4& m2) {
  return Matrix4x4(m1.m11 - m2.m11, m1.m12 - m2.m12, m1.m13 - m2.m13, m1.m14 - m2.m14,
                   m1.m21 - m2.m21, m1.m22 - m2.m22, m1.m23 - m2.m23, m1.m24 - m2.m24,
                   m1.m31 - m2.m31, m1.m32 - m2.m32, m1.m33 - m2.m33, m1.m34 - m2.m34,
                   m1.m41 - m2.m41, m1.m42 - m2.m42, m1.m43 - m2.m43, m1.m44 - m2.m44);
}

Matrix4x4 operator * (const Matrix4x4& m, float r) {
  return Matrix4x4(m.m11 * r, m.m12 * r, m.m13 * r, m.m14 * r,
                   m.m21 * r, m.m22 * r, m.m23 * r, m.m24 * r,
                   m.m31 * r, m.m32 * r, m.m33 * r, m.m34 * r,
                   m.m41 * r, m.m42 * r, m.m43 * r, m.m44 * r);
}
 
Matrix4x4 operator * (float r, const Matrix4x4& m) {
  return Matrix4x4(m.m11 * r, m.m12 * r, m.m13 * r, m.m14 * r,
                   m.m21 * r, m.m22 * r, m.m23 * r, m.m24 * r,
                   m.m31 * r, m.m32 * r, m.m33 * r, m.m34 * r,
                   m.m41 * r, m.m42 * r, m.m43 * r, m.m44 * r);
}
 
Matrix4x4 operator / (const Matrix4x4& m, float r) {
  return Matrix4x4(m.m11 / r, m.m12 / r, m.m13 / r, m.m14 / r,
                   m.m21 / r, m.m22 / r, m.m23 / r, m.m24 / r,
                   m.m31 / r, m.m32 / r, m.m33 / r, m.m34 / r,
                   m.m41 / r, m.m42 / r, m.m43 / r, m.m44 / r);
}

float operator * (const Matrix1x4& m1, const Matrix4x1& m2) {
  return m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31 + m1.m14 * m2.m41;
}

Matrix4x4 operator * (const Matrix4x1& m1, const Matrix1x4& m2) {
  return Matrix4x4(m1.m11 * m2.m11, m1.m11 * m2.m12, m1.m11 * m2.m13, m1.m11 * m2.m14,
                   m1.m21 * m2.m11, m1.m21 * m2.m12, m1.m21 * m2.m13, m1.m21 * m2.m14,
                   m1.m31 * m2.m11, m1.m31 * m2.m12, m1.m31 * m2.m13, m1.m31 * m2.m14,
                   m1.m41 * m2.m11, m1.m41 * m2.m12, m1.m41 * m2.m13, m1.m41 * m2.m14);
}

Matrix1x4 operator * (const Matrix1x4& m1, const Matrix4x4& m2) {
  return Matrix1x4(m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31 + m1.m14 * m2.m41,
                   m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32 + m1.m14 * m2.m42,
                   m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32 + m1.m14 * m2.m42,
                   m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32 + m1.m14 * m2.m42);
}

Matrix4x1 operator * (const Matrix4x4& m1, const Matrix4x1& m2) {
  return Matrix4x1(m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31 + m1.m14 * m2.m41,
                   m1.m21 * m2.m11 + m1.m22 * m2.m21 + m1.m23 * m2.m31 + m1.m24 * m2.m41,
                   m1.m31 * m2.m11 + m1.m32 * m2.m21 + m1.m33 * m2.m31 + m1.m34 * m2.m41,
                   m1.m41 * m2.m11 + m1.m42 * m2.m21 + m1.m43 * m2.m31 + m1.m44 * m2.m41);
}

std::ostream& operator << (std::ostream& os, const Matrix1x4& m) {
  return os << "[" << m.m11 << "," << m.m12 << "," << m.m13 << "," << m.m14 << "]";
}
 
std::ostream& operator << (std::ostream& os, const Matrix4x1& m) {
  return os << "[" << m.m11 << ";" << m.m21 << ";" << m.m31 << ";" << m.m41 << "]";
}
 
std::ostream& operator << (std::ostream& os, const Matrix4x4& m) {
  return os << "[" << m.m11 << "," << m.m12 << "," << m.m13 << "," << m.m14 << ";"
                   << m.m21 << "," << m.m22 << "," << m.m23 << "," << m.m24 << ";"
                   << m.m31 << "," << m.m32 << "," << m.m33 << "," << m.m34 << ";"
                   << m.m41 << "," << m.m42 << "," << m.m43 << "," << m.m44 << "]";
}
