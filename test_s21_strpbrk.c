#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(found) {
  const char *str = "i believe i can fly";
  const char *keys = "e";
  ck_assert_pstr_eq(s21_strpbrk(str, keys), strpbrk(str, keys));
}
END_TEST

START_TEST(not_found) {
  const char *str = "qwerty";
  const char *keys = "asdfgh";
  ck_assert_pstr_eq(s21_strpbrk(str, keys), strpbrk(str, keys));
}
END_TEST

START_TEST(empty_str) {
  const char *str = "";
  const char *keys = "qq";
  ck_assert_pstr_eq(s21_strpbrk(str, keys), strpbrk(str, keys));
}
END_TEST

START_TEST(empty_keys) {
  const char *str = "some test text";
  const char *keys = "";
  ck_assert_pstr_eq(s21_strpbrk(str, keys), strpbrk(str, keys));
}
END_TEST

START_TEST(both_empty) {
  const char *str = "";
  const char *keys = "";
  ck_assert_pstr_eq(s21_strpbrk(str, keys), strpbrk(str, keys));
}
END_TEST

START_TEST(first_char) {
  const char *str = "first char";
  const char *keys = "f";
  ck_assert_pstr_eq(s21_strpbrk(str, keys), strpbrk(str, keys));
}
END_TEST

START_TEST(zero) {
  const char *str = "endddddd";
  const char *keys = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str, keys), strpbrk(str, keys));
}
END_TEST

START_TEST(case_sensitive) {
  const char *str = "enddDddd";
  const char *keys = "D";
  ck_assert_pstr_eq(s21_strpbrk(str, keys), strpbrk(str, keys));
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, found);
  tcase_add_test(tc, not_found);
  tcase_add_test(tc, empty_str);
  tcase_add_test(tc, empty_keys);
  tcase_add_test(tc, both_empty);
  tcase_add_test(tc, first_char);
  tcase_add_test(tc, zero);
  tcase_add_test(tc, case_sensitive);

  suite_add_tcase(s, tc);
  return s;
}