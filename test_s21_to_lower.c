#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(up_char) {
  char str[] = "A";
  char expected[] = "a";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(lower_str) {
  char str[] = "qwerty";
  char expected[] = "qwerty";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(caps_lower) {
  char str[] = "CAPS LOCK";
  char expected[] = "caps lock";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(mixed_case) {
  char str[] = "Hi TherE";
  char expected[] = "hi there";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(mixed_char) {
  char str[] = "R@nd0M_TEx^t";
  char expected[] = "r@nd0m_tex^t";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(non_letter_char) {
  char str[] = "+";
  char expected[] = "+";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(null) {
  char *str = NULL;
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_null(result);
}
END_TEST

Suite *suite_to_lower(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, up_char);
  tcase_add_test(tc, lower_str);
  tcase_add_test(tc, caps_lower);
  tcase_add_test(tc, mixed_case);
  tcase_add_test(tc, mixed_char);
  tcase_add_test(tc, non_letter_char);
  tcase_add_test(tc, null);

  suite_add_tcase(s, tc);
  return s;
}