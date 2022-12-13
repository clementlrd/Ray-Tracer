#include "printer.hpp"
#include "../display/Image.hpp"
#include "../materials/color.hpp"
#include <iostream>

void printerPpm(Image image) {
  screenSize currentSize = image.getSize();
  std::cout << "P3\n"
            << currentSize.width << ' ' << currentSize.height << "\n255\n";

  for (size_t j = currentSize.height - 1; j >= 0; --j) {
    for (size_t i = 0; i < currentSize.width; ++i) {
      Color current_color = image.getColor(i, j);
      RGB_color rgb_value = current_color.getRGBColor();
      uint8_t r = rgb_value.r;
      uint8_t g = rgb_value.g;
      uint8_t b = rgb_value.b;

      std::cout << r << ' ' << g << ' ' << b << '\n';
    }
  }
}