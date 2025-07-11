#include "s21_string.h"

void *s21_to_lower(const char *str) {
  int len = (int)s21_strlen(str);
  char *ptr = (char *)calloc((len + 1), sizeof(char));
  s21_strcpy(ptr, str);

  for (int i = 0; ptr[i] != '\0'; i++) {
    if (ptr[i] >= 'A' && ptr[i] <= 'Z') {
      ptr[i] = ptr[i] - 'A' + 'a';
    }
  }

  return (void *)ptr;
}