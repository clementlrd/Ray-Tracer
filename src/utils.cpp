#include "utils.hpp"

uint8_t safe_uint8_add(uint8_t a, uint8_t b) {
  return (uint8_t)min(255, (int)a + (int)b);
}

uint8_t safe_uint8_sub(uint8_t a, uint8_t b) {
  return (uint8_t)max(0, (int)a - (int)b);
}

uint8_t safe_uint8_mult(uint8_t a, double b) {
  if (b < 0) {
    throw std::invalid_argument("Negative color does not exist !");
  };
  return (uint8_t)min((double)255, (double)a * b);
}