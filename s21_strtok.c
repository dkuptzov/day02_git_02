#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {  // 15
  static char *current_pos = s21_NULL;
  if (str != s21_NULL) {
    current_pos = str;
    while (*current_pos != '\0' &&
           s21_strchr(delim, *current_pos) != s21_NULL) {
      *(current_pos++) = '\0';
    }
  }
  char *res = current_pos;
  if (current_pos != s21_NULL) {
    while (*current_pos != '\0' &&
           s21_strchr(delim, *current_pos) == s21_NULL) {
      current_pos++;
    }
    while (*current_pos != '\0' &&
           s21_strchr(delim, *current_pos) != s21_NULL) {
      *(current_pos++) = '\0';
    }
    if (*res == '\0') {
      res = s21_NULL;
    }
  }
  return res;
}