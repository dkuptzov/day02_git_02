#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {  // 1
  unsigned char *ptr = (unsigned char *)str;
  void *result = s21_NULL;
  int flag = 0;
  for (s21_size_t i = 0; i < n && !flag; i++) {
    if (ptr[i] == (unsigned char)c) {
      result = &(ptr)[i];  // ptr = (char*) &  str[i];
      flag = 1;
    }
  }
  return (void *)result;
}