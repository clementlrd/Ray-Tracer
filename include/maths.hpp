#pragma once

#include <cmath>
#include <ostream>

using namespace std;

namespace maths {
  /*
   * Constants
   */
  constexpr double PI { M_PI };
  constexpr double HALF_PI { PI / 2 };

  /*
   * Vector 3D class
   */
  class Vect3D {
  protected:
    double vect[3];

  public:
    Vect3D();
    Vect3D(double);
    Vect3D(double x, double y, double z);
    Vect3D(const Vect3D&);
    Vect3D(Point3D a, Point3D b);

    double x() const;
    double y() const;
    double z() const;
    double operator[](int i) const;

    Vect3D& operator+=(const Vect3D&);
    Vect3D& operator-=(const Vect3D&);
    Vect3D& operator*=(double);
    Vect3D& operator/=(double);

    double norm() const;
    double norm_squared() const;
  };

  /* Utility functions */

  inline std::ostream& operator<<(std::ostream& out, const Vect3D& u) {
    return out << "[" << u.x() << ' ' << u.y() << ' ' << u.z() << "]";
  }

  inline Vect3D operator+(const Vect3D& u, const Vect3D& v) {
    return Vect3D(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
  }

  inline Vect3D operator-(const Vect3D& u, const Vect3D& v) {
    return Vect3D(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
  }

  // By convention double is placed before Vect3D
  inline Vect3D operator*(double t, const Vect3D& u) {
    return Vect3D(u.x() * t, u.y() * t, u.z() * t);
  }

  inline Vect3D operator/(const Vect3D& u, double t) { return (1 / t) * u; }

  inline double dot(const Vect3D& u, const Vect3D& v) {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
  }

  inline Vect3D cross(const Vect3D& u, const Vect3D& v) {
    return Vect3D(u.y() * v.z() - u.z() * v.y(),
                  u.z() * v.x() - u.x() * v.z(),
                  u.x() * v.y() - u.y() * v.x());
  }

  inline Vect3D unit(const Vect3D& u) { return u / u.norm(); }

  /*
   * Point 3D class
   */

  using Point3D = Vect3D;
} // namespace maths