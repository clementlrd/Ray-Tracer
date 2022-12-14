#include "maths.hpp"

using maths::Vect3D;

/* Vect3D */

Vect3D::Vect3D() : vect { 0, 0, 0 } {}
Vect3D::Vect3D(double p) : vect { p, p, p } {}
Vect3D::Vect3D(double x, double y, double z) : vect { x, y, z } {}
Vect3D::Vect3D(const Vect3D& v) : vect { v.x(), v.y(), v.z() } {}
Vect3D::Vect3D(Point3D a, Point3D b)
    : vect { (b - a).x(), (b - a).y(), (b - a).z() } {}

double Vect3D::x() const { return vect[0]; }
double Vect3D::y() const { return vect[1]; }
double Vect3D::z() const { return vect[2]; }
double Vect3D::operator[](int i) const { return vect[i]; }

Vect3D& Vect3D::operator+=(const Vect3D& vect2) {
  vect[0] += vect2.x();
  vect[1] += vect2.y();
  vect[2] += vect2.z();
  return *this;
}
Vect3D& Vect3D::operator-=(const Vect3D& vect2) {
  vect[0] -= vect2.x();
  vect[1] -= vect2.y();
  vect[2] -= vect2.z();
  return *this;
}
Vect3D& Vect3D::operator*=(double t) {
  vect[0] *= t;
  vect[1] *= t;
  vect[2] *= t;
  return *this;
}
Vect3D& Vect3D::operator/=(double t) {
  *this *= (1 / t);
  return *this;
}

double Vect3D::norm() const { return std::sqrt(norm_squared()); }
double Vect3D::norm_squared() const {
  return x() * x() + y() * y() + z() * z();
}