#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(strncpy_basic) {
  char dest[1024] = {};
  const char src[100] = "Hello";
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
}
END_TEST

START_TEST(strncpy_shorter_src) {
  char dest[1024] = {};
  const char src[100] = "Hi";
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
}
END_TEST

START_TEST(strncpy_longer_dest) {
  char dest[1024] = {};
  const char src[100] = "Hello, World!";
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
}
END_TEST

START_TEST(strncpy_empty_src) {
  char dest[1024] = {};
  const char src[100] = "";
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
}
END_TEST

START_TEST(strncpy_null_char_in_src) {
  char dest[1024] = {};
  const char src[1024] = "Hello\0World";
  ck_assert_str_eq(s21_strncpy(dest, src, 10), strncpy(dest, src, 10));
}
END_TEST

START_TEST(strncpy_zero_length_src) {
  char dest[1024] = {};
  ck_assert_str_eq(s21_strncpy(dest, "", 5), strncpy(dest, "", 5));
}
END_TEST

START_TEST(strncpy_zero_fill) {
  char dest[10] = {'\0'};
  const char src[100] = "Hello, World!";
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
}
END_TEST

START_TEST(strncpy_same_dest_src) {
  char src[1024] = "Hello";
  char *dest = src;
  const char src1[] = "Hello";
  char *dest1 = src;
  ck_assert_str_eq(s21_strncpy(dest, src, 5), strncpy(dest1, src1, 5));
}
END_TEST

Suite *suite_strncpy() {
  Suite *suite = suite_create("strncpy_suite");
  TCase *tcase_core = tcase_create("strncpy_tc");

  tcase_add_test(tcase_core, strncpy_basic);
  tcase_add_test(tcase_core, strncpy_shorter_src);
  tcase_add_test(tcase_core, strncpy_longer_dest);
  tcase_add_test(tcase_core, strncpy_empty_src);
  tcase_add_test(tcase_core, strncpy_null_char_in_src);
  tcase_add_test(tcase_core, strncpy_zero_length_src);
  tcase_add_test(tcase_core, strncpy_zero_fill);
  tcase_add_test(tcase_core, strncpy_same_dest_src);

  suite_add_tcase(suite, tcase_core);
  return suite;
}