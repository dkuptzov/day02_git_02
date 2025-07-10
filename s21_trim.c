#include "s21_string.h"

/*
Возвращает новую строку, в которой удаляются все начальные и конечные вхождения
набора заданных символов (trim_chars) из данной строки (src).
В случае какой-либо ошибки следует вернуть значение NULL.
*/

/* start, end */

/* Найти первый символ, который не входит в trim_chars - это будет start (начало
   строки) Найти последний символ, который не входит в trim_chars - это будет
   end конец строки Вытащить все, что от start до end Вернуть результат example:
    ++aboba++
    trim_chars = "+";
    (++) aboba (++)
    res: aboba
    */

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src && trim_chars) {
    int start = 0;
    int end = s21_strlen(src);

    while (src[start] && s21_strchr(trim_chars,
                                    src[start])) {  // strchr вернет указатель,
                                                    // а если не найдет, то NULL
      start++;  // двигаем start вперед, если нашли трим
    }

    while (end > start && s21_strchr(trim_chars, src[end - 1])) {
      end--;  // двигаемся назад
    }

    result = (char *)malloc(end - start + 1);

    if (result) {
      int length_result = end - start;
      s21_strncpy(result, src + start,
                  length_result);  // пропускаем trim символы и копируем до их
                                   // начала в конце строки
      result[length_result] = '\0';  // +1 не надо, т.к. length_result это
                                     // индекс с учетом выделенной памяти
    }
  }
  return (void *)result;
}