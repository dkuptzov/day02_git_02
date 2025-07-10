#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(low_char) {
  char str[] = "a";
  char expected[] = "A";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(upper_str) {
  char str[] = "QWERTY";
  char expected[] = "QWERTY";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(lower) {
  char str[] = "caps lock";
  char expected[] = "CAPS LOCK";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(mixed_case) {
  char str[] = "Hi TherE";
  char expected[] = "HI THERE";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(mixed_char) {
  char str[] = "R@nd0m_Tex^t";
  char expected[] = "R@ND0M_TEX^T";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(non_letter_char) {
  char str[] = "+";
  char expected[] = "+";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(null) {
  char *str = NULL;
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_null(result);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, low_char);
  tcase_add_test(tc, upper_str);
  tcase_add_test(tc, lower);
  tcase_add_test(tc, mixed_case);
  tcase_add_test(tc, mixed_char);
  tcase_add_test(tc, non_letter_char);
  tcase_add_test(tc, null);

  suite_add_tcase(s, tc);
  return s;
}