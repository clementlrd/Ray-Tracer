#pragma once

#include "../maths/Vector3D.hpp"

class Ray {
private:
  Point3D origin;
  Vect3D direction;

public:
  Ray();
  Ray(const Point3D &origin, const Vect3D &direction);
  Ray(const Ray &);

  Point3D get_origin();
  Vect3D get_direction();

  Point3D current_pos(double time);
};