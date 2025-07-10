#include "../s21_funcs/s21_string.h"
#include "s21_tests.h"

void compare_all_tokens(char *str1, char *str2, const char *delim) {
  char *token1 = s21_strtok(str1, delim);
  char *token2 = strtok(str2, delim);
  ck_assert_pstr_eq(token1, token2);

  while (token1 != NULL && token2 != NULL) {
    token1 = s21_strtok(NULL, delim);
    token2 = strtok(NULL, delim);
    ck_assert_pstr_eq(token1, token2);
  }
}

START_TEST(basic) {
  char str1[] = "word1,word2,word3";
  char str2[] = "word1,word2,word3";
  const char *delim = ",";

  compare_all_tokens(str1, str2, delim);
}
END_TEST

START_TEST(few_same_delimiters) {
  char str1[] = "one++two+++three";
  char str2[] = "one++two+++three";
  const char *delim = "+";

  compare_all_tokens(str1, str2, delim);
}
END_TEST

START_TEST(few_delimiters) {
  char str1[] = "one+_&two+++three+_&four";
  char str2[] = "one+_&two+++three+_&four";
  const char *delim = "+_&";

  compare_all_tokens(str1, str2, delim);
}
END_TEST

START_TEST(few_few_delimiters) {
  char str1[] = "*A_B+C=D";
  char str2[] = "*A_B+C=D";
  const char *delim = "+_*=";

  compare_all_tokens(str1, str2, delim);
}
END_TEST

START_TEST(no_delimiters) {
  char str1[] = "nothing";
  char str2[] = "nothing";
  const char *delim = ",";

  compare_all_tokens(str1, str2, delim);
}
END_TEST

/* переписала тесты, фейлиться перестал */
START_TEST(only_delimeters) {
  char str1[] = "!!!!!";
  char str2[] = "!!!!!";
  const char *delim = "!";

  compare_all_tokens(str1, str2, delim);
}
END_TEST

START_TEST(too_many_uses) {
  char str1[] = "men*sine*yaratam";
  char str2[] = "men*sine*yaratam";
  const char *delim = ",*? =";

  compare_all_tokens(str1, str2, delim);
}
END_TEST

/* че тут? */
START_TEST(null_after_end) {
  char str1[] = "a";
  char str2[] = "a";

  char *token1 = s21_strtok(str1, "a");
  char *token2 = strtok(str2, "a");
  ck_assert_pstr_eq(token1, token2);

  token1 = s21_strtok(NULL, "a");
  token2 = strtok(NULL, "a");
  ck_assert_ptr_null(token1);
  ck_assert_ptr_null(token2);
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, few_delimiters);
  tcase_add_test(tc, few_few_delimiters);
  tcase_add_test(tc, few_same_delimiters);
  tcase_add_test(tc, no_delimiters);
  tcase_add_test(tc, only_delimeters);
  tcase_add_test(tc, too_many_uses);
  tcase_add_test(tc, null_after_end);

  suite_add_tcase(s, tc);
  return s;
}