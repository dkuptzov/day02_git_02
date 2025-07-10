#include "s21_case.h"

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void s21_case_c(char **str, param *param) {
  param->width -= 1;
  if (param->flag_minus == 1 && param->width > 0) {
    (*str)[param->count++] = param->c;
    s21_alignment(&str, param);
  } else if (param->flag_zero == 1 || param->flag_plus == 1 ||
             param->width > 0) {
    s21_alignment(&str, param);
    (*str)[param->count++] = param->c;
  } else
    (*str)[param->count++] = param->c;
}

void s21_case_u(char **str, param *param) {
  char *str_du = s21_NULL;
  int dont_print = 0, zero_3 = 0, acc = param->accuracy;
  if (param->length == 'l' && param->va_int == LLONG_MIN) {
    const char str_llmin[23] = "9223372036854775808";
    str_du = calloc(20, sizeof(char));
    for (int i = 0; i < 19; i++) str_du[i] = str_llmin[i];
  } else
    str_du = s21_atoi_new(param);
  int strlen = s21_strlen(str_du);
  if (param->accuracy == 0 && param->va_int == 0) strlen = 0;
  if (param->flag_space == 1 && param->type != 'u' && param->va_int >= 0) {
    (*str)[param->count++] = ' ';
    param->width--;
  } else if (param->flag_plus == 1 && param->va_int >= 0 &&
             param->type != 'u' &&
             (param->flag_minus == 1 || param->flag_space == 1 ||
              param->flag_zero == 1))
    param->width--;
  if (param->flag_hash == 1 && param->flag_space == 0 && param->va_int != 0)
    param->width += 2;
  if ((param->width < strlen && param->accuracy <= 0 && param->va_int < 0 &&
       param->type == 'd') ||
      (param->flag_minus == 1 && param->va_int < 0 && param->type == 'd')) {
    param->width--;
    param->flag_zero = 0;
  }
  if (param->width == 0 && param->accuracy == 0 && param->va_int == 0)
    zero_3 = 1;
  s21_width_accuracy(strlen, param);
  if (param->va_int == 0 && param->width <= 0 && param->accuracy <= 0) {
    dont_print = 1;
    if (param->flag_plus == 1 && param->type != 'u')
      (*str)[param->count++] = '+';
    if (zero_3 == 0) (*str)[param->count++] = '0';
  } else if (param->flag_minus == 1) {
    dont_print = 1;
    if (param->type != 'u' && param->flag_plus == 1 && param->va_int >= 0) {
      (*str)[param->count++] = '+';
      param->flag_plus = 0;
    }
    if (param->va_int < 0) (*str)[param->count++] = '-';
    s21_case_u_width_acc(str, param, param->accuracy, '0');
    param->accuracy = 0;
    for (int j = 0; str_du[j] != '\0'; j++) (*str)[param->count++] = str_du[j];
    s21_case_u_width_acc(str, param, param->width, ' ');
  } else if (param->width > 0 && param->accuracy > 0) {
    dont_print = 1;
    if (param->flag_plus == 1 && param->va_int >= 0) param->width--;
    s21_case_u_width_acc(str, param, param->width, ' ');
    if (param->flag_plus == 1 && param->va_int >= 0)
      (*str)[param->count++] = '+';
    else if (param->va_int < 0)
      (*str)[param->count++] = '-';
    s21_case_u_width_acc(str, param, param->accuracy, '0');
    for (int j = 0; str_du[j] != '\0'; j++) (*str)[param->count++] = str_du[j];
  } else if (param->flag_zero == 1 ||
             (param->accuracy > 0 && param->width <= 0)) {
    if (param->va_int < 0)
      (*str)[param->count++] = '-';
    else if (param->flag_plus == 1 && param->type != 'u') {
      (*str)[param->count++] = '+';
      param->flag_plus = 0;
    }
    s21_alignment(&str, param);
  } else if (param->width > 0) {
    s21_alignment(&str, param);
    if (param->flag_plus == 1 && param->va_int > 0) {
      if (param->flag_space == 0) param->count--;
      (*str)[param->count++] = '+';
      param->flag_plus = 0;
    } else if (param->va_int == 0 && acc != 0)
      (*str)[param->count++] = '0';
  } else if (param->length == 'h') {
    while (param->va_int >= 65536) param->va_int -= 65536;
    if (param->va_int < 0) (*str)[param->count++] = '-';
    str_du = s21_atoi_new(param);
  } else if (param->accuracy <= 0 && param->va_int < 0 && param->type != 'u')
    (*str)[param->count++] = '-';
  if (param->type != 'u' && param->flag_plus == 1 && param->va_int > 0 &&
      dont_print == 0)
    (*str)[param->count++] = '+';
  if ((param->flag_minus == 0) &&
      !(param->flag_dot == 1 && param->accuracy == 0 && param->va_int == 0) &&
      dont_print == 0) {
    for (int j = 0; str_du[j] != '\0'; j++) (*str)[param->count++] = str_du[j];
  }
  free(str_du);
}

void s21_case_u_width_acc(char **str, param *param, int len, char c) {
  for (int i = 0; i < len; i++) (*str)[param->count++] = c;
}

void s21_case_f(char **str, param *param) {
  char *str_int;
  if (param->va_f == 0.0000005 && param->flag_dot == 0) param->va_f = 0.0000001;
  str_int = s21_atoi_new(param);
  int strlen = s21_strlen(str_int);
  if (param->va_f == 0.0 && param->type == 'f')
    s21_width_accuracy_f_0(strlen, param);
  else
    s21_width_accuracy(strlen, param);
  if (param->flag_plus == 1 && param->flag_zero == 1 && param->va_f >= 0)
    (*str)[param->count++] = '+';
  if (param->flag_plus == 1 && param->width > 0) param->width--;
  if (param->flag_space == 1 && param->va_f >= 0) {
    (*str)[param->count++] = ' ';
    param->width--;
  }
  if (param->va_f < 0 && param->width <= 0 && param->accuracy <= 0)
    (*str)[param->count++] = '-';
  if (param->width > 0) {
    if (param->va_f < 0 && param->flag_minus == 1)
      (*str)[param->count++] = '-';
    else if (param->va_f < 0 && param->flag_zero == 1) {
      (*str)[param->count++] = '-';
      if (param->flag_plus == 0) param->width--;
    }
    if (param->flag_zero == 1) s21_alignment(&str, param);
    if (param->flag_minus == 1)
      for (int j = 0; str_int[j] != '\0'; j++)
        (*str)[param->count++] = str_int[j];
    if (param->flag_zero == 0) s21_alignment(&str, param);
  }
  if (param->flag_plus == 1 && param->flag_zero == 0 && param->va_f >= 0)
    (*str)[param->count++] = '+';
  if (param->flag_minus == 0 || (param->width <= 0 && param->flag_minus == 1))
    for (int j = 0; str_int[j] != '\0'; j++)
      (*str)[param->count++] = str_int[j];
  if (param->type == 'f' && param->va_f == 0.0 && param->flag_space == 0 &&
      param->length == 'x' && param->accuracy == 0 && param->flag_dot == 1) {
    while ((*str)[param->count - 1] == '0') param->count--;
    if ((*str)[param->count - 1] == '.') param->count--;
  } else if (param->type == 'f' && param->va_f == 0.0 && param->accuracy > 0 &&
             param->flag_space == 0) {
    while (param->accuracy-- > 1) (*str)[param->count++] = '0';
  }
  free(str_int);
}

void s21_case_g(char **str, param *param) {
  char *str_int;
  int less_zero = 0, is_dot = 0;
  long double param_va_f = param->va_f;
  if (param->flag_plus == 1 && param->va_f >= 0)
    (*str)[param->count++] = '+';
  else if (param->flag_space == 1 && param->va_f >= 0)
    (*str)[param->count++] = ' ';
  if (param_va_f < 0) {
    param_va_f *= (-1.0);
    less_zero = 1;
  }
  if (param->va_f == 0.0 && (param->type == 'g' || param->type == 'G'))
    (*str)[param->count++] = '0';
  else if ((param->va_f >= pow(10, 6) || param_va_f >= pow(10, 6)) ||
           ((param->type == 'e' || param->type == 'E') &&
            (param->va_f >= 1 || param_va_f >= 1))) {
    int count = s21_case_g_1(param, less_zero, 1);
    str_int = s21_atoi_new(param);
    param->width = (param->width > (int)s21_strlen(str_int))
                       ? param->width - (int)s21_strlen(str_int) - 4
                       : -1;
    if (param->flag_zero == 1 || param->width >= 0)
      s21_alignment(&str, param);
    else if (param->va_f < 0)
      (*str)[param->count++] = '-';
    for (int j = 0; str_int[j] != '\0'; j++)
      (*str)[param->count++] = str_int[j];
    int param_count = param->count;
    if (param->type == 'g' || param->type == 'G') {
      for (int i = param_count - 1; i >= 0; i--)
        if ((*str)[i] == '.') is_dot = 1;
      if (param->flag_hash == 0 && is_dot == 1) {
        param->count--;
        while ((*str)[param->count] == '0') param->count--;
        if ((*str)[param->count] == '.') (*str)[param->count] = '\0';
        param->count++;
      }
    }
    (*str)[param->count++] =
        (param->type == 'E' || param->type == 'G') ? 'E' : 'e';
    (*str)[param->count++] = '+';
    if (count >= 10)
      (*str)[param->count++] = '0' + ((count / 10) % 10);
    else
      (*str)[param->count++] = '0';
    (*str)[param->count++] = '0' + (count % 10);
  } else if ((param->va_f < pow(10, -4) || param_va_f < pow(10, -4)) ||
             ((param->type == 'e' || param->type == 'E') &&
              (param->va_f < 1 || param_va_f < 1))) {
    int count = s21_case_g_1(param, less_zero, 2);
    if (param->accuracy == 0) param->va_f = round(param->va_f);
    str_int = s21_atoi_new(param);
    param->width = (param->width > (int)s21_strlen(str_int))
                       ? param->width - (int)s21_strlen(str_int) - 4
                       : -1;
    if (param->flag_zero == 1 || param->width >= 0)
      s21_alignment(&str, param);
    else if (param->va_f < 0)
      (*str)[param->count++] = '-';
    for (int i = s21_strlen(str_int) - 1;
         i >= 0 && (param->type == 'g' || param->type == 'G'); i--) {
      if (str_int[i] == '0' || str_int[i] == '.' || str_int[i] == '\0')
        str_int[i] = '\0';
      else
        break;
    }
    for (int j = 0; str_int[j] != '\0'; j++)
      (*str)[param->count++] = str_int[j];
    (*str)[param->count++] =
        (param->type == 'E' || param->type == 'G') ? 'E' : 'e';
    (*str)[param->count++] = (param->va_f == 0.0) ? '+' : '-';
    if (count >= 100) (*str)[param->count++] = '0' + ((count / 100) % 10);
    if (count >= 10)
      (*str)[param->count++] = '0' + ((count / 10) % 10);
    else
      (*str)[param->count++] = '0';
    (*str)[param->count++] = '0' + (count % 10);
  } else {
    s21_case_g_2(param);
    str_int = s21_atoi_new(param);
    for (int j = 0; str_int[j] != '\0'; j++)
      (*str)[param->count++] = str_int[j];
    int param_count = param->count;
    for (int i = param_count - 1; i >= 0; i--)
      if ((*str)[i] == '.') is_dot = 1;
    if (param->flag_hash == 0 && is_dot == 1) {
      param->count--;
      while ((*str)[param->count] == '0') param->count--;
      if ((*str)[param->count] == '.') (*str)[param->count] = '\0';
      param->count++;
    }
  }
}

int s21_case_g_1(param *param, int less_zero, int x) {
  int count = 0;
  if (less_zero == 1) param->va_f *= -1;
  if (x == 1) {
    while (param->va_f >= 10.0) {
      param->va_f = param->va_f / 10;
      count++;
    }
  } else if (x == 2) {
    while ((param->va_f + 0.000001) < 1.0 && param->va_f != 0.0) {
      param->va_f *= 10;
      count++;
    }
  }
  if (less_zero == 1) param->va_f *= -1;
  return count;
}

void s21_case_g_2(param *param) {
  if (param->va_f < 1.0)
    param->g = 0;
  else if (param->va_f < 10.0)
    param->g = 1;
  else if (param->va_f < 100.0)
    param->g = 2;
  else if (param->va_f < 1000.0)
    param->g = 3;
  else if (param->va_f < 10000.0)
    param->g = 4;
  else if (param->va_f < 100000.0)
    param->g = 5;
  else
    param->g = 6;
}

void s21_case_s(char **str, const char *str_d, param *param) {
  int strlen = s21_strlen(str_d);
  if (param->flag_dot == 1 && param->accuracy == -1) param->accuracy = 0;
  if (param->width >= 0 && param->accuracy >= 0) {
    if (param->flag_minus == 1 && param->width >= strlen &&
        param->accuracy >= strlen)
      param->width -= strlen;
    else if (param->width < strlen && param->accuracy < strlen &&
             param->width >= param->accuracy)
      param->width -= param->accuracy;
    else if (param->width < strlen && param->accuracy < strlen &&
             param->accuracy > param->width)
      param->width = 0;
    else if (param->width > param->accuracy && param->width >= strlen)
      param->width -= param->accuracy;
    else if (param->accuracy >= param->width && param->accuracy >= strlen) {
      param->accuracy = -1;
      param->width -= strlen;
    }
  } else if (param->width >= 0) {
    if (param->width > strlen)
      param->width = param->width - strlen;
    else
      param->width = 0;
  }
  if (param->flag_minus == 1 && param->flag_dot == 0) {
    for (int j = 0; str_d[j] != '\0'; j++) (*str)[param->count++] = str_d[j];
    s21_alignment(&str, param);
  } else if (param->flag_zero == 1 || param->flag_plus == 1 ||
             (param->width > 0 && param->accuracy == -1)) {
    s21_alignment(&str, param);
    for (int j = 0; str_d[j] != '\0'; j++) (*str)[param->count++] = str_d[j];
  } else if (param->flag_minus == 0 && param->accuracy == -1)
    for (int j = 0; str_d[j] != '\0'; j++) (*str)[param->count++] = str_d[j];
  else if (param->width >= 0 && param->accuracy >= 0) {
    if (param->flag_minus == 0) {
      int par_acc = param->accuracy - s21_strlen(str_d);
      while (param->width-- > 0) (*str)[param->count++] = ' ';
      while (par_acc-- > 0) (*str)[param->count++] = ' ';
    }
    for (int j = 0; str_d[j] != '\0'; j++) {
      if (param->accuracy-- > 0)
        (*str)[param->count++] = str_d[j];
      else if (param->accuracy == 0)
        break;
    }
    while (param->width-- > 0) (*str)[param->count++] = ' ';
  }
}

void s21_case_x_plus(char **str, param *param) {
  int count = 0;
  long long int temp_va = param->va_int;
  char *str_x;
  str_x = calloc(16 + 1, sizeof(char));
  if (param->va_int == 0) str_x[count++] = '0';
  while (temp_va > 0) {
    long long int x = temp_va % 16;
    temp_va /= 16;
    if (x > 9)
      str_x[count++] = s21_x_plus_minus_switch(x, param);
    else
      str_x[count++] = '0' + (x % 10);
  }
  str_x[count] = '\0';
  int strlen = s21_strlen(str_x);
  s21_width_accuracy(strlen, param);
  int dont_print = 0;
  if (param->width > 0 && param->flag_minus == 0 && param->flag_zero == 0) {
    s21_alignment(&str, param);
    if ((param->flag_hash == 1) && param->va_int != 0) {
      dont_print = 1;
      (*str)[param->count++] = '0';
      (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
    }
  } else if (param->width > 0 && param->flag_zero == 1) {
    if ((param->flag_hash == 1) && param->va_int != 0) {
      dont_print = 1;
      (*str)[param->count++] = '0';
      (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
    }
    s21_alignment(&str, param);
  }
  if (param->accuracy > 0) {
    param->width = 0;
    if (param->flag_hash == 1 && param->va_int != 0 && dont_print == 0) {
      (*str)[param->count++] = '0';
      (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
    }
    s21_alignment(&str, param);
    param->flag_minus = 0;
  } else if ((param->flag_hash == 1) && dont_print == 0 && param->va_int != 0) {
    (*str)[param->count++] = '0';
    (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
  }
  for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_x[i];
  if (param->flag_minus == 1) s21_alignment(&str, param);
  free(str_x);
}

char s21_x_plus_minus_switch(long long int x, const param *param) {
  char ret = '\0';
  switch (x % 10) {
    case 0:
      ret = (param->type == 'x') ? 'a' : 'A';
      break;
    case 1:
      ret = (param->type == 'x') ? 'b' : 'B';
      break;
    case 2:
      ret = (param->type == 'x') ? 'c' : 'C';
      break;
    case 3:
      ret = (param->type == 'x') ? 'd' : 'D';
      break;
    case 4:
      ret = (param->type == 'x') ? 'e' : 'E';
      break;
    case 5:
      ret = (param->type == 'x') ? 'f' : 'F';
      break;
    default:
      break;
  }
  return ret;
}

void s21_case_x_minus(char **str, param *param) {
  int count = 0, count_revers = 0, plus = 0;
  long long int result;
  char *binary_str_revers, *binary_str, *str_x;
  s21_make_str_case_x(&str_x, &binary_str_revers, &binary_str, 64, param);
  long long int x_va_int = param->va_int * -1;
  while (x_va_int > 0) {
    binary_str_revers[count_revers++] = (x_va_int % 2 == 0) ? '0' : '1';
    x_va_int /= 2;
  }
  int zero = 4 - (count_revers % 4), multi = 0;
  count = 0;
  while (zero-- != 0) binary_str[count++] = '0';
  for (int i = count_revers - 1; i >= 0; i--)
    binary_str[count++] = binary_str_revers[i];
  s21_case_x_for(&count, &plus, &binary_str);
  count_revers = 0;
  for (int j = 0; j < 8 - (count / 4); j++)
    str_x[count_revers++] = (param->type == 'x') ? 'f' : 'F';
  multi = 3;
  result = 0;
  for (int i = 0; i < count; i++) {
    if (binary_str[i] == '1') result += (pow(2, multi));
    multi--;
    if ((i + 1) % 4 == 0 && i != 0) {
      if (result > 9)
        str_x[count_revers++] = s21_x_plus_minus_switch(result, param);
      else
        str_x[count_revers++] = '0' + (result % 10);
      result = 0;
      multi = 3;
    }
  }
  str_x[count_revers] = '\0';
  int strlen = s21_strlen(str_x);
  s21_width_accuracy(strlen, param);
  if ((param->width > 0 && param->flag_minus == 0) || (param->accuracy > 0)) {
    if (param->width > 0 && param->flag_minus == 0) s21_alignment(&str, param);
    if ((param->flag_hash == 1) && param->va_int != 0) {
      (*str)[param->count++] = '0';
      (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
    }
    if (param->accuracy > 0) s21_alignment(&str, param);
  } else if (param->flag_hash == 1) {
    (*str)[param->count++] = '0';
    (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
  }
  for (int i = 0; i < count_revers; i++) {
    if (param->length != 'h' || i > count_revers - 5)
      (*str)[param->count++] = str_x[i];
  }
  s21_free_str_case_x(&str_x, &binary_str_revers, &binary_str);
}

void s21_case_x_for(int *count, int *plus, char **binary_str) {
  for (int i = *count - 1; i >= 0; i--) {
    if ((*binary_str)[i] == '1' && i == *count - 1)
      (*binary_str)[i] = '1';
    else if ((*binary_str)[i] == '0' && i == *count - 1)
      *plus = 1;
    else if ((*binary_str)[i] == '1' && *plus == 1)
      *plus = 0;
    else if ((*binary_str)[i] == '0' && *plus == 0)
      (*binary_str)[i] = '1';
    else if ((*binary_str)[i] == '1' && *plus == 0)
      (*binary_str)[i] = '0';
  }
}

void s21_case_o_plus(char **str, param *param) {
  int count = 0;
  char *str_o;
  str_o = calloc(1024 + 1, sizeof(char));
  if (param->va_int == 0) str_o[count++] = '0';
  while (param->va_int > 0) {
    str_o[count++] = '0' + param->va_int % 8;
    param->va_int /= 8;
  }
  int strlen = s21_strlen(str_o);
  s21_width_accuracy(strlen, param);
  if (param->flag_minus == 1 && param->flag_dot == 0) {
    for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
    s21_alignment(&str, param);
  } else if (param->width > 0) {
    s21_alignment(&str, param);
    for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
  } else if (param->accuracy > 0) {
    s21_alignment(&str, param);
    for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
  } else
    for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
  free(str_o);
}

void s21_case_o_minus(char **str, param *param) {
  int count = 0, count_revers = 0, plus = 1, three = 0;
  char *binary_str_revers, *binary_str, *str_x8, *str3;
  binary_str_revers = calloc(32 + 1, sizeof(char));
  binary_str = calloc(32 + 1, sizeof(char));
  str_x8 = calloc(32 + 1, sizeof(char));
  str3 = calloc(4 + 1, sizeof(char));
  param->va_int *= -1;
  while (param->va_int > 0) {
    binary_str_revers[count_revers++] = (param->va_int % 2 == 0) ? '0' : '1';
    param->va_int /= 2;
  }
  binary_str[count++] = '1';
  for (int i = 0; i < 32 - count_revers; i++) binary_str[count++] = '0';
  for (int i = count_revers - 1; i >= 0; i--)
    binary_str[count++] = binary_str_revers[i];
  for (int i = 0; binary_str[i] != '\0'; i++)
    binary_str[i] = (binary_str[i] == '0') ? '1' : '0';
  for (int i = count - 1; i >= 0; i--) {
    if (binary_str[i] == '1' && plus == 1)
      binary_str[i] = '0';
    else if (binary_str[i] == '0' && plus == 1) {
      binary_str[i] = '1';
      plus = 0;
    }
  }
  count = 0;
  for (int i = 0; binary_str[i] != '\0'; i++) {
    str3[three++] = binary_str[i];
    if (three == 3) {
      str3[three] = '\0';
      str_x8[count++] = s21_x8(&str3);
      three = 0;
    }
  }
  str_x8[count] = '\0';
  int strlen = s21_strlen(str_x8);
  s21_width_accuracy(strlen, param);
  if (param->width > 0) {
    s21_alignment(&str, param);
    for (int i = 0; str_x8[i] != '\0'; i++) (*str)[param->count++] = str_x8[i];
  } else if (param->accuracy > 0) {
    s21_alignment(&str, param);
    for (int i = 0; str_x8[i] != '\0'; i++) (*str)[param->count++] = str_x8[i];
  } else
    for (int i = 0; str_x8[i] != '\0'; i++) (*str)[param->count++] = str_x8[i];
  s21_free_str_case_o(&binary_str_revers, &binary_str, &str_x8, &str3);
}

char s21_x8(char **str) {
  char x8 = '0';
  if ((*str)[0] == '0' && (*str)[1] == '0' && (*str)[2] == '0')
    x8 = '0';
  else if ((*str)[0] == '0' && (*str)[1] == '0' && (*str)[2] == '1')
    x8 = '1';
  else if ((*str)[0] == '0' && (*str)[1] == '1' && (*str)[2] == '0')
    x8 = '2';
  else if ((*str)[0] == '0' && (*str)[1] == '1' && (*str)[2] == '1')
    x8 = '3';
  else if ((*str)[0] == '1' && (*str)[1] == '0' && (*str)[2] == '0')
    x8 = '4';
  else if ((*str)[0] == '1' && (*str)[1] == '0' && (*str)[2] == '1')
    x8 = '5';
  else if ((*str)[0] == '1' && (*str)[1] == '1' && (*str)[2] == '0')
    x8 = '6';
  else if ((*str)[0] == '1' && (*str)[1] == '1' && (*str)[2] == '1')
    x8 = '7';
  return x8;
}

void s21_case_p(char **str, char *str_d, param *param) {
  param->length = 0;
  char *hex_addr, *hex_addr_2;
  hex_addr = calloc(32 + 1, sizeof(char));
  hex_addr_2 = calloc(32 + 1, sizeof(char));
  uintptr_t address = (uintptr_t)str_d;
  int count = 2;
  if (str_d != s21_NULL) {
    for (int i = sizeof(void *) * 2 - 1; i >= 0; --i)
      hex_addr[i] = "0123456789abcdef"[((address >> (i * 4)) & 0xf)];
    hex_addr[sizeof(void *) * 2 + 1] = '\0';
    hex_addr_2[0] = '0';
    hex_addr_2[1] = 'x';
    while (param->accuracy - 12 > 0) {
      hex_addr_2[count++] = '0';
      param->accuracy--;
    }
    int first = 1;
    for (int i = sizeof(void *) * 2 - 1; i >= 0; --i) {
      if (first == 0)
        hex_addr_2[count++] = hex_addr[i];
      else if (hex_addr[i] != 'x' && hex_addr[i] != '0') {
        hex_addr_2[count++] = hex_addr[i];
        first = 0;
      }
    }
  } else {
    s21_case_p_hex(&hex_addr_2);
    count = 5;
  }
  hex_addr_2[count] = '\0';
  int strlen = s21_strlen(hex_addr_2);
  s21_width_accuracy(strlen, param);
  if (param->flag_plus == 1 || param->flag_space == 1) param->width--;
  if (param->flag_zero == 1 && param->flag_dot == 0) {
    if (param->flag_plus == 1)
      (*str)[param->count++] = '+';
    else if (param->flag_space == 1)
      (*str)[param->count++] = ' ';
    for (int i = 0; i < 2; i++) (*str)[param->count++] = hex_addr_2[i];
    if (param->width > 0 && param->flag_minus == 0) s21_alignment(&str, param);
    for (int i = 2; i < count; i++) (*str)[param->count++] = hex_addr_2[i];
  } else if (param->flag_dot == 1) {
    if (param->flag_plus == 1 && param->width <= 0)
      (*str)[param->count++] = '+';
    else if (param->flag_space == 1)
      (*str)[param->count++] = ' ';
    if (param->width > 0 && param->flag_minus == 0) s21_alignment(&str, param);
    if (param->flag_plus == 1 && param->width > 0) (*str)[param->count++] = '+';
    for (int i = 0; i < count; i++) (*str)[param->count++] = hex_addr_2[i];
  } else {
    if (param->width > 0 && param->flag_minus == 0) s21_alignment(&str, param);
    if (param->flag_plus == 1)
      (*str)[param->count++] = '+';
    else if (param->flag_space == 1)
      (*str)[param->count++] = ' ';
    for (int i = 0; i < count; i++) (*str)[param->count++] = hex_addr_2[i];
  }
  if (param->width > 0 && param->flag_minus == 1) s21_alignment(&str, param);
  free(hex_addr);
  free(hex_addr_2);
}

void s21_case_p_hex(char **hex_addr_2) {
  int count = 0;
  (*hex_addr_2)[count++] = '(';
  (*hex_addr_2)[count++] = 'n';
  (*hex_addr_2)[count++] = 'i';
  (*hex_addr_2)[count++] = 'l';
  (*hex_addr_2)[count++] = ')';
}

void s21_width_accuracy(int strlen, param *param) {
  if (param->width > 0 && param->accuracy >= 0) {
    if (param->width == strlen && param->accuracy == strlen) {
      param->width = 0;
      param->accuracy = 0;
    } else if (param->width > param->accuracy && param->accuracy > strlen) {
      param->width -= param->accuracy;
      param->accuracy -= strlen;
      if (param->va_int < 0 && param->flag_minus == 0) {
        param->width--;
      }
    } else if (param->width > param->accuracy) {
      param->width -= strlen;
      param->accuracy = 0;
      if (param->va_int < 0 && param->flag_minus == 0 && param->type != 'x' &&
          param->type != 'X')
        param->width--;
    } else if (param->width == param->accuracy) {
      param->accuracy -= strlen;
      param->width = 0;
    } else if (param->accuracy >= strlen) {
      param->accuracy -= strlen;
      param->width = 0;
    } else if (param->width < strlen) {
      param->accuracy = 0;
      param->width = 0;
    }
  } else if (param->width > 0) {
    if ((param->flag_hash == 1) && param->va_int != 0) param->width -= 2;
    if (param->va_int < 0 && param->flag_minus == 0) param->width--;
    param->width -= strlen;
  } else if (param->accuracy > 0) {
    param->accuracy = (param->va_int >= 0) ? param->accuracy - strlen
                                           : param->accuracy - strlen + 1;
    if (param->va_int < 0 && param->flag_minus == 0) param->accuracy--;
  }
}

void s21_width_accuracy_f_0(int strlen, param *param) {
  if (param->width > 0 && param->accuracy >= 0) {
    if (param->width == strlen && param->accuracy == strlen) {
      param->width = 0;
    } else if (param->width >= param->accuracy && param->width >= strlen) {
      if (param->accuracy == 0)
        param->width--;
      else if (param->width > strlen && param->accuracy <= strlen) {
        param->width -= (strlen + param->accuracy - 1);
      } else if (param->accuracy > strlen)
        param->width -= (param->accuracy + 2);
      else if (param->width == strlen)
        param->width -= strlen;
      else {
        param->width -= strlen;
        param->accuracy = 0;
      }
    } else if (param->width >= param->accuracy) {
      if (param->accuracy == 0)
        param->width--;
      else
        param->width = 0;
    } else if (param->accuracy >= strlen || param->width < strlen)
      param->width = 0;
  } else if (param->width > 0) {
    param->width -= strlen;
  }
}

void s21_make_str_case_x(char **str1, char **str2, char **str3, int max_count,
                         param *param) {
  *str1 = calloc(max_count + 1, sizeof(char));
  *str2 = calloc(max_count + 1, sizeof(char));
  *str3 = calloc(max_count + 1, sizeof(char));
  if (*str1 == s21_NULL || *str2 == s21_NULL || *str3 == s21_NULL)
    param->error = 1;
}

void s21_free_str_case_x(char **str1, char **str2, char **str3) {
  free(*str1);
  free(*str2);
  free(*str3);
}

void s21_free_str_case_o(char **str1, char **str2, char **str3, char **str4) {
  free(*str1);
  free(*str2);
  free(*str3);
  free(*str4);
}