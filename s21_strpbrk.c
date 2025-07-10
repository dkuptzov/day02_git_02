#include "s21_string.h"

/* 12 strpbrk
ПОИСК
Находит первый символ в строке str1,
который соответствует любому символу, указанному в str2.
Ищет слева-направо. Первый символ из подстроки str2 в строке str1
Вложенный цикл. Пробегаем строку и пробегаем символы подстроки для каждого
символа строки.  */
/* Думаю, что это будет медленно ппц как из-за ручного break в виде проверки
 * gotcha (found) на каждой(!) итерации */

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;

  if (str1 && str2) {
    for (const char *current_pos = str1; *current_pos != '\0' && !result;
         current_pos++) {
      for (const char *search_char = str2; *search_char != '\0' && !result;
           search_char++) {
        if (*current_pos == *search_char) {
          result = (char *)current_pos;
        }
      }
    }
  }
  return result;
}