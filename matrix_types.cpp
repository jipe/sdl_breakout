#include "matrix_types.h"

Matrix2x2::Matrix2x2(float m11, float m12, float m21, float m22)
  : m11(m11), m12(m12), m21(m21), m22(m22) {
}

float Matrix2x2::det() const {
  return m11 * m22 - m12 * m21;
}

Matrix1x4::Matrix1x4(float m11, float m12, float m13, float m14)
  : m11(m11), m12(m12), m13(m13), m14(m14) {
}

Matrix1x4& Matrix1x4::operator += (const Matrix1x4& m) {
  m11 += m.m11;
  m12 += m.m12;
  m13 += m.m13;
  m14 += m.m14;
  return *this;
}

Matrix1x4& Matrix1x4::operator -= (const Matrix1x4& m) {
  m11 -= m.m11;
  m12 -= m.m12;
  m13 -= m.m13;
  m14 -= m.m14;
  return *this;
}

Matrix1x4& Matrix1x4::operator *= (float f) {
  m11 *= f;
  m12 *= f;
  m13 *= f;
  m14 *= f;
  return *this;
}

Matrix1x4& Matrix1x4::operator /= (float f) {
  m11 /= f;
  m12 /= f;
  m13 /= f;
  m14 /= f;
  return *this;
}

Matrix4x1 Matrix1x4::transpose() const {
  return Matrix4x1(m11, m12, m13, m14);
}

Matrix4x1::Matrix4x1(float m11, float m21, float m31, float m41)
  : m11(m11), m21(m21), m31(m31), m41(m41) {
}

Matrix4x1& Matrix4x1::operator += (const Matrix4x1& m) {
  m11 += m.m11;
  m21 += m.m21;
  m31 += m.m31;
  m41 += m.m41;
  return *this;
}

Matrix4x1& Matrix4x1::operator -= (const Matrix4x1& m) {
  m11 -= m.m11;
  m21 -= m.m21;
  m31 -= m.m31;
  m41 -= m.m41;
  return *this;
}

Matrix4x1& Matrix4x1::operator *= (float r) {
  m11 *= r;
  m21 *= r;
  m31 *= r;
  m41 *= r;
  return *this;
}

Matrix4x1& Matrix4x1::operator /= (float r) {
  m11 /= r;
  m21 /= r;
  m31 /= r;
  m41 /= r;
  return *this;
}

Matrix1x4 Matrix4x1::transpose() const {
  return Matrix1x4(m11, m21, m31, m41);
}

Matrix4x4::Matrix4x4(float m11, float m12, float m13, float m14,
                     float m21, float m22, float m23, float m24,
                     float m31, float m32, float m33, float m34,
                     float m41, float m42, float m43, float m44)
  : m11(m11), m12(m12), m13(m13), m14(m14),
    m21(m21), m22(m22), m23(m23), m24(m24),
    m31(m31), m32(m32), m33(m33), m34(m34),
    m41(m41), m42(m42), m43(m43), m44(m44) {
}

Matrix4x4& Matrix4x4::operator += (const Matrix4x4& m) {
  m11 += m.m11;
  m12 += m.m12;
  m13 += m.m13;
  m14 += m.m14;

  m21 += m.m21;
  m22 += m.m22;
  m23 += m.m23;
  m24 += m.m24;

  m31 += m.m31;
  m32 += m.m32;
  m33 += m.m33;
  m34 += m.m34;

  m41 += m.m41;
  m42 += m.m42;
  m43 += m.m43;
  m44 += m.m44;

  return *this;
}

Matrix4x4& Matrix4x4::operator -= (const Matrix4x4& m) {
  m11 -= m.m11;
  m12 -= m.m12;
  m13 -= m.m13;
  m14 -= m.m14;

  m21 -= m.m21;
  m22 -= m.m22;
  m23 -= m.m23;
  m24 -= m.m24;

  m31 -= m.m31;
  m32 -= m.m32;
  m33 -= m.m33;
  m34 -= m.m34;

  m41 -= m.m41;
  m42 -= m.m42;
  m43 -= m.m43;
  m44 -= m.m44;

  return *this;
}

Matrix4x4& Matrix4x4::operator *= (float r) {
  m11 *= r;
  m12 *= r;
  m13 *= r;
  m14 *= r;

  m21 *= r;
  m22 *= r;
  m23 *= r;
  m24 *= r;

  m31 *= r;
  m32 *= r;
  m33 *= r;
  m34 *= r;

  m41 *= r;
  m42 *= r;
  m43 *= r;
  m44 *= r;

  return *this;
}

Matrix4x4& Matrix4x4::operator /= (float r) {
  m11 /= r;
  m12 /= r;
  m13 /= r;
  m14 /= r;

  m21 /= r;
  m22 /= r;
  m23 /= r;
  m24 /= r;

  m31 /= r;
  m32 /= r;
  m33 /= r;
  m34 /= r;

  m41 /= r;
  m42 /= r;
  m43 /= r;
  m44 /= r;

  return *this;
}

Matrix4x4 Matrix4x4::transpose() const {
  return Matrix4x4(m11, m21, m31, m41,
                   m12, m22, m32, m42,
                   m13, m23, m33, m43,
                   m14, m24, m34, m44);
}
