#include "Vector3D.hpp"

/* Vect3D */

Vect3D::Vect3D() : vect{0, 0, 0} {}
Vect3D::Vect3D(double p) : vect{p, p, p} {}
Vect3D::Vect3D(double x, double y, double z) : vect{x, y, z} {}

double Vect3D::x() const { return vect[0]; }
double Vect3D::y() const { return vect[1]; }
double Vect3D::z() const { return vect[2]; }
double Vect3D::operator[](int i) const { return vect[i]; }

Vect3D &Vect3D::operator+=(const Vect3D &vect2) {
  vect[0] += vect2[0];
  vect[1] += vect2[1];
  vect[2] += vect2[2];
  return *this;
}
Vect3D &Vect3D::operator-=(const Vect3D &vect2) {
  vect[0] -= vect2[0];
  vect[1] -= vect2[1];
  vect[2] -= vect2[2];
  return *this;
}
Vect3D &Vect3D::operator*=(double t) {
  vect[0] *= t;
  vect[1] *= t;
  vect[2] *= t;
  return *this;
}
Vect3D &Vect3D::operator/=(double t) {
  *this *= (1 / t);
  return *this;
}

double Vect3D::norm() const { return std::sqrt(norm_squared()); }
double Vect3D::norm_squared() const {
  return vect[0] * vect[0] + vect[1] * vect[1] + vect[2] * vect[2];
}