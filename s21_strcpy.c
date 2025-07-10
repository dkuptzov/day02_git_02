#include "s21_string.h"

char *s21_strcpy(char *strDest, const char *strSrc) {
  char *temp = strDest;
  for (int i = 0; strSrc[i] != '\0'; i++) {
    strDest[i] = strSrc[i];
  }
  return temp;
}