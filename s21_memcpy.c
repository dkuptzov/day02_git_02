#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {  // 3
  for (int i = 0; i < (int)n && ((char *)src)[i] != '\0'; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
  }

  return dest;
}