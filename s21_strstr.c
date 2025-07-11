#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {  // 14
  char *ptr = s21_NULL;
  int flag = 1;
  for (int i = 0; i < (int)s21_strlen(haystack) && flag == 1; i++) {
    ptr = (char *)&haystack[i];
    if (s21_strncmp(ptr, needle, s21_strlen(needle)) == 0) {
      flag = 0;
    }
  }
  return ptr;
}