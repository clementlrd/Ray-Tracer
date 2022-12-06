#ifndef __ECRAN_HPP__
#define __ECRAN_HPP__

#include "../materials/color.hpp"
#include <vector>

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

/* Pixel
 *
 * Pixel class, contain a color
 *
 */
class Pixel {
protected:
  Color color;

public:
  Pixel(Color c);
  Pixel();

  Color const &getColor() const;
  Color const &setColor(Color const &c);
};

class Ecran {
protected:
  screenSize size;
  std::vector<std::vector<Pixel>> pixels;

public:
  Ecran(size_t width, size_t height);
  Ecran();
  ~Ecran(); // TODO : delete pixels

  screenSize const &getSize() const;
  void getSize(size_t &w, size_t &h) const;
  size_t getWidth() const;
  size_t getHeight() const;
  Pixel &getPixel(size_t posW, size_t posH);

  screenSize const &changeSize(screenSize const &size);
  screenSize const &changeSize(size_t width, size_t height);
  size_t getResolution() const;
};

#endif