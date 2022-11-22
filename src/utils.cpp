#include "utils.hpp"
#include <cstdint>

uint8_t safe_uint8_add(uint8_t a, uint8_t b) {
  return (uint8_t)min(255, (int)a + (int)b);
}

uint8_t safe_uint8_sub(uint8_t a, uint8_t b) {
  return (uint8_t)max(0, (int)a - (int)b);
}