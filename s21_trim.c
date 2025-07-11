#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *ptr = s21_NULL;

  int len = s21_strlen(src);

  int start_index = 0;
  int end_index = len - 1;

  for (int i = 0; i < len && start_index == 0; i++) {  // обрезаить начало
    if (s21_strchr(trim_chars, src[i]) == s21_NULL) {
      start_index = i;
    }
  }

  for (int i = len - 1; i > 0 && end_index == len - 1; i--) {  // обрезаем конец
    if (s21_strchr(trim_chars, src[i]) == s21_NULL) {
      end_index = i;
    }
  }

  ptr = calloc(end_index - start_index + 2, sizeof(char));

  for (int i = 0, j = start_index; j <= end_index; i++, j++) ptr[i] = src[j];

  return (void *)ptr;
}