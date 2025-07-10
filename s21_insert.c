#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  int len1 = s21_strlen(src);
  int len2 = s21_strlen(str);

  char *res = (char *)calloc(len1 + len2 + 1, sizeof(char));

  int res_index = 0;

  for (int i = 0; i < (int)start_index; i++, res_index++)  // начало до индекса
    res[res_index] = src[i];

  for (int i = 0; i < len2; i++, res_index++) res[res_index] = str[i];

  for (int i = start_index; i < len1; i++, res_index++) res[res_index] = src[i];

  return (void *)res;
}