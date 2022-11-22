#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <cstdint>

/* RGB_color
 *
 * Struct that contain a color representation (r,g,b,a)
 *
 */
struct RGB_color
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
};

/* Color
 *
 * Color class, contain color representation (RGB base) and methods on color
 *
 */
class Color
{
protected:
  RGB_color color;

public:
  Color(RGB_color const &c);
  Color(uint8_t level);
  Color();

  Color &operator+=(Color const c);
  Color &operator-=(Color const c);

  RGB_color const &getRGBColor() const;
};

/* ColorRGB
 *
 * ColorRGB class, contain RGB color representation
 *
 */
class ColorRGB : public Color
{
public:
  ColorRGB(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);
  ColorRGB();

  RGB_color const &setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);
  RGB_color const &setColor(RGB_color c);
};

/* ColorBW
 *
 * ColorBW class, contain BW color representation
 *
 */
class ColorBW : public Color
{
protected:
  uint8_t level;

public:
  ColorBW(uint8_t l);
  ColorBW();

  uint8_t getLevel();
  RGB_color const &setColor(uint8_t l);
};

#endif