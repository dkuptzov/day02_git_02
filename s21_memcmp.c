#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {  // 2
  int result = 0;
  for (int i = 0; result == 0 && i < (int)n; i++) {
    result = ((char *)str1)[i] - ((char *)str2)[i];
  }

  return result;
}