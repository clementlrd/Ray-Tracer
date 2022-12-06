#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include "../materials/color.hpp"
#include <vector>

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
  std::vector<std::vector<Color>> image;

public:
  Image();
  Image(size_t width, size_t height);
  Image(size_t width, size_t height, Color baseColor);
  screenSize getSize() const;
  //~Image();
};

#endif