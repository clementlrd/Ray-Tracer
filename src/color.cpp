#include "color.hpp"
#include "utils.hpp"

/* Color */

Color::Color(RGB_color const &c) : color(c)
{
}
Color::Color(unsigned char level) : color{level, level, level, 0} {}
Color::Color() : color{0, 0, 0, 0} {}

Color &Color::operator+=(Color c)
{
  color.r = safe_char_add(color.r, c.color.r);
  color.g = safe_char_add(color.g, c.color.g);
  color.b = safe_char_add(color.b, c.color.b);
  color.a = safe_char_add(color.a, c.color.a);
  return *this;
}

Color &Color::operator-=(Color c)
{
  color.r = safe_char_sub(color.r, c.color.r);
  color.g = safe_char_sub(color.g, c.color.g);
  color.b = safe_char_sub(color.b, c.color.b);
  color.a = safe_char_sub(color.a, c.color.a);
  return *this;
}

RGB_color const &Color::getRGBColor() const
{
  return color;
}

/* Color RGB */

ColorRGB::ColorRGB(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0) : Color({r, g, b, a}) {}
ColorRGB::ColorRGB() : Color() {}

RGB_color const &ColorRGB::setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0)
{
  color = {r, g, b, a};
  return color;
}
RGB_color const &ColorRGB::setColor(RGB_color c)
{
  color = c;
  return color;
}

/* Color BW */

ColorBW::ColorBW(unsigned char l) : Color(l) {}
ColorBW::ColorBW() : Color() {}

unsigned char ColorBW::getLevel()
{
  return color.r;
}

RGB_color const &ColorBW::setColor(unsigned char l)
{
  color = {l, l, l, 0};
  return color;
}
