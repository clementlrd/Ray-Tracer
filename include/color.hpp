#pragma once

#include "utils.hpp"

#include <cstdint>
#include <string>

/* RGB_color
 *
 * Struct that contain a color representation (r,g,b,a)
 *
 */
struct RGB_color {
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
class Color {
protected:
  RGB_color color;

public:
  Color(RGB_color const& c);
  Color(uint8_t level);
  Color();

  Color& operator*=(double const& t);
  Color& operator+=(Color const& c);
  Color& operator-=(Color const& c);
  Color& operator=(Color const& c);
  bool operator==(Color const& c) const;
  bool operator!=(Color const& c) const;

  RGB_color const& getRGBColor() const;

  std::string repr() const;
  friend std::ostream& operator<<(std::ostream& os, const Color& c);
};

/* ColorRGB
 *
 * ColorRGB class, contain RGB color representation
 *
 */
class ColorRGB : public Color {
public:
  ColorRGB(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);
  ColorRGB();

  RGB_color const& setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);
  RGB_color const& setColor(RGB_color c);
};

/* ColorBW
 *
 * ColorBW class, contain BW color representation
 *
 */
class ColorBW : public Color {
protected:
  uint8_t level;

public:
  ColorBW(uint8_t l);
  ColorBW();

  uint8_t getLevel();
  RGB_color const& setColor(uint8_t l);
};

// By convention double is before Color
inline Color operator*(double const t, Color const color) {
  RGB_color c = color.getRGBColor();
  uint8_t r   = safe_uint8_mult(c.r, t);
  uint8_t g   = safe_uint8_mult(c.g, t);
  uint8_t b   = safe_uint8_mult(c.b, t);
  uint8_t a   = safe_uint8_mult(c.a, t);
  return Color({ r, g, b, a });
};

inline Color operator+(Color const color1, Color const color2) {
  RGB_color c1 = color1.getRGBColor();
  RGB_color c2 = color2.getRGBColor();
  uint8_t r    = safe_uint8_add(c1.r, c2.r);
  uint8_t g    = safe_uint8_add(c1.g, c2.g);
  uint8_t b    = safe_uint8_add(c1.b, c2.b);
  uint8_t a    = safe_uint8_add(c1.a, c2.a);
  return Color({ r, g, b, a });
};

inline Color operator-(Color const color1, Color const color2) {
  RGB_color c1 = color1.getRGBColor();
  RGB_color c2 = color2.getRGBColor();
  uint8_t r    = safe_uint8_sub(c1.r, c2.r);
  uint8_t g    = safe_uint8_sub(c1.g, c2.g);
  uint8_t b    = safe_uint8_sub(c1.b, c2.b);
  uint8_t a    = safe_uint8_sub(c1.a, c2.a);
  return Color({ r, g, b, a });
};