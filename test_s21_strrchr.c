#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(strrchr_simple) {
  const char *s = "hello group";
  int c = 'o';
  ck_assert_ptr_eq(s21_strrchr(s, c), strrchr(s, c));
}
END_TEST

START_TEST(strrchr_last_char) {  // последний
  const char *s = "hello group";
  int c = 'p';
  ck_assert_ptr_eq(s21_strrchr(s, c), strrchr(s, c));
}
END_TEST

START_TEST(strrchr_first_char) {  // первый
  const char *s = "hello group";
  int c = 'h';
  ck_assert_ptr_eq(s21_strrchr(s, c), strrchr(s, c));
}
END_TEST

START_TEST(strrchr_without_symbol) {  // без символа
  const char *s = "hello group";
  int c = 'z';
  ck_assert_ptr_eq(s21_strrchr(s, c), strrchr(s, c));
}
END_TEST

START_TEST(strrchr_empty_string) {  // пустая строка
  const char *s = "";
  int c = 'u';
  ck_assert_ptr_eq(s21_strrchr(s, c), strrchr(s, c));
}
END_TEST

START_TEST(strrchr_repeating) {  // повторяющийся
  const char *s = "ddddd";
  int c = 'd';
  ck_assert_ptr_eq(s21_strrchr(s, c), strrchr(s, c));
}
END_TEST

START_TEST(strrchr_many_occurrences) {  // много вхождений
  const char *s = "group group group";
  int c = 'p';
  ck_assert_ptr_eq(s21_strrchr(s, c), strrchr(s, c));
}
END_TEST

Suite *suite_strrchr() {
  Suite *suite = suite_create("strrchr_suite");
  TCase *tcase_core = tcase_create("strrchr_tc");

  tcase_add_test(tcase_core, strrchr_simple);
  tcase_add_test(tcase_core, strrchr_last_char);
  tcase_add_test(tcase_core, strrchr_first_char);
  tcase_add_test(tcase_core, strrchr_without_symbol);
  tcase_add_test(tcase_core, strrchr_empty_string);
  tcase_add_test(tcase_core, strrchr_repeating);
  tcase_add_test(tcase_core, strrchr_many_occurrences);

  suite_add_tcase(suite, tcase_core);
  return suite;
}