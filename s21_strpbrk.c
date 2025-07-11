#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {  // 12
  char *ptr = s21_NULL;
  int exit = 1;
  for (int i = 0; str1[i] != '\0' && exit == 1; i++) {  // i++
    for (int j = 0; str2[j] != '\0' && exit == 1; j++) {
      if (str1[i] == str2[j]) {
        ptr = (char *)(&str1[i]);
        exit = 0;
      }
    }
  }
  return ptr;
}