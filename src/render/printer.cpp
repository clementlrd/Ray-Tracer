#include "printer.hpp"
#include "../display/Image.hpp"
#include "../materials/color.hpp"
#include <iostream>

void printerPpm(Image image) {
  screenSize currentSize = image.getSize();
  std::cout << "P3\n"
            << currentSize.width << ' ' << currentSize.height << "\n255\n";

  for (size_t j = 0; j < currentSize.height; j++) {
    for (size_t i = 0; i < currentSize.width; i++) {
      Color current_color = image(i, j);
      const RGB_color rgb = current_color.getRGBColor();
      std::cout << (int)rgb.r << ' ' << (int)rgb.g << ' ' << (int)rgb.b << '\n';
    }
  }
}