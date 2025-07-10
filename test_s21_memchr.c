#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(basic) {
  char str[] = "some text pupupu";
  char target = 'e';
  ck_assert_ptr_eq(s21_memchr(str, target, strlen(str)),
                   memchr(str, target, strlen(str)));
}
END_TEST

START_TEST(empty) {
  char str[] = "";
  char target = 'x';
  ck_assert_ptr_eq(s21_memchr(str, target, strlen(str)),
                   memchr(str, target, strlen(str)));
}
END_TEST

START_TEST(special_chars) {
  char str[] = "@#$^&*()";
  char target = '(';
  ck_assert_ptr_eq(s21_memchr(str, target, strlen(str)),
                   memchr(str, target, strlen(str)));
}
END_TEST

START_TEST(null_byte) {
  char str[] = "OKAK\0NULL";
  char target = '\0';
  ck_assert_ptr_eq(s21_memchr(str, target, strlen(str)),
                   memchr(str, target, strlen(str)));
}
END_TEST

START_TEST(numbers) {
  char str[] = "3.1415926535";
  char target = '6';
  ck_assert_ptr_eq(s21_memchr(str, target, strlen(str)),
                   memchr(str, target, strlen(str)));
}
END_TEST

START_TEST(numbers_chars) {
  char str[] = "Aboba123boba456";
  char target = '1';
  ck_assert_ptr_eq(s21_memchr(str, target, strlen(str)),
                   memchr(str, target, strlen(str)));
}
END_TEST

START_TEST(numbers_array) {
  int array[] = {78, 4, 77, 91, 99, 78};
  s21_size_t arr_sz = sizeof(int) * 6;
  char target = 91;

  ck_assert_ptr_eq(s21_memchr(array, target, arr_sz),
                   memchr(array, target, arr_sz));
}
END_TEST

START_TEST(not_found) {
  char str[] = "ABCDEFG";
  char target = 'O';
  ck_assert_ptr_eq(s21_memchr(str, target, strlen(str)),
                   memchr(str, target, strlen(str)));
}
END_TEST

Suite *suite_memchr() {
  Suite *s = suite_create("s21_memchr");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, basic);
  tcase_add_test(tc_core, empty);
  tcase_add_test(tc_core, special_chars);
  tcase_add_test(tc_core, null_byte);
  tcase_add_test(tc_core, numbers);
  tcase_add_test(tc_core, numbers_chars);
  tcase_add_test(tc_core, numbers_array);
  tcase_add_test(tc_core, not_found);

  suite_add_tcase(s, tc_core);
  return s;
}