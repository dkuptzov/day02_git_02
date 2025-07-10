#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(strchr_simple) {
  const char *str = "Hello to my group!";
  char c = 'o';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_not_found) {  // не нашел
  const char *str = "Hello to my group!";
  char c = 'z';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_empty_str) {  // пустой str
  const char *str = "";
  char c = 'o';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_first_char) {
  const char *str = "Hello to my group!";
  char c = 'H';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_last_char) {
  const char *str = "Hello to my group!";
  char c = '!';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_single_char) {
  const char *str = "a";
  char c = 'a';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_spaces) {
  const char *str = "   ";
  char c = 'a';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_second) {
  const char *str = "Hello";
  char c = 'e';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *suite_strchr() {
  Suite *suite = suite_create("strchr_suite");
  TCase *tcase_core = tcase_create("strchr_tc");

  tcase_add_test(tcase_core, strchr_simple);
  tcase_add_test(tcase_core, strchr_not_found);
  tcase_add_test(tcase_core, strchr_empty_str);
  tcase_add_test(tcase_core, strchr_first_char);
  tcase_add_test(tcase_core, strchr_last_char);
  tcase_add_test(tcase_core, strchr_single_char);
  tcase_add_test(tcase_core, strchr_spaces);
  tcase_add_test(tcase_core, strchr_second);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
