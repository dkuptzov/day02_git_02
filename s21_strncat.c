#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {  // 5
  int i = 0;
  while (dest[i] != '\0') {
    i++;
  }

  for (int j = 0; j < (int)n && src[j] != '\0'; j++) {
    dest[i + j] = src[j];
  }

  return dest;
}