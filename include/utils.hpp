#pragma once

#include <cstdint>

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
