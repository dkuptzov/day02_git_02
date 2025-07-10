#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {  // 4
  for (int i = 0; i < (int)n; i++) {
    ((char *)str)[i] = (char)c;
  }
  return str;
}