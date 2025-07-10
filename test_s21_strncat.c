#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(strncat_empty_src) {  // пустой src
  char dest[1024] = "Hello";
  const char src[1024] = "";

  ck_assert_str_eq(s21_strncat(dest, src, 5), strncat(dest, src, 5));
}
END_TEST

START_TEST(strncat_empty_dest) {  // пустой dest
  char dest[1024] = "";
  const char src[1024] = "World";

  ck_assert_str_eq(s21_strncat(dest, src, 5), strncat(dest, src, 5));
}
END_TEST

START_TEST(strncat_n_greater_than_src) {  // n больше чем src
  char dest[1024] = "Hello";
  const char src[1024] = "World";

  ck_assert_str_eq(s21_strncat(dest, src, 10), strncat(dest, src, 10));
}
END_TEST

START_TEST(strncat_without_src) {  // пустой src
  char dest[1024] = "Hello";

  ck_assert_str_eq(s21_strncat(dest, "\0", 5), strncat(dest, "\0", 5));
}
END_TEST

START_TEST(strncat_n_zero) {  // с нолевой n
  char dest[1024] = "Hello";
  const char src[1024] = "World";

  ck_assert_str_eq(s21_strncat(dest, src, 0), strncat(dest, src, 0));
}
END_TEST

Suite *suite_strncat() {
  Suite *suite = suite_create("strncat_suite");
  TCase *tcase_core = tcase_create("strncat_tc");

  tcase_add_test(tcase_core, strncat_empty_src);
  tcase_add_test(tcase_core, strncat_empty_dest);
  tcase_add_test(tcase_core, strncat_n_greater_than_src);
  tcase_add_test(tcase_core, strncat_without_src);
  tcase_add_test(tcase_core, strncat_n_zero);

  suite_add_tcase(suite, tcase_core);
  return suite;
}