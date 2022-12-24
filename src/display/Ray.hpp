#pragma once

#include "../materials/color.hpp"
#include "../maths/Vector3D.hpp"
#include <limits>

/*
 * Ray class represented by an origin, a direction, and a color.
 */
class Ray {
private:
  Point3D origin;
  Vect3D direction;
  Color color;

public:
  Ray();
  Ray(const Point3D &origin, const Vect3D &direction,
      const Color &color = ColorBW{0});
  Ray(const Ray &);

  Point3D get_origin() const;
  Vect3D get_direction() const;
  Color get_color() const;

  Point3D current_pos(double time) const;

  Ray &operator+=(const Color c);
  Ray &operator-=(const Color c);
};

/* Send ray into the scene -> TODO : mouve into render part */
Color send_ray(Point3D origin, Vect3D dir,
               double dmax = std::numeric_limits<int>::max(), int rmax = 1);