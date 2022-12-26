#pragma once

#include "color.hpp"
#include "maths.hpp"

#include <limits>

/*
 * Ray class represented by an origin, a direction, and a color.
 */
class Ray {
private:
  maths::Point3D origin;
  maths::Vect3D direction;
  Color color;

public:
  Ray();
  Ray(const maths::Point3D& origin,
      const maths::Vect3D& direction,
      const Color& color = ColorBW { 0 });
  Ray(const Ray&);

  maths::Point3D get_origin() const { return origin; };
  maths::Vect3D get_direction() const { return direction; };
  Color get_color() const { return color; };

  maths::Point3D current_pos(double time) const;

  Ray& operator+=(const Color c);
  Ray& operator-=(const Color c);
};

/* Send ray into the scene -> TODO : move into render part */
Color send_ray(maths::Point3D origin,
               maths::Vect3D dir,
               double dmax = std::numeric_limits<int>::max(),
               int rmax    = 1);