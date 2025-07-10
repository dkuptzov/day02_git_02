#include "s21_sprintf.h"

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_case.h"
#include "s21_string.h"

int s21_sprintf(char *str, const char *str_format, ...) {
  param param = {0, 0,    0, 0, 0, -1, 'x', 'x', 'x',
                 0, 0.01, 0, 0, 0, 0,  0,   0,   1024};
  va_list args;
  va_start(args, str_format);
  char *str_sing, *str_ready;
  str_sing = calloc(16 + 1, sizeof(char));
  str_ready = calloc(param.str_size + 1, sizeof(char));
  if (str_sing == s21_NULL || str_ready == s21_NULL) param.error = 1;
  for (int i = 0; str_format[i] != '\0' && param.error == 0; i++) {
    if (str_format[i] == '%') {
      s21_update_param(&param);
      i++;
      while (s21_str_format(str_format[i])) {
        int next_c = 0, is_number = 0;
        if (s21_str_format_is(str_format[i], &param))
          next_c = 0;
        else if (str_format[i] == '*' && param.flag_dot == 1)
          param.accuracy = va_arg(args, int);
        else if (str_format[i] == '*')
          param.width = va_arg(args, int);
        else if (str_format[i] >= '0' && str_format[i] <= '9')
          is_number = 1;
        else if (str_format[i] == 'h' || str_format[i] == 'l' ||
                 str_format[i] == 'L')
          param.length = str_format[i];
        while (str_format[i] >= '0' && str_format[i] <= '9' && is_number == 1)
          str_sing[param.count_sign++] = str_format[i++];
        if (is_number == 1) {
          str_sing[param.count_sign] = '\0';
          if (param.flag_dot == 1)
            param.accuracy = s21_str_to_number(str_sing);
          else
            param.width = s21_str_to_number(str_sing);
          next_c = 1;
          free(str_sing);
          str_sing = calloc(16 + 1, sizeof(char));
          if (str_sing == s21_NULL) param.error = 1;
          param.count_sign = 0;
        }
        if (next_c == 0) i++;
      }
      s21_change(&param);
      param.type = str_format[i];
      va_list copy_args;
      va_copy(copy_args, args);
      s21_switch_if(str_format[i], str_ready, copy_args, &param);
      va_end(copy_args);
      if (str_format[i] == 'c' || str_format[i] == 'd' ||
          str_format[i] == 'u' || str_format[i] == 'x' ||
          str_format[i] == 'X' || str_format[i] == 'o')
        va_arg(args, int);
      else if (param.length == 'L')
        va_arg(args, long double);
      else if (str_format[i] == 'e' || str_format[i] == 'E' ||
               str_format[i] == 'g' || str_format[i] == 'G' ||
               str_format[i] == 'f')
        va_arg(args, double);
      else if (str_format[i] == 's' || str_format[i] == 'p')
        va_arg(args, char *);
    } else
      str_ready[param.count++] = str_format[i];
    s21_malloc_update_main_str(&str_ready, &param);
  }
  va_end(args);
  str_ready[param.count] = '\0';
  if (param.error == 0)
    for (int i = 0; str_ready[i] != '\0'; i++) str[i] = str_ready[i];
  free(str_ready);
  free(str_sing);
  return param.count;
}

void s21_change(param *param) {
  if ((param->flag_dot == 1 || param->flag_minus) && param->flag_zero == 1)
    param->flag_zero = 0;
  if (param->flag_space == 1 && param->flag_plus == 1) param->flag_space = 0;
}

int s21_str_format(char c) {
  int ret = 0;
  if (c == '-' || c == '+' || c == '0' || c == ' ' || c == '.' || c == '#' ||
      c == '*' || (c >= '0' && c <= '9') || c == 'h' || c == 'l' || c == 'L')
    ret = 1;
  return ret;
}

int s21_str_format_is(char c, param *param) {
  int ret = 1;
  if (c == '+')
    param->flag_plus = 1;
  else if (c == ' ')
    param->flag_space = 1;
  else if (c == '-')
    param->flag_minus = 1;
  else if (c == '#')
    param->flag_hash = 1;
  else if (c == '.') {
    param->flag_dot = 1;
    param->accuracy = 0;
  } else if (c == '0' && param->flag_dot == 0)
    param->flag_zero = 1;
  else
    ret = 0;
  return ret;
}

void s21_alignment(char ***str, param *param) {
  if (param->type == 'x' || param->type == 'X') {
    if (param->width > 0 && param->flag_zero == 0)
      s21_for_aligment(str, param, param->width, ' ');
    else if (param->width > 0 && param->flag_zero == 1)
      s21_for_aligment(str, param, param->width, '0');
    else if (param->accuracy > 0)
      s21_for_aligment(str, param, param->accuracy, '0');
  } else if (param->type == 'u' || param->type == 'd' || param->type == 'f' ||
             param->type == 'E' || param->type == 'e') {
    if (param->width > 0 && param->flag_zero == 0) {
      if (param->va_f < 0) param->width--;
      s21_for_aligment(str, param, param->width, ' ');
      if (param->va_int < 0 && param->accuracy <= 0 && param->flag_minus == 0)
        (**str)[param->count++] = '-';
      else if (param->va_f < 0 && param->flag_minus == 0)
        (**str)[param->count++] = '-';
    }
    if (param->va_int < 0 && param->width > 0 && param->accuracy > 0)
      (**str)[param->count++] = '-';
    if (param->width > 0 && param->flag_zero == 1) {
      if (param->accuracy < 0) param->accuracy = 0;
      s21_for_aligment(str, param, param->width - param->accuracy, '0');
    }
    if (param->accuracy > 0 && param->va_f != 0.0 && param->type != 'E' &&
        param->type != 'e')
      s21_for_aligment(str, param, param->accuracy, '0');
  } else if (param->type == 's' || param->type == 'p') {
    if (param->width > 0 && (param->flag_zero == 0 || param->flag_dot == 1))
      s21_for_aligment(str, param, param->width, ' ');
    else if (param->width > 0 && param->flag_zero == 1)
      s21_for_aligment(str, param, param->width, '0');
    else if (param->accuracy > 0)
      s21_for_aligment(str, param, param->accuracy, '0');
  } else if (param->type == 'c') {
    if (param->width > 0) s21_for_aligment(str, param, param->width, ' ');
  } else if (param->type == 'o') {
    if (param->width > 0) s21_for_aligment(str, param, param->width, ' ');
    if (param->accuracy > 0) s21_for_aligment(str, param, param->accuracy, '0');
  } else {
    if ((param->width > 0 && param->flag_zero == 0) || param->accuracy > 0)
      s21_for_aligment(str, param, param->width, '0');
    else if (param->width > 0)
      s21_for_aligment(str, param, param->width, ' ');
  }
}

void s21_for_aligment(char ***str, param *param, int len, char c) {
  for (int i = 0; i < len; i++) (**str)[param->count++] = c;
}

int s21_str_to_number(const char *str_sing) {
  int number = 0, multiplier = 1;
  for (int i = 0; str_sing[i] != '\0'; i++) {
    number *= multiplier;
    switch (str_sing[i]) {
      case '0':
        break;
      case '1':
        number += 1;
        break;
      case '2':
        number += 2;
        break;
      case '3':
        number += 3;
        break;
      case '4':
        number += 4;
        break;
      case '5':
        number += 5;
        break;
      case '6':
        number += 6;
        break;
      case '7':
        number += 7;
        break;
      case '8':
        number += 8;
        break;
      case '9':
        number += 9;
        break;
      default:
        break;
    }
    multiplier = 10;
  }
  return number;
}

void s21_update_param(param *param) {
  param->count_sign = 0;
  param->width = 0;
  param->accuracy = -1;
  param->length = 'x';
  param->flag_hash = 0;
  param->flag_minus = 0;
  param->flag_plus = 0;
  param->flag_space = 0;
  param->flag_zero = 0;
  param->flag_dot = 0;
  param->va_int = 0;
  param->va_f = 0.01;
}

void s21_switch_if(char c, char *str_ready, va_list args, param *param) {
  if (c == '%')
    str_ready[param->count++] = '%';
  else if (c == 'c') {
    param->c = va_arg(args, int);
    s21_case_c(&str_ready, param);
  } else if (c == 'd') {
    param->va_int = s21_type(va_arg(args, long long int), param);
    s21_case_u(&str_ready, param);
  } else if (c == 'e' || c == 'E' || c == 'g' || c == 'G' || c == 'f') {
    if (param->length == 'L')
      param->va_f = va_arg(args, long double);
    else {
      long double temp = va_arg(args, double);
      param->va_f = (long double)temp;
    }
    if (c == 'f')
      s21_case_f(&str_ready, param);
    else
      s21_case_g(&str_ready, param);
  } else if (c == 'u') {
    param->va_int = va_arg(args, long long int);
    s21_case_u(&str_ready, param);
  } else if (c == 's') {
    const char *str_d = va_arg(args, char *);
    s21_case_s(&str_ready, str_d, param);
  } else if (c == 'x' || c == 'X') {
    if (param->length == 'l')
      param->va_int = va_arg(args, long int);
    else {
      int temp_x = va_arg(args, int);
      param->va_int = (long long int)temp_x;
    }
    if (param->va_int == -2147483648) param->va_int *= -1;
    if (param->va_int >= 0)
      s21_case_x_plus(&str_ready, param);
    else
      s21_case_x_minus(&str_ready, param);
  } else if (c == 'o') {
    if (param->length == 'l')
      param->va_int = va_arg(args, long int);
    else if (param->length == 'h') {
      long long int temp_o = va_arg(args, long long int);
      param->va_int = (long long int)temp_o;
      param->va_int = s21_type(param->va_int, param);
    } else {
      int temp_o = va_arg(args, int);
      param->va_int = (long long int)temp_o;
    }
    if (param->flag_hash == 1) str_ready[param->count++] = '0';
    if (param->va_int >= 0)
      s21_case_o_plus(&str_ready, param);
    else
      s21_case_o_minus(&str_ready, param);
  } else if (c == 'p')
    s21_case_p(&str_ready, va_arg(args, char *), param);
}

void s21_malloc_update_main_str(char **str, param *param) {
  if (param->count > param->str_size / 2) {
    param->str_size *= 2;
    char *temp = realloc(*str, param->str_size + 1);
    if (temp == NULL)
      param->error = 1;
    else
      *str = temp;
  }
}