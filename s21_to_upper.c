#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *ptr = s21_NULL;
  if (str) {
    int len = (int)s21_strlen(str);
    ptr = (char *)calloc((len + 1), sizeof(char));
    if (ptr) {
      s21_strcpy(ptr, str);  // вопрос к Денису: почему strcpy, а не strncpy?

      for (int i = 0; ptr[i] != '\0'; i++) {
        if (ptr[i] >= 'a' && ptr[i] <= 'z') {
          ptr[i] = ptr[i] - 'a' + 'A';
        }
      }
    }
  }
  return (void *)ptr;
}