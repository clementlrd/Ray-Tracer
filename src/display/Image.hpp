#pragma once

#include "../materials/color.hpp"
#include <algorithm>
#include <memory>

#define INIT_WIDTH 600
#define INIT_HEIGHT 400

/* screenSize
 *
 * Contain a screen size with a width and height.
 *
 */
struct screenSize {
  size_t width;
  size_t height;
};
typedef struct screenSize screenSize;

class Image {
protected:
  screenSize size;
  std::unique_ptr<Color[]> image;

public:
  Image();
  Image(size_t width, size_t height);
  Image(size_t width, size_t height, Color baseColor);
  Image(const Image &source)
      : size(source.size),
        image(std::make_unique<Color[]>(size.width * size.height)) {
    std::copy_n(source.image.get(), size.width * size.height, image.get());
  }
  Image(Image &&source) : size(source.size), image(source.image.release()) {}
  Image &operator=(const Image &source) {
    size = source.size;
    image = std::make_unique<Color[]>(size.width * size.height);
    std::copy_n(source.image.get(), size.width * size.height, image.get());
    return *this;
  }
  Image &operator=(Image &&source) {
    size = source.size;
    image.swap(source.image);
    source.image.release();
    return *this;
  }

  screenSize const &getSize() const;
  void getSize(size_t &w, size_t &h) const;
  size_t getWidth() const;
  size_t getHeight() const;
  Color &operator()(size_t x, size_t y) const {
    return *(image.get() + x * size.height + y);
  };

  size_t getResolution() const;
  //~Image();
};
