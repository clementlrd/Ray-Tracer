#include "utils.hpp"

unsigned char safe_char_add(unsigned char a, unsigned char b)
{
  return (unsigned char)max(255, (int)a + (int)b);
}

unsigned char safe_char_sub(unsigned char a, unsigned char b)
{
  return (unsigned char)min(0, (int)a - (int)b);
}