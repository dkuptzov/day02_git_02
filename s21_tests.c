#include "s21_tests.h"

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int number_failed;
  Suite *suite = suite_create("All Tests");
  SRunner *runner = srunner_create(suite);

  srunner_add_suite(runner, suite_memchr());
  srunner_add_suite(runner, suite_memcmp());
  srunner_add_suite(runner, suite_memcpy());
  srunner_add_suite(runner, suite_memset());
  srunner_add_suite(runner, suite_strchr());
  srunner_add_suite(runner, suite_strrchr());
  srunner_add_suite(runner, suite_strlen());
  srunner_add_suite(runner, suite_strstr());
  srunner_add_suite(runner, suite_strpbrk());
  srunner_add_suite(runner, suite_strtok());
  srunner_add_suite(runner, suite_strerror());
  srunner_add_suite(runner, suite_to_upper());
  srunner_add_suite(runner, suite_to_lower());
  srunner_add_suite(runner, suite_trim());
  srunner_add_suite(runner, make_suite());
  srunner_add_suite(runner, suite_insert());
  srunner_add_suite(runner, suite_strncmp());
  srunner_add_suite(runner, suite_strncpy());
  srunner_add_suite(runner, suite_strncat());
  srunner_add_suite(runner, suite_strcspn());
  srunner_add_suite(runner, suite_strcpy());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}