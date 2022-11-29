#include "materials/color.hpp"
#include <iostream>

void print_color(RGB_color const &c);

int main() {
  Color c1;
  print_color(c1.getRGBColor());
  return 0;
}

void print_color(RGB_color const &c) {
  std::cout << "(" << (int)c.r << "," << (int)c.g << "," << (int)c.b << ","
            << (int)c.a << ")" << std::endl;
}