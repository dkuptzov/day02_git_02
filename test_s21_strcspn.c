#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(strcspn_simple) {
  const char *s = "Hello to my group";
  const char *search = "xyz";
  ck_assert_int_eq(s21_strcspn(s, search), strcspn(s, search));
}
END_TEST

START_TEST(strcspn_start) {  // со тарта
  const char *s = "Hello to my group";
  const char *search = "H";
  ck_assert_int_eq(s21_strcspn(s, search), strcspn(s, search));
}
END_TEST

START_TEST(strcspn_not_found_1) {  // не найден
  const char *s = "Hello to my group";
  const char *search = "z";
  ck_assert_int_eq(s21_strcspn(s, search), strcspn(s, search));
}
END_TEST

START_TEST(strcspn_not_found_2) {  // не найден
  const char *s = "Hello to my group";
  const char *search = "xyz";
  ck_assert_int_eq(s21_strcspn(s, search), strcspn(s, search));
}
END_TEST

START_TEST(strcspn_all) {  // полное совпадение, но покажет первую
  const char *s = "ptr";
  const char *search = "ptr";
  ck_assert_int_eq(s21_strcspn(s, search), strcspn(s, search));
}
END_TEST

START_TEST(strcspn_empty_string) {  // поиск с пустой строкой
  const char *s = "";
  const char *search = "abc";
  ck_assert_int_eq(s21_strcspn(s, search), strcspn(s, search));
}
END_TEST

START_TEST(strcspn_single_reject) {  // найдет в первом слове
  const char *s = "Hello to my group";
  const char *search = "o";
  ck_assert_int_eq(s21_strcspn(s, search), strcspn(s, search));
}
END_TEST

START_TEST(strcspn_multiple_reject) {  // найдет в первом слове и выйдет
  const char *s = "Hello to my group";
  const char *search = "o l";
  ck_assert_int_eq(s21_strcspn(s, search), strcspn(s, search));
}
END_TEST

Suite *suite_strcspn() {
  Suite *suite = suite_create("strcspn_suite");
  TCase *tcase_core = tcase_create("strcspn_tc");

  tcase_add_test(tcase_core, strcspn_simple);
  tcase_add_test(tcase_core, strcspn_start);
  tcase_add_test(tcase_core, strcspn_not_found_1);
  tcase_add_test(tcase_core, strcspn_not_found_2);
  tcase_add_test(tcase_core, strcspn_all);
  tcase_add_test(tcase_core, strcspn_empty_string);
  tcase_add_test(tcase_core, strcspn_single_reject);
  tcase_add_test(tcase_core, strcspn_multiple_reject);

  suite_add_tcase(suite, tcase_core);
  return suite;
}