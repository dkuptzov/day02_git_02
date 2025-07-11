#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {  // 11
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}