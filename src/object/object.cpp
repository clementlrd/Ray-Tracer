#include "object.hpp"

using obj::Cuboid;
using obj::Plane;
using obj::Sphere;

using obj::Camera;

using obj::Scene;

Cuboid::Cuboid()
    : Object(Point3D(0, 0, 0)),
      vectx(Vect3D(1, 0, 0)),
      vecty(Vect3D(0, 1, 0)),
      vectz(Vect3D(0, 0, 1)) {};

Cuboid::Cuboid(Point3D origin, Vect3D vectx, Vect3D vecty, Vect3D vectz)
    : Object(origin), vectx(vectx), vecty(vecty), vectz(vectz) {};

Cuboid::Cuboid(const Cuboid& cuboid)
    : Object(cuboid.origin),
      vectx(cuboid.vectx),
      vecty(cuboid.vecty),
      vectz(cuboid.vectz) {};

Vect3D Cuboid::normal(Point3D surface_pt) const {
  Vect3D relative = surface_pt - origin;
  if (relative.x() == 0) {
    return Vect3D(0, 0, 0) - unit(vectx);
  } else if (relative.y() == 0) {
    return Vect3D(0, 0, 0) - unit(vecty);
  } else if (relative.z() == 0) {
    return Vect3D(0, 0, 0) - unit(vectz);
  } else if (relative.x() == vectx.norm()) {
    return unit(vectx);
  } else if (relative.y() == vecty.norm()) {
    return unit(vecty);
  } else if (relative.z() == vectz.norm()) {
    return unit(vectz);
  } else {
    throw std::invalid_argument("Not a surface point !");
  }
};

Vect3D Cuboid::tangent(Point3D surface_pt) const {
  Vect3D relative = surface_pt - origin;
  if (relative.x() == 0 || relative.x() == vectx.norm()) {
    return unit(vecty);
  } else if (relative.y() == 0 || relative.y() == vecty.norm()) {
    return unit(vectz);
  } else if (relative.z() == 0 || relative.z() == vectz.norm()) {
    return unit(vectx);
  } else {
    throw std::invalid_argument("Not a surface point !");
  }
};

Sphere::Sphere() : Object(Point3D(0, 0, 0)), radius(1.0) {};

Sphere::Sphere(Point3D origin, double radius)
    : Object(origin), radius(radius) {};

Sphere::Sphere(const Sphere& sphere)
    : Object(sphere.origin), radius(sphere.radius) {};

Vect3D Sphere::normal(Point3D surface_pt) const {
  return unit(Vect3D(origin, surface_pt));
};

Camera::Camera()
    : size_cam({ 3, 4 }), focal_length(1.0), origin(Point3D(0, 0, 0)) {};

Camera::Camera(size_t height, size_t width, size_t focal_length, Point3D origin)
    : size_cam({ height, width }),
      focal_length(focal_length),
      origin(origin) {};

Camera::Camera(screenSize size, size_t focal_length, Point3D origin)
    : size_cam(size), focal_length(focal_length), origin(origin) {};

Camera::Camera(const Camera& cam)
    : size_cam(cam.size_cam),
      focal_length(cam.focal_length),
      origin(cam.origin) {};

Vect3D Camera::h() const { return Vect3D(size_cam.width, 0, 0); };

Vect3D Camera::v() const { return Vect3D(0, size_cam.height, 0); };

Point3D Camera::o() const { return origin; };

size_t Camera::focal() const { return focal_length; };

screenSize Camera::size() const { return size_cam; };

Point3D Camera::llc() const {
  return origin - h() / 2 - v() / 2 - Vect3D(0, 0, focal_length);
};
