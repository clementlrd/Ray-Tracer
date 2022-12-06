#include "Ecran.hpp"

Pixel::Pixel(Color c) : color(c){};

Pixel::Pixel() : color((0, 0, 0)){}; // Pixel by default is black

Color const &Pixel::getColor() const { return color; };

Color const &Pixel::setColor(Color const &c) { return color = c; };

Ecran::Ecran(size_t width, size_t height)
    : size{width, height} {}; // Each unit of size is a pixel

Ecran::Ecran() : size{600, 400} {}; // Size by default

screenSize const &Ecran::getSize() const { return size; };

void Ecran::getSize(size_t &w, size_t &h) const {
  w = size.width;
  h = size.height;
};

size_t Ecran::getWidth() const { return size.width; };

size_t Ecran::getHeight() const { return size.height; };

Pixel &Ecran::getPixel(size_t posW, size_t posH) { return pixels[posH][posW]; };

size_t Ecran::getResolution() const { return size.height * size.width; };

screenSize const &Ecran::changeSize(screenSize const &size) {
  return this->size = size;
};
