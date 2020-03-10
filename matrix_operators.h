#ifndef MATRIX_OPERATORS_H
#define MATRIX_OPERATORS_H

#include "matrix_types.h"

#include <iostream>

Matrix1x4 operator + (const Matrix1x4& m1, const Matrix1x4& m2);
Matrix1x4 operator - (const Matrix1x4& m1, const Matrix1x4& m2);
Matrix1x4 operator * (const Matrix1x4& m, float r); 
Matrix1x4 operator * (float r, const Matrix1x4& m); 
Matrix1x4 operator / (const Matrix1x4& m, float r); 

Matrix4x1 operator + (const Matrix4x1& m1, const Matrix4x1& m2);
Matrix4x1 operator - (const Matrix4x1& m1, const Matrix4x1& m2);
Matrix4x1 operator * (const Matrix4x1& m, float r); 
Matrix4x1 operator * (float r, const Matrix4x1& m); 
Matrix4x1 operator / (const Matrix4x1& m, float r); 

Matrix4x4 operator + (const Matrix4x4& m1, const Matrix4x4& m2);
Matrix4x4 operator - (const Matrix4x4& m1, const Matrix4x4& m2);
Matrix4x4 operator * (const Matrix4x4& m, float r); 
Matrix4x4 operator * (float r, const Matrix4x4& m); 
Matrix4x4 operator / (const Matrix4x4& m, float r); 

float operator * (const Matrix1x4& m1, const Matrix4x1& m2);
Matrix4x4 operator * (const Matrix4x1& m1, const Matrix1x4& m2);
Matrix1x4 operator * (const Matrix1x4& m1, const Matrix4x4& m2);
Matrix4x1 operator * (const Matrix4x4& m1, const Matrix4x1& m2);

std::ostream& operator << (std::ostream& os, const Matrix1x4& m); 
std::ostream& operator << (std::ostream& os, const Matrix4x1& m); 
std::ostream& operator << (std::ostream& os, const Matrix4x4& m); 

#endif
