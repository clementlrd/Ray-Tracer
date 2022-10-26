#ifndef __ECRAN_HPP__
#define __ECRAN_HPP__

#include <vector>
#include "color.hpp"

struct screenSize
{
  size_t width;
  size_t height;
};
typedef struct screenSize screenSize;

class Pixel
{
protected:
  ColorRGB color;

public:
  Pixel(ColorRGB c);
  Pixel();

  ColorRGB const &getColor() const;
  ColorRGB const &setColor(ColorRGB const &c);
};

class Ecran
{
protected:
  screenSize size;
  size_t resolution;

public:
  Ecran(size_t width, size_t height, size_t resolution);
  Ecran(size_t width, size_t height);
  Ecran();
  ~Ecran(); // TODO : delete pixels

  screenSize const &getSize() const;
  void getSize(size_t &w, size_t &h) const;
  size_t getWidth() const;
  size_t getHeight() const;
  Pixel &getPixel(size_t posX, size_t posY) const;

  screenSize const &changeSize(screenSize const &size);
  screenSize const &changeSize(size_t width, size_t height);
  void setResolution(size_t resolution);
};

#endif