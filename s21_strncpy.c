#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src,
                  s21_size_t n) {  // 8 Копирует до n символов из строки, на
                                   // которую указывает src, в dest.
  char *ptr = s21_NULL;

  int i = 0;
  while (dest[i] != '\0') {
    i++;
  }
  ptr = &((char *)dest)[i];

  for (int j = 0; j < (int)n; j++) {
    ptr[j] = src[j];
  }

  return dest;
}