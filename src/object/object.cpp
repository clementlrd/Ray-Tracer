#include "object.hpp"

using obj::Cube;
using obj::Plane;
using obj::Sphere;

using obj::Camera;

using obj::Scene;

Camera::Camera()
    : size({ 3, 4 }), focal_length(1.0), origin(Point3D(0, 0, 0)) {};

Camera::Camera(size_t height, size_t width, size_t focal_length, Point3D origin)
    : size({ height, width }), focal_length(focal_length), origin(origin) {};

Camera::Camera(screenSize size, size_t focal_length, Point3D origin)
    : size(size), focal_length(focal_length), origin(origin) {};

Camera::Camera(const Camera& cam)
    : size(cam.size), focal_length(cam.focal_length), origin(cam.origin) {};

Point3D Camera::get_llc() const {
  return origin - get_horizontal() / 2 - get_vertical() / 2
         - Vect3D(0, 0, focal_length);
};
