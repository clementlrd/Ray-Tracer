#include "Image.hpp"

Image::Image() : size{INIT_WIDTH, INIT_HEIGHT} {
  Color baseColor = Color();
  std::vector<Color> columns(size.height, baseColor);
  image.resize(size.width, columns);
}

Image::Image(size_t width, size_t height) : size{width, height} {
  Color baseColor = Color();
  std::vector<Color> columns(height, baseColor);
  image.resize(width, columns);
}

Image::Image(size_t width, size_t height, Color baseColor)
    : size{width, height} {
  std::vector<Color> columns(height, baseColor);
  image.resize(width, columns);
}

screenSize const &Image::getSize() const{
    return size;
}

void Image::getSize(size_t &w, size_t &h) const{
  w= size.width;
  h = size.height;
}

size_t Image::getWidth() const{
  return size.width;
}

size_t Image::getHeight() const{
  return size.height;
}

Color &Image::getColor(size_t posW, size_t posH){
  return image[posW][posH];
}

screenSize const &Image::changeSize(screenSize const &final_size){
  for (size_t i =0;i< final_size.width;i++){
    image[i].resize(final_size.height,Color());
  };
  Color baseColor = Color();
  std::vector<Color> columns(final_size.height, baseColor);
  image.resize(final_size.width, columns);
  size.width = final_size.width;
  size.height = final_size.height;
  return size;
}

screenSize const &Image::changeSize(size_t width, size_t height){
  for (size_t i =0;i< width;i++){
    image[i].resize(height,Color());
  };
  Color baseColor = Color();
  std::vector<Color> columns(height, baseColor);
  image.resize(width, columns);
  size.width = width;
  size.height = height;
  return size;
}

size_t Image::getResolution() const{
  return size.width*size.height;
}

