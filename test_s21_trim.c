#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(basic) {
  char str[] = "++aboba++";
  char trim_ch[] = "+";
  char expected[] = "aboba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(no_string) {
  char str[] = "";
  char trim_ch[] = "+";
  char expected[] = "";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(no_trim) {
  char str[] = "234r54aboba156wef";
  char trim_ch[] = "";
  char expected[] = "234r54aboba156wef";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(nothing) {
  char str[] = "";
  char trim_ch[] = "";
  char expected[] = "";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(same) {
  char str[] = "aboba";
  char trim_ch[] = "aboba";
  char expected[] = "";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(hard_trim) {
  char str[] = "45!@fsdgp45!pfdf45!@";
  char trim_ch[] = "45!@";
  char expected[] = "fsdgp45!pfdf";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(other_trim) {
  char str[] = "aoaodosdosd";
  char trim_ch[] = "45!@";
  char expected[] = "aoaodosdosd";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(trim_cant_do_that) {
  char str[] = "aoa!-!odosdos!-!d";
  char trim_ch[] = "!-!";
  char expected[] = "aoa!-!odosdos!-!d";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

Suite *suite_trim(void) {
  Suite *s = suite_create("s21_to_trim");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, no_string);
  tcase_add_test(tc, no_trim);
  tcase_add_test(tc, nothing);
  tcase_add_test(tc, same);
  tcase_add_test(tc, hard_trim);
  tcase_add_test(tc, other_trim);
  tcase_add_test(tc, trim_cant_do_that);

  suite_add_tcase(s, tc);
  return s;
}