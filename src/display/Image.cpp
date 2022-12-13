#include "Image.hpp"

Image::Image() : size{INIT_WIDTH, INIT_HEIGHT} {
  image = std::make_unique<Color[]>(size.height * size.width);
}

Image::Image(size_t width, size_t height) : size{width, height} {
  image = std::make_unique<Color[]>(size.height * size.width);
}

Image::Image(size_t width, size_t height, Color baseColor)
    : size{width, height} {
  image = std::make_unique<Color[]>(size.height * size.width);
  // To do : set base color everywhere
}

screenSize const &Image::getSize() const { return size; }

void Image::getSize(size_t &w, size_t &h) const {
  w = size.width;
  h = size.height;
}

size_t Image::getWidth() const { return size.width; }

size_t Image::getHeight() const { return size.height; }

size_t Image::getResolution() const { return size.width * size.height; }
