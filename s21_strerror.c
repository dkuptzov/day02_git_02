#include "s21_string.h"

char *s21_strerror(int errnum) {  // 10
  static char res[S21_SIZE_ERRORLIST];
  s21_memset(res, 0, s21_strlen(res));
  if (errnum < 0 || errnum >= S21_SIZE_ERRORLIST)
    s21_strcpy(res, "-1");
  else
    s21_strcpy(res, s21_errlist[errnum]);
  return res;
}