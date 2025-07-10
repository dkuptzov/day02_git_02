#include "s21_atoi.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char *s21_atoi_new(param *param) {
  int max = 6, max2, count = 0;
  char *digit, *str;
  digit = calloc(64 + 1, sizeof(char));
  str = calloc(64 + 1, sizeof(char));
  int x;
  if (param->length == 'h' || param->type == 'd' || param->type == 'u') {
    if (param->type == 'u')
      x = s21_atoi_int_u(str, digit, (unsigned long long)param->va_int, param);
    else
      x = s21_atoi_int(str, digit, param->va_int, param);
    str[x] = '\0';
  } else if (param->type == 'f' || param->type == 'g' || param->type == 'G' ||
             param->type == 'e' || param->type == 'E') {
    if (param->flag_dot == 1)
      max = s21_min_1(param);
    else if (param->g != 0)
      max -= param->g;
    if (max == 1 && param->va_f < 1 &&
        (param->type == 'g' || param->type == 'G'))
      max = s21_min_2(max, param);
    x = s21_atoi_int(str, digit, param->va_f, param);
    long double y = (param->va_f < 0) ? param->va_f * -1.0 : param->va_f;
    if (param->flag_dot == 1 && param->accuracy > 0)
      max2 = param->accuracy;
    else
      max2 = max;
    int z1 = 0, z2 = 0, z3 = 0;
    while (count < max) {
      int test = 0;
      y -= (long long int)y;
      while (test++ < max2 - count) {
        long long int last_y = (long long int)y % 10;
        if (z2 != 0 && z2 == test && param->type != 'f') y = round(y);
        y *= 10;
        if ((long long int)y % 10 == 9 && last_y == 0) z1 = test;
        if ((long long int)y % 10 != 9) z1 = 0;
        if (test == max2 - count - 1 && z3 == 0) {
          z2 = z1;
          z3 = 1;
        }
      }
      if (((param->type == 'e' || param->type == 'E') &&
           (param->flag_dot != 1 || count == max - 1)) ||
          (param->type == 'f' || param->type == 'g' || param->type == 'G'))
        y = round(y);
      y /= pow(10, max2 - count - 1);
      if (param->length != 'L')
        str[x++] = '0' + ((int)(y + 0.000001) % 10);
      else
        str[x++] = '0' + ((int)y % 10);
      y -= (long long int)y;
      count++;
    }
    if (str[--x] == '.')
      str[x] = '\0';
    else
      str[++x] = '\0';
  }
  free(digit);
  return str;
}

int s21_atoi_int(char *str, char *digit, long double x, param *param) {
  int lg = log10l(x);
  int count = 0, count_reverse = 0, max_lg = lg / 2;
  long double temp = 0.0;
  char digit_reverse[100] = {0};
  while (x > 9000000000000000000.0) {
    while (lg - max_lg > 0) {
      long double x_temp = x;
      x_temp /= pow(10, lg);
      digit_reverse[count_reverse++] = '0' + (((long long int)x_temp) % 10);
      temp = (long long int)x_temp;
      lg--;
    }
    x -= (temp * pow(10, lg + 1));
    lg = log10l(x);
    max_lg = lg / 2;
    param->va_f = x;
  }
  digit_reverse[count_reverse] = '\0';
  long long int x_first = x;
  long long int z;
  if (param->accuracy <= 0 && param->flag_dot == 1) x = round(x);
  if (x < 0) x *= -1.0;
  if (param->accuracy >= 1 && param->type == 'f') {
    x *= pow(10, param->accuracy + 1);
    x += 0.000001;
    x /= 10;
    z = (long long int)x;
    z /= pow(10, param->accuracy);
  } else if (param->type == 'g' && param->va_f > 100000)
    z = round(x);
  else if (x > 0)
    z = (long long int)(x + 0.000001);
  else if (param->accuracy == 0)
    z = round(x);
  else
    z = (long long int)(x - 0.000001);
  if (z < 0) z *= -1;
  while (z > 0) {
    digit[count++] = '0' + (z % 10);
    z /= 10;
  }
  for (int i = count_reverse - 1; i >= 0; i--) {
    digit[count++] = digit_reverse[i];
  }
  digit[count] = '\0';
  for (int i = count - 1; i >= 0; i--) str[z++] = digit[i];
  if (x_first == 0) str[z++] = '0';
  if (param->type == 'f' || param->type == 'g' || param->type == 'G' ||
      param->type == 'e' || param->type == 'E')
    str[z++] = '.';
  return z;
}

int s21_atoi_int_u(char *str, char *digit, unsigned long long x,
                   const param *param) {
  int count = 0;
  unsigned long long z = x;
  if (param->accuracy <= 0 && param->length == 'L' && param->flag_dot == 1)
    z = round(z);
  while (z > 0) {
    digit[count++] = '0' + (z % 10);
    z /= 10;
  }
  digit[count] = '\0';
  for (int i = count - 1; i >= 0; i--) {
    str[z++] = digit[i];
  }
  if (z == 0) str[z++] = '0';
  return z;
}

int s21_min_1(param *param) {
  int max = 0;
  if (param->accuracy <= 0 && param->width <= 0 &&
      (param->type == 'g' || param->type == 'G'))
    max = 1;
  else if (param->type == 'f' && param->va_f == 0.0 && param->flag_space == 0 &&
           param->length == 'x')
    max = 1;
  else if (param->accuracy >= 0)
    max = param->accuracy;
  else
    max = param->width;
  return max;
}

int s21_min_2(int max, param *param) {
  long double z = param->va_f;
  z *= 10;
  while (z < 1) {
    z *= 10;
    max++;
  }
  return max;
}