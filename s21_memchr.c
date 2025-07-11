#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {  // 1
  char *ptr = s21_NULL;
  int exit = 0;

  for (int i = 0; ((char *)str)[i] != '\0' && i < (int)n && exit == 0; i++) {
    if (((char *)str)[i] == (char)c) {
      ptr = &((char *)str)[i];  // ptr = (char*)   &  str[i];
      exit = 1;
    }
  }
  return (void *)ptr;
}