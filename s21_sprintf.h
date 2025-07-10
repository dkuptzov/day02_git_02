#include <stdarg.h>

#ifndef SPRINTF21_H
#define SPRINTF21_H
// #define s21_NULL ((void *)0)

typedef struct param {
  int error;
  int g;
  int count;
  int count_sign;
  int width;
  int accuracy;
  char length;
  char type;
  char c;
  long long int va_int;
  long double va_f;
  short flag_minus;
  short flag_plus;
  short flag_space;
  short flag_hash;
  short flag_zero;
  short flag_dot;
  int str_size;
} param;

int s21_sprintf(char *str, const char *str_format, ...);
void s21_change(param *param);
void s21_alignment(char ***str, param *param);
int s21_str_to_number(const char *str_sing);
// int s21_strlen(const char *str_du);
int s21_str_format(char c);
int s21_str_format_is(char c, param *param);
void s21_update_param(param *param);
void s21_switch_if(char c, char *str_ready, va_list args, param *param);
void s21_malloc_update_main_str(char **str, param *param);
void s21_for_aligment(char ***str, param *param, int len, char c);

#endif