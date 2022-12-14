#include "color.hpp"

#include <cstdint>

/* Color */

Color::Color(RGB_color const& c) : color(c) {}
Color::Color(uint8_t level) : color { level, level, level, 0 } {}
Color::Color() : color { 0, 0, 0, 0 } {}

Color& Color::operator*=(double const& t) {
  color.r = safe_uint8_mult(color.r, t);
  color.g = safe_uint8_mult(color.g, t);
  color.b = safe_uint8_mult(color.b, t);
  color.a = safe_uint8_mult(color.a, t);
  return *this;
}

Color& Color::operator+=(Color const& c) {
  color.r = safe_uint8_add(color.r, c.color.r);
  color.g = safe_uint8_add(color.g, c.color.g);
  color.b = safe_uint8_add(color.b, c.color.b);
  color.a = safe_uint8_add(color.a, c.color.a);
  return *this;
}

Color& Color::operator-=(Color const& c) {
  color.r = safe_uint8_sub(color.r, c.color.r);
  color.g = safe_uint8_sub(color.g, c.color.g);
  color.b = safe_uint8_sub(color.b, c.color.b);
  color.a = safe_uint8_sub(color.a, c.color.a);
  return *this;
}

Color& Color::operator=(Color const& c) {
  color = c.color;
  return *this;
};

bool Color::operator==(Color const& c) const {
  return color.r == c.color.r && color.g == c.color.g && color.b == c.color.b
         && color.a == c.color.a;
}

bool Color::operator!=(Color const& c) const { return !(*this == c); }

RGB_color const& Color::getRGBColor() const { return color; }

std::string Color::repr() const {
  const auto [r, g, b, a] = color;
  return "(" + std::to_string(r) + "," + std::to_string(g) + ","
         + std::to_string(b) + " | " + std::to_string(a) + ")";
}

std::ostream& operator<<(std::ostream& os, const Color& c) {
  os << c.repr();
  return os;
}

/* Color RGB */

ColorRGB::ColorRGB(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : Color({ r, g, b, a }) {}
ColorRGB::ColorRGB() : Color() {}

RGB_color const&
    ColorRGB::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  color = { r, g, b, a };
  return color;
}
RGB_color const& ColorRGB::setColor(RGB_color c) {
  color = c;
  return color;
}

/* Color BW */

ColorBW::ColorBW(uint8_t l) : Color(l) {}
ColorBW::ColorBW() : Color() {}

uint8_t ColorBW::getLevel() { return color.r; }

RGB_color const& ColorBW::setColor(uint8_t l) {
  color = { l, l, l, 0 };
  return color;
}
