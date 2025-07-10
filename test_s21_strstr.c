#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

START_TEST(empty_both) {
  const char *haystack = "";
  const char *needle = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_haystack) {
  const char *haystack = "";
  const char *needle = "dskdjbfdshdhdffsdoif";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_needle) {
  const char *haystack = "jksjdnfnsdjfsijf";
  const char *needle = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(found) {
  const char *haystack = "Hello world!";
  const char *needle = "world";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(not_found) {
  const char *haystack = "pupupu";
  const char *needle = "aboba";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(case_sensitive) {
  const char *haystack = "Aboba pupupu";
  const char *needle = "aboBA";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(repeated_words) {
  const char *haystack = "pu pu pu";
  const char *needle = "pu";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(one_needle) {
  const char *haystack = "eeww awww";
  const char *needle = " ";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(one_haystack) {
  const char *haystack = " ";
  const char *needle = "llghdf4345 iue8f8g49u";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(in_the_end) {
  const char *haystack = "mon tue wed thu fri sat sun";
  const char *needle = "sun";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, empty_both);
  tcase_add_test(tc, empty_haystack);
  tcase_add_test(tc, empty_needle);
  tcase_add_test(tc, found);
  tcase_add_test(tc, not_found);
  tcase_add_test(tc, case_sensitive);
  tcase_add_test(tc, repeated_words);
  tcase_add_test(tc, one_needle);
  tcase_add_test(tc, one_haystack);
  tcase_add_test(tc, in_the_end);

  suite_add_tcase(s, tc);
  return s;
}
