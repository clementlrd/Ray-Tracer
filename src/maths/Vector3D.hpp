#pragma once

#include <cmath>

class Vect3D {
protected:
  double vect[3];

public:
  Vect3D();
  Vect3D(double);
  Vect3D(double x, double y, double z);

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
