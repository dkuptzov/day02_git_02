#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {  // 13
  char *ptr = s21_NULL;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == c) {
      ptr = (char *)(&str[i]);
    }
  }
  return ptr;
}