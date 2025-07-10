#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(strcpy_basic) {
  char dest[1024] = {};
  const char *src = "Hello";
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
}
END_TEST

START_TEST(strcpy_shorter_src) {
  char dest[1024] = {};
  const char *src = "Hi";
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
}
END_TEST

START_TEST(strcpy_longer_dest) {
  char dest[1024] = {};
  const char *src = "Hello, World!";
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
}
END_TEST

START_TEST(strcpy_empty_src) {
  char dest[1024] = {};
  const char *src = "";
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
}
END_TEST

START_TEST(strcpy_null_char_in_src) {
  char dest[1024] = {};
  const char *src = "Hello\0World";
  ck_assert_str_eq(s21_strncpy(dest, src, 10), strncpy(dest, src, 10));
}
END_TEST

START_TEST(strcpy_zero_length_src) {
  char dest[1024] = {};
  ck_assert_str_eq(s21_strncpy(dest, "", 5), strncpy(dest, "", 5));
}
END_TEST

START_TEST(strcpy_zero_fill) {
  char dest[10] = {'\0'};
  const char *src = "Hello, World!";
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
}
END_TEST

START_TEST(strcpy_same_dest_src) {
  char src[1024] = "Hello";
  char *dest = src;
  const char src1[] = "Hello";
  char *dest1 = src;
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest1, src1, 5));
}
END_TEST

Suite *suite_strcpy() {
  Suite *suite = suite_create("strcpy_suite");
  TCase *tcase_core = tcase_create("strcpy_tc");

  tcase_add_test(tcase_core, strcpy_basic);
  tcase_add_test(tcase_core, strcpy_shorter_src);
  tcase_add_test(tcase_core, strcpy_longer_dest);
  tcase_add_test(tcase_core, strcpy_empty_src);
  tcase_add_test(tcase_core, strcpy_null_char_in_src);
  tcase_add_test(tcase_core, strcpy_zero_length_src);
  tcase_add_test(tcase_core, strcpy_zero_fill);
  tcase_add_test(tcase_core, strcpy_same_dest_src);

  suite_add_tcase(suite, tcase_core);
  return suite;
}