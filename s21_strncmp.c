#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {  // 7
  int answer = 0;
  for (int i = 0; answer == 0 && i < (int)n; i++) {
    answer = str1[i] - str2[i];
  }
  return answer;
}