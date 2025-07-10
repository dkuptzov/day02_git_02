#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(memcpy_1) {
  const char src[1024] = "Decrease the line";
  char dest[1024] = {'\0'};
  ck_assert_ptr_eq(s21_memcpy(dest, src, 6), memcpy(dest, src, 6));
  dest[6] = '\0';
  ck_assert_str_eq(dest, "Decrea");
}
END_TEST

START_TEST(memcpy_2) {
  char src[1024] = "Decrease the";
  char dest[1024];
  ck_assert_ptr_eq(s21_memcpy(dest, src, sizeof(src)),
                   memcpy(dest, src, sizeof(src)));
  ck_assert_str_eq(dest, "Decrease the");
}
END_TEST

Suite *suite_memcpy() {
  Suite *suite = suite_create("test_memcpy");
  TCase *tcase_core = tcase_create("memcpy_tc");

  tcase_add_test(tcase_core, memcpy_1);
  tcase_add_test(tcase_core, memcpy_2);

  suite_add_tcase(suite, tcase_core);
  return suite;
}