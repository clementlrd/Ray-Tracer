#ifndef __COLOR_HPP__
#define __COLOR_HPP__

/* RGB_color
 *
 * Struct that contain a color representation (r,g,b,a)
 *
 */
struct RGB_color
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
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
  Color(unsigned char level);
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
  ColorRGB(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0);
  ColorRGB();

  RGB_color const &setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0);
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
  unsigned char level;

public:
  ColorBW(unsigned char l);
  ColorBW();

  unsigned char getLevel();
  RGB_color const &setColor(unsigned char l);
};

#endif