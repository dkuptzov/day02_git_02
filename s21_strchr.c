#include "s21_string.h"

char *s21_strchr(const char *str, int c) {  // 6
  char *ptr = s21_NULL;
  int exit = 0;
  for (int i = 0; str[i] != '\0' && exit == 0; i++) {
    if (str[i] == c) {
      ptr = (char *)&str[i];
      exit = 1;
    }
  }
  return ptr;
}