#ifndef __UTILS_HPP__
#define __UTILS_HPP__

template <typename T>
T max(const T &a, const T &b)
{
  return a > b ? a : b;
}

template <typename T>
T min(const T &a, const T &b)
{
  return a < b ? a : b;
}

unsigned char safe_char_add(unsigned char a, unsigned char b);
unsigned char safe_char_sub(unsigned char a, unsigned char b);

#endif