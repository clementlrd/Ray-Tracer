#pragma once

#include <cstdint>
#include <stdexcept>

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

template <typename T>
T max(const T& a, const T& b) {
  return a > b ? a : b;
}

template <typename T>
T min(const T& a, const T& b) {
  return a < b ? a : b;
}

uint8_t safe_uint8_add(uint8_t a, uint8_t b);
uint8_t safe_uint8_sub(uint8_t a, uint8_t b);
uint8_t safe_uint8_mult(uint8_t a, double t);
