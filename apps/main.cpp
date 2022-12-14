#include "color.hpp"
#include "image.hpp"
#include "maths.hpp"
#include "object.hpp"
#include "ray.hpp"

#include <iostream>

void print_image(Image const& image);
Color ray_color(const Ray& r);

int main() {
  // Init image and camera
  Image img1       = Image();
  obj::Camera cam1 = obj::Camera();
  int height       = (int)img1.getHeight();
  int width        = (int)img1.getWidth();
  for (int j = height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < width; ++i) {
      double u = double(i) / (width - 1);
      double v = double(j) / (height - 1);
      // Create a ray according to the position of the camera
      Ray r(cam1.o(), cam1.llc() + u * cam1.h() + v * cam1.v() - cam1.o());
      Color color_pixel = ray_color(r);
      img1(i, j)        = color_pixel;
    };
  };
  printer::ppm(img1);
  return 0;
}

void print_image(Image const& image) {
  for (size_t i = 0; i < image.getWidth(); i++) {
    for (size_t j = 0; j < image.getHeight(); j++) {
      std::cout << image(i, j).repr() << std::endl;
    }
  }
}

Color ray_color(const Ray& r) {
  Vect3D unit_direction = unit(r.dir());
  double t              = 0.5 * (unit_direction.y() + 1.0);
  return (1 - t) * Color({ 255, 255, 255 })
         + t * Color({ 128, 179, 255 }); // from white to cyan
}