#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {  // 2
  const unsigned char *ptr1 = str1;
  const unsigned char *ptr2 = str2;
  int result = 0;
  for (s21_size_t i = 0; result == 0 && i < n; i++) {
    result = (int)ptr1[i] - (int)ptr2[i];
  }

  return result;
}