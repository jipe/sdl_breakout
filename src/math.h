#ifndef MATH_H
#define MATH_H

template <typename T>
int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

template <typename T>
T abs(T val) {
  return val < T(0) ? -val : val;
}

#endif
