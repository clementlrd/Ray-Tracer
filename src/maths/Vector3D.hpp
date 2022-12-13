#pragma once

#include <cmath>
#include <ostream>

/* Vector 3D class */

class Vect3D {
protected:
  double vect[3];

public:
  Vect3D();
  Vect3D(double);
  Vect3D(double x, double y, double z);
  Vect3D(const Vect3D &);

  double x() const;
  double y() const;
  double z() const;
  double operator[](int i) const;

  Vect3D &operator+=(const Vect3D &);
  Vect3D &operator-=(const Vect3D &);
  Vect3D &operator*=(double);
  Vect3D &operator/=(double);

  double norm() const;
  double norm_squared() const;
};

/* Utility functions */

inline std::ostream &operator<<(std::ostream &out, const Vect3D &u) {
  return out << "[" << u.x() << ' ' << u.y() << ' ' << u.z() << "]";
}

inline Vect3D operator+(const Vect3D &u, const Vect3D &v) {
  return Vect3D(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline Vect3D operator-(const Vect3D &u, const Vect3D &v) {
  return Vect3D(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline Vect3D operator*(const Vect3D &u, double t) {
  return Vect3D(u.x() * t, u.y() * t, u.z() * t);
}

inline Vect3D operator/(const Vect3D &u, double t) { return u * (1 / t); }

inline double dot(const Vect3D &u, const Vect3D &v) {
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline Vect3D cross(const Vect3D &u, const Vect3D &v) {
  return Vect3D(u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

inline Vect3D unit(const Vect3D &u) { return u / u.norm(); }