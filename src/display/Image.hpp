#pragma once

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

  screenSize const &getSize() const;
  void getSize(size_t &w, size_t &h) const;
  size_t getWidth() const;
  size_t getHeight() const;
  Color &getColor(size_t posW, size_t posH);

  screenSize const &changeSize(screenSize const &final_size);
  screenSize const &changeSize(size_t width, size_t height);
  size_t getResolution() const;
  //~Image();
};
