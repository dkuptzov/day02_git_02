#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(strncmp_basic) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_diff_in_first_n) {
  const char *str1 = "Hello";
  const char *str2 = "Hellp";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_equal_shorter_n) {
  const char *str1 = "Hello";
  const char *str2 = "Hello, World!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_equal_but_diff_lengths) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, World!!!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 13), strncmp(str1, str2, 13));
}
END_TEST

START_TEST(strncmp_n_is_zero) {
  const char *str1 = "Hello";
  const char *str2 = "Hello, World!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

START_TEST(strncmp_case_sensitive) {
  const char *str1 = "HeLlo";
  const char *str2 = "Hello";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_empty_strings) {
  const char *str1 = "";
  const char *str2 = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

Suite *suite_strncmp() {
  Suite *suite = suite_create("strncmp_suite");
  TCase *tcase_core = tcase_create("strncmp_tc");

  tcase_add_test(tcase_core, strncmp_basic);

  tcase_add_test(tcase_core, strncmp_diff_in_first_n);
  tcase_add_test(tcase_core, strncmp_equal_shorter_n);
  tcase_add_test(tcase_core, strncmp_equal_but_diff_lengths);
  tcase_add_test(tcase_core, strncmp_n_is_zero);
  tcase_add_test(tcase_core, strncmp_case_sensitive);
  tcase_add_test(tcase_core, strncmp_empty_strings);

  suite_add_tcase(suite, tcase_core);
  return suite;
}