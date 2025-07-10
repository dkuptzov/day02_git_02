#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>

Suite *suite_insert();
Suite *suite_memchr(void);
Suite *suite_memcmp(void);
Suite *suite_memcpy(void);
Suite *suite_memset();

Suite *suite_strchr(void);
Suite *suite_strcpy();

Suite *suite_strlen(void);
Suite *suite_strncmp();
Suite *suite_strncpy();
Suite *suite_strstr(void);
Suite *suite_strpbrk(void);
Suite *suite_strrchr();

Suite *suite_strtok(void);
Suite *suite_strerror(void);
Suite *suite_to_upper(void);
Suite *suite_to_lower(void);
Suite *suite_trim(void);

Suite *suite_strcspn();
Suite *suite_strncat();
Suite *make_suite(void);

#endif