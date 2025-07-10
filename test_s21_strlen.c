#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(basic) {
  char str[] = "QWERTY, ASDFGH!";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(empty) {
  char str[] = "";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(special_chars) {
  char str[] = "±!@#$^&*()_+";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(null_null_null) {
  char str[] = "OKAK\0KAK\0KAK\0KAK\0";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(numbers) {
  char str[] = "0123456789";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(long_string) {
  char str[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(spaces) {
  char str[] = "     ";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(mixed) {
  char str[] = "Ffaw34k@#842-fv";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

END_TEST

START_TEST(random_test) {
  char str[] = "random test random text vo kak";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *suite_strlen() {
  Suite *s = suite_create("s21_strlen");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, basic);
  tcase_add_test(tc_core, empty);
  tcase_add_test(tc_core, special_chars);
  tcase_add_test(tc_core, null_null_null);
  tcase_add_test(tc_core, numbers);
  tcase_add_test(tc_core, long_string);
  tcase_add_test(tc_core, spaces);
  tcase_add_test(tc_core, mixed);
  tcase_add_test(tc_core, random_test);

  suite_add_tcase(s, tc_core);
  return s;
}