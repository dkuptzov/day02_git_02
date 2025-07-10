#ifndef S21_CASE_H
#define S21_CASE_H

#include "s21_atoi.h"
#include "s21_binary.h"
#include "s21_sprintf.h"

void s21_case_c(char **str, param *param);
void s21_case_g(char **str, param *param);
int s21_case_g_1(param *param, int less_zero, int x);
void s21_case_g_2(param *param);
void s21_case_u(char **str, param *param);
void s21_case_u_width_acc(char **str, param *param, int len, char c);
void s21_case_f(char **str, param *param);
void s21_case_x_plus(char **str, param *param);
void s21_case_x_minus(char **str, param *param);
void s21_case_x_for(int *count, int *plus, char **binary_str);
void s21_make_str_case_x(char **str1, char **str2, char **str3, int max_count,
                         param *param);
void s21_free_str_case_x(char **str1, char **str2, char **str3);
char s21_x_plus_minus_switch(long long int x, const param *param);
void s21_case_p_hex(char **hex_addr_2);
void s21_case_s(char **str, const char *str_d, param *param);
void s21_case_o_plus(char **str, param *param);
void s21_case_o_minus(char **str, param *param);
void s21_free_str_case_o(char **str1, char **str2, char **str3, char **str4);
void s21_case_p(char **str, char *str_d, param *param);
char s21_x8(char **str);
void s21_width_accuracy(int strlen, param *param);
void s21_width_accuracy_f_0(int strlen, param *param);

#endif