#include "object.hpp"

using obj::Cuboid;
using obj::Plane;
using obj::Sphere;

using obj::Camera;

using obj::Scene;

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
