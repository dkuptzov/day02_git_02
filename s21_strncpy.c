#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src,
                  s21_size_t n) {  // 8 Копирует до n символов из строки, на
                                   // которую указывает src, в dest.
  for (int i = 0; i < (int)n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  return dest;
}