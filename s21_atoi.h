#ifndef S21_ATOI_H
#define S21_ATOI_H

#include "s21_sprintf.h"

char *s21_atoi_new(param *param);
int s21_atoi_int(char *str, char *digit, long double x, param *param);
int s21_atoi_int_u(char *str, char *digit, unsigned long long x,
                   const param *param);
int s21_min_1(param *param);
int s21_min_2(int max, param *param);

#endif