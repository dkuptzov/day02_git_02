#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(memset_simple) {
  char str[30] = "Hello to my group!";
  char с = 'o';
  ck_assert_ptr_eq(s21_memset(str, с, sizeof(str)),
                   memset(str, с, sizeof(str)));
}
END_TEST

START_TEST(memset_filled_with_zero) {  // Заполнил нулями
  char str[30] = "Hello to my group!";
  char с = '0';
  ck_assert_ptr_eq(s21_memset(str, с, sizeof(str)),
                   memset(str, с, sizeof(str)));
}
END_TEST

START_TEST(memset_not_completely_filled) {  // не полное заполнение
  char str[30] = "Hello to my group!";
  char с = 'e';
  ck_assert_ptr_eq(s21_memset(str + 3, с, 3), memset(str + 3, с, 3));
}
END_TEST

START_TEST(memset_full_fill) {  // полное заполнение
  char str[30] = "Hello to my group!";
  char с = 'l';
  ck_assert_ptr_eq(s21_memset(str, с, sizeof(str)),
                   memset(str, с, sizeof(str)));
}
END_TEST

START_TEST(memset_negative_value) {  // с отрицательным числом
  unsigned char str[10] = {0};
  unsigned char с = (unsigned char)(-1);

  s21_memset(str, с, sizeof(str));
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(str[i], 0xFF);
  }
}
END_TEST

Suite *suite_memset() {
  Suite *suite = suite_create("memset_suite");
  TCase *tcase_core = tcase_create("memset_tc");

  tcase_add_test(tcase_core, memset_simple);
  tcase_add_test(tcase_core, memset_filled_with_zero);
  tcase_add_test(tcase_core, memset_not_completely_filled);
  tcase_add_test(tcase_core, memset_full_fill);
  tcase_add_test(tcase_core, memset_negative_value);

  suite_add_tcase(suite, tcase_core);
  return suite;
}