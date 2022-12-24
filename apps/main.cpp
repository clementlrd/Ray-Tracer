#include "image.hpp"

#include <iostream>

void print_image(Image const& image);

int main() {
  Image img1(2, 2);
  Color c2(ColorRGB(255, 128, 64));
  img1(0, 0) = c2;
  img1(1, 0) = c2;
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