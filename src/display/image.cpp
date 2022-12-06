#include "image.hpp"

Image::Image() : size{INIT_WIDTH, INIT_HEIGHT} {
  Color baseColor = Color();
  std::vector<Color> columns(size.height, baseColor);
  image.resize(size.width, columns);
};

Image::Image(size_t width, size_t height) : size{width, height} {
  Color baseColor = Color();
  std::vector<Color> columns(height, baseColor);
  image.resize(width, columns);
};

Image::Image(size_t width, size_t height, Color baseColor)
    : size{width, height} {
  std::vector<Color> columns(height, baseColor);
  image.resize(width, columns);
};

screenSize Image::getSize() const{
    return size;
};
