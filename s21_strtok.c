#include "s21_string.h"

/* аналог split() из Python */

/* делит строку на части (токены) по установленным разделителям
нарезает на токены '\0', запоминает позицию в строке
два разделителя подряд и более считаются за один
если токены кончились, то возвращает NULL
*/
int s21_isdelim(char ch, const char *delim);

char *s21_strtok(char *str, const char *delim) {
  static char *next_token = s21_NULL;  // сохраняем позицию между вызовами
  char *token_start = s21_NULL;  // начало текущего токена
  int found = 0;                 // флаг для ретернов

  if (str != s21_NULL) {  // начинаем с новой строки
    next_token = str;
  }

  if (next_token != s21_NULL && *next_token != '\0') {
    while (*next_token != '\0' && s21_isdelim(*next_token, delim)) {
      next_token++;  // на начале игнорим разделители
    }

    if (*next_token != '\0') {
      token_start = next_token;  // сохраняем начало токена

      found = 1;
      // ищем где токен заканчивается в цикле (пока не встретим конец строки или
      // разделитель)
      while (*next_token != '\0' && !s21_isdelim(*next_token, delim)) {
        next_token++;
      }

      if (*next_token !=
          '\0') {  // строка еще не кончилась -> обрезаем и двигаемся дальше
        *next_token = '\0';  // тут обрезали
        next_token++;        // тут пошли дальше
      } else {
        next_token = s21_NULL;  // нет строки - нет токенов
      }
    }
  }
  return found ? token_start : s21_NULL;
}

int s21_isdelim(char ch, const char *delim) {
  int result = 0;

  while (*delim != '\0' && result != 1) {
    if (ch == *delim) {
      result = 1;
    } else {
      delim++;
    }
  }
  return result;
}