#include "ray.hpp"

#include "maths.hpp"

using maths::Point3D;
using maths::Vect3D;

Ray::Ray() : origin(Point3D(0, 0, 0)), direction(Vect3D(1.0, 0, 0)) {};

Ray::Ray(const maths::Point3D& origin,
         const maths::Vect3D& direction,
         const Color& color)
    : origin(origin), direction(direction), color(color) {};

Ray::Ray(const Ray& r)
    : origin(r.origin), direction(r.direction), color(r.color) {};

maths::Point3D Ray::o() const { return origin; };

maths::Vect3D Ray::dir() const { return direction; };

Color Ray::colour() const { return color; };

maths::Point3D Ray::current_pos(double time) const {
  return origin + time * direction;
};

Ray& Ray::operator+=(const Color c) {
  color += c;
  return *this;
};
Ray& Ray::operator-=(const Color c) {
  color -= c;
  return *this;
};