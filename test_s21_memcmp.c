#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(basic) {
  char str1[] = "compare";
  char str2[] = "compare";
  int n = 5;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(null_n) {
  char str1[] = "compare";
  char str2[] = "compare";
  int n = 0;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(null_string) {
  char *str1 = "";
  char *str2 = "";
  int n = 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

END_TEST

START_TEST(test_case) {
  char str1[] = "qwerty";
  char str2[] = "QWERTy";
  int n = 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_numbers) {
  char str1[] = "753";
  char str2[] = "755";
  int n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_symbols) {
  char str1[] = "!!!@";
  char str2[] = "!!!@";
  int n = 4;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(equal_long) {
  char str1[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  char str2[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  int n = strlen(str1);

  ck_assert_int_eq(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(not_equal_long) {
  char str1[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  char str2[] = "gllk;;gfhtfl;fg;gf;df";
  int n = strlen(str1);

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, null_n);
  tcase_add_test(tc, null_string);
  tcase_add_test(tc, test_case);
  tcase_add_test(tc, test_numbers);
  tcase_add_test(tc, test_symbols);
  tcase_add_test(tc, equal_long);
  tcase_add_test(tc, not_equal_long);

  suite_add_tcase(s, tc);
  return s;
}