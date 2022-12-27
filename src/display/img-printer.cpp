#include "image.hpp"

#include <iostream>

void printer::ppm(Image image) {
  screenSize currentSize = image.getSize();
  std::cout << "P3\n"
            << currentSize.width << ' ' << currentSize.height << "\n255\n";

  for (int j = (int)currentSize.height - 1; j >= 0; --j) {
    for (int i = 0; i < (int)currentSize.width; ++i) {
      Color current_color = image(i, j);
      const RGB_color rgb = current_color.getRGBColor();
      std::cout << (int)rgb.r << ' ' << (int)rgb.g << ' ' << (int)rgb.b << '\n';
    }
  }
}