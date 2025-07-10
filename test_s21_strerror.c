#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(strerror_known) {
  for (int i = 0; i < 100; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(strerror_unknown_positive) {
  ck_assert_str_eq(s21_strerror(666), strerror(666));
}
END_TEST

START_TEST(strerror_negative) {
  ck_assert_str_eq(s21_strerror(-1), strerror(-1));
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, strerror_known);
  tcase_add_test(tc, strerror_unknown_positive);
  tcase_add_test(tc, strerror_negative);

  suite_add_tcase(s, tc);
  return s;
}