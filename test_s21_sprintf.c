#include <check.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_sprintf.h"

START_TEST(test_1) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "NUMBER 01: %c TEST", 'D'),
                   sprintf(str2, "NUMBER 01: %c TEST", 'D'));
  ck_assert_str_eq(str1, str2);
  printf("Test001 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_2) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 02: %s TEST", "KARAMBA"),
                   sprintf(str2, "NUMBER 02: %s TEST", "KARAMBA"));
  ck_assert_str_eq(str, str2);
  printf("Test002 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_3) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 03: %d TEST", 123456789),
                   sprintf(str2, "NUMBER 03: %d TEST", 123456789));
  ck_assert_str_eq(str, str2);
  printf("Test003 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_4) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 04: %f TEST", 85.95654),
                   sprintf(str2, "NUMBER 04: %f TEST", 85.95654));
  ck_assert_str_eq(str, str2);
  printf("Test004 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_5) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 05: %20d TEST", 63546546),
                   sprintf(str2, "NUMBER 05: %20d TEST", 63546546));
  ck_assert_str_eq(str, str2);
  printf("Test005 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_6) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 06: %+20d TEST", 644),
                   sprintf(str2, "NUMBER 06: %+20d TEST", 644));
  ck_assert_str_eq(str, str2);
  printf("Test006 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_7) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 07: %-20d TEST", -5000),
                   sprintf(str2, "NUMBER 07: %-20d TEST", -5000));
  ck_assert_str_eq(str, str2);
  printf("Test007 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_8) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 08: %.20d TEST", 473436),
                   sprintf(str2, "NUMBER 08: %.20d TEST", 473436));
  ck_assert_str_eq(str, str2);
  printf("Test008 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_9) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 09: % d TEST", 12345),
                   sprintf(str2, "NUMBER 09: % d TEST", 12345));
  ck_assert_str_eq(str, str2);
  printf("Test009 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_10) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 10: %09d TEST", 12345),
                   sprintf(str2, "NUMBER 10: %09d TEST", 12345));
  ck_assert_str_eq(str, str2);
  printf("Test010 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_11) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 11: %hd TEST", 12345),
                   sprintf(str2, "NUMBER 11: %hd TEST", 12345));
  ck_assert_str_eq(str, str2);
  printf("Test011 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_12) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 12: %ld TEST", 14665465467),
                   sprintf(str2, "NUMBER 12: %ld TEST", 14665465467));
  ck_assert_str_eq(str, str2);
  printf("Test012 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_13) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 13: %u TEST", -12345),
                   sprintf(str2, "NUMBER 13: %u TEST", -12345));
  ck_assert_str_eq(str, str2);
  printf("Test013 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_14) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 14: %-10d TEST", -12345),
                   sprintf(str2, "NUMBER 14: %-10d TEST", -12345));
  ck_assert_str_eq(str, str2);
  printf("Test014 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_15) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 15: %-10c TEST", 'X'),
                   sprintf(str2, "NUMBER 15: %-10c TEST", 'X'));
  ck_assert_str_eq(str, str2);
  printf("Test015 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_16) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 16: +%5d TEST", 54321),
                   sprintf(str2, "NUMBER 16: +%5d TEST", 54321));
  ck_assert_str_eq(str, str2);
  printf("Test016 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_17) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 17: %15s TEST", "Hello World!"),
                   sprintf(str2, "NUMBER 17: %15s TEST", "Hello World!"));
  ck_assert_str_eq(str, str2);
  printf("Test017 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_18) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 18: %.3f TEST", 123.456789),
                   sprintf(str2, "NUMBER 18: %.3f TEST", 123.456789));
  ck_assert_str_eq(str, str2);
  printf("Test018 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_19) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str, "NUMBER 19: %-10s|%5d|%c|%.2f", "string",
                               12345, 'Z', 123.456789),
                   sprintf(str2, "NUMBER 19: %-10s|%5d|%c|%.2f", "string",
                           12345, 'Z', 123.456789));
  ck_assert_str_eq(str, str2);
  printf("Test019 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_20) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str, "NUMBER 20: %10hd%10ld", (short)-12345,
                  (long)-1234567890),
      sprintf(str2, "NUMBER 20: %10hd%10ld", (short)-12345, (long)-1234567890));
  ck_assert_str_eq(str, str2);
  printf("Test020 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_21) {
  char *str, *str2;
  str = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "This is a simple value %d";
  int val = 6;
  ck_assert_int_eq(s21_sprintf(str, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str, str2);
  printf("Test021 --------------\n");
  printf("%s\n", str);
  printf("%s\n", str2);
  free(str);
  free(str2);
}
END_TEST

START_TEST(test_22) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%5d";
  int val = 63;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test022 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_23) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%+12d";
  int val = 473;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test023 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_24) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%0*d";
  int val = 123;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));
  ck_assert_str_eq(str1, str2);
  printf("Test024 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_25) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test025 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_26) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test026 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_27) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test027 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_28) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test028 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_29) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test029 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_30) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test030 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_31) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test031 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_32) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test032 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_33) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test033 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_34) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));
  ck_assert_str_eq(str1, str2);
  printf("Test034 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_35) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test035 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_36) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test036 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_37) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test037 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_38) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test038 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_39) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));
  ck_assert_str_eq(str1, str2);
  printf("Test039 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_40) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test040 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_41) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  printf("Test041 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_42) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test042 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_43) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));
  ck_assert_str_eq(str1, str2);
  printf("Test043 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_44) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test044 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_45) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));
  ck_assert_str_eq(str1, str2);
  printf("Test045 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_46) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test046 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_47) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test047 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_48) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test048 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_49) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));
  ck_assert_str_eq(str1, str2);
  printf("Test049 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_50) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test050 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_51) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test051 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_52) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test052 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_53) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test053 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_54) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test054 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_55) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test055 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_56) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test056 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_57) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test057 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_58) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test058 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_59) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test059 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_60) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));
  ck_assert_str_eq(str1, str2);
  printf("Test060 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_61) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test061 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_62) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test062 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_63) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test063 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_64) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%15s";
  char *val = "55 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test064 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_65) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%-15.9s";
  char *val = "11 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test066 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_66) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%s";
  char *val =
      "33 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test066 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_67) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%s%s%s%s";
  char *val =
      "44 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));
  ck_assert_str_eq(str1, str2);
  printf("Test067 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_68) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
  printf("Test068 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_69) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
  printf("Test069 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_70) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
  printf("Test070 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_71) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%p";
  char *ptr = NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));
  ck_assert_str_eq(str1, str2);
  printf("Test071 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_72) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test072 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_73) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test073 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_74) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test074 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_75) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test075 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_76) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test076 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_77) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test077 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_78) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.14Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test078 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_79) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test079 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_80) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test080 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_81) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));
  ck_assert_str_eq(str1, str2);
  printf("Test081 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_82) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.17Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test082 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_83) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test083 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_84) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test084 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_85) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test085 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_86) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test086 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_87) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test087 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_88) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test088 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_89) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test089 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_90) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));
  ck_assert_str_eq(str1, str2);
  printf("Test090 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_91) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
  printf("Test091 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_92) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));
  ck_assert_str_eq(str1, str2);
  printf("Test092 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_93) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));
  ck_assert_str_eq(str1, str2);
  printf("Test093 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_94) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));
  ck_assert_str_eq(str1, str2);
  printf("Test094 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_95) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));
  ck_assert_str_eq(str1, str2);
  printf("Test095 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_96) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));
  ck_assert_str_eq(str1, str2);
  printf("Test096 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_97) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));
  ck_assert_str_eq(str1, str2);
  printf("Test097 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_98) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));
  ck_assert_str_eq(str1, str2);
  printf("Test098 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_99) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
  printf("Test099 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_100) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));
  ck_assert_str_eq(str1, str2);
  printf("Test100 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_101) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));
  ck_assert_str_eq(str1, str2);
  printf("Test101 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_102) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));
  ck_assert_str_eq(str1, str2);
  printf("Test102 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_103) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));
  ck_assert_str_eq(str1, str2);
  printf("Test103 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_104) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));
  ck_assert_str_eq(str1, str2);
  printf("Test104 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_105) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));
  ck_assert_str_eq(str1, str2);
  printf("Test105 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_106) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  printf("Test106 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_107) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  printf("Test107 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_108) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  printf("Test108 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_109) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  printf("Test109 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_110) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  printf("Test110 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_111) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  printf("Test111 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_112) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
  printf("Test112 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_113) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
  printf("Test113 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_114) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  printf("Test114 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_115) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  printf("Test115 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_116) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  printf("Test116 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_117) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  printf("Test117 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_118) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  printf("Test118 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_119) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  printf("Test119 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_120) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  printf("Test120 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_121) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  printf("Test121 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_122) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  printf("Test122 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_123) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  printf("Test123 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_124) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  printf("Test124 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_125) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  printf("Test125 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_126) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
  printf("Test126 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_127) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
  printf("Test127 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_128) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  printf("Test128 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_129) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  printf("Test129 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_130) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  printf("Test130 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_131) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  printf("Test131 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_132) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  printf("Test132 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_133) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  printf("Test133 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_134) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
  printf("Test134 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_135) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
  printf("Test135 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_136) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  printf("Test136 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_137) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);
  printf("Test137 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_138) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
  printf("Test138 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_139) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  printf("Test139 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_140) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);
  printf("Test140 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_141) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
  printf("Test141 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_142) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
  printf("Test142 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_143) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
  printf("Test143 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_144) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
  printf("Test144 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_145) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
  printf("Test145 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_146) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
  printf("Test146 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_147) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
  printf("Test147 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_148) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  printf("Test148 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_149) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  printf("Test149 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_150) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  printf("Test150 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_151) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  printf("Test151 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_152) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
  printf("Test152 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_153) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  printf("Test153 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_154) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  printf("Test154 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_155) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  printf("Test155 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_156) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  printf("Test156 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_157) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
  printf("Test157 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_158) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%10ld";
  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));
  ck_assert_str_eq(str1, str2);
  printf("Test158 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_159) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%1.1f";
  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));
  ck_assert_str_eq(str1, str2);
  printf("Test159 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_160) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%8.3c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));
  ck_assert_str_eq(str1, str2);
  printf("Test160 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_161) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%+5.5d aboba";
  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
  printf("Test161 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_162) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%7.7f";
  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));
  ck_assert_str_eq(str1, str2);
  printf("Test162 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_163) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%7.4s";
  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));
  ck_assert_str_eq(str1, str2);
  printf("Test163 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_164) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%6.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));
  ck_assert_str_eq(str1, str2);
  printf("Test164 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_165) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%ld%lu";
  ck_assert_int_eq(s21_sprintf(str1, format, 777, 111),
                   sprintf(str2, format, 777, 111));
  ck_assert_str_eq(str1, str2);
  printf("Test165 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_166) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%hd%hu";
  ck_assert_int_eq(s21_sprintf(str1, format, -777, 111),
                   sprintf(str2, format, -777, 111));
  ck_assert_str_eq(str1, str2);
  printf("Test166 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_167) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%+lu%+d%+lf";
  ck_assert_int_eq(s21_sprintf(str1, format, 321, -5555, -1213.123),
                   sprintf(str2, format, 321, -5555, -1213.123));
  ck_assert_str_eq(str1, str2);
  printf("Test167 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_168) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%-35.5lu%-3.5ld%33.10Lf";
  long double k = 333.33213;
  ck_assert_int_eq(s21_sprintf(str1, format, 5555555555, 44444444444, k),
                   sprintf(str2, format, 5555555555, 44444444444, k));
  ck_assert_str_eq(str1, str2);
  printf("Test168 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_169) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "% 0.0lu% 0.0ld % 0.0lf";
  ck_assert_int_eq(s21_sprintf(str1, format, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
  printf("Test169 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_170) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "% 0.0hu% 0.0hd % 0.0f";
  ck_assert_int_eq(s21_sprintf(str1, format, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 222, 33333333333, -166513.1232));
  ck_assert_str_eq(str1, str2);
  printf("Test170 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_171) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "% c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));
  ck_assert_str_eq(str1, str2);
  printf("Test171 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_172) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "% s";
  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));
  ck_assert_str_eq(str1, str2);
  printf("Test172 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_173) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "% s% c";
  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));
  ck_assert_str_eq(str1, str2);
  printf("Test173 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_174) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%210s";
  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));
  ck_assert_str_eq(str1, str2);
  printf("Test174 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_175) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%-115s";
  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));
  ck_assert_str_eq(str1, str2);
  printf("Test175 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_176) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%+2.1c%+4.2d%+10.2f%+55.55s%+1.1u";
  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));
  ck_assert_str_eq(str1, str2);
  printf("Test176 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_177) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%.f";
  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));
  ck_assert_str_eq(str1, str2);
  printf("Test177 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_181) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%-.f";
  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));
  ck_assert_str_eq(str1, str2);
  printf("Test181 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_182) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%-.1d";
  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));
  ck_assert_str_eq(str1, str2);
  printf("Test182 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_183) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));
  ck_assert_str_eq(str1, str2);
  printf("Test183 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_184) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%e%e%e%e";
  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));
  ck_assert_str_eq(str1, str2);
  printf("Test184 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_185) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%Le";
  long double x = 122.1231;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));
  ck_assert_str_eq(str1, str2);
  printf("Test185 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_186) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%.10e";
  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));
  ck_assert_str_eq(str1, str2);
  printf("Test186 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_187) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%5.3e%3.2e%lf";
  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));
  ck_assert_str_eq(str1, str2);
  printf("Test187 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_188) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%E";
  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));
  ck_assert_str_eq(str1, str2);
  printf("Test188 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_189) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));
  ck_assert_str_eq(str1, str2);
  printf("Test189 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_190) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));
  ck_assert_str_eq(str1, str2);
  printf("Test190 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_191) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%#e Floppa %#E%#f";
  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));
  ck_assert_str_eq(str1, str2);
  printf("Test191 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_192) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%.Lf";
  long double a = 7.9418438184;
  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));
  ck_assert_str_eq(str1, str2);
  printf("Test192 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_193) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%.Lf";
  long double a = 7.9418438184;
  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));
  ck_assert_str_eq(str1, str2);
  printf("Test193 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_194) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%.5o";
  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));
  ck_assert_str_eq(str1, str2);
  printf("Test194 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_195) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test195 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_196) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test196 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_197) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test197 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_198) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test198 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_199) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test199 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_200) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test200 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_201) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test201 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_202) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test202 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_203) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test203 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_204) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test204 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_205) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test205 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_206) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test206 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_207) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test207 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_208) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
  printf("Test208 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_209) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));
  ck_assert_str_eq(str1, str2);
  printf("Test209 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_211) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test211 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_213) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "Work with string: %15s ...";
  int a = s21_sprintf(str1, format, "Hello!");
  int b = sprintf(str2, format, "Hello!");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test213 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_214) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  int a =
      s21_sprintf(str1,
                  "Work with string: "
                  "%1s%10s%.s%1.s%.1s%1.1s%1.2s%2.1s%6.1s%6.6s%6.10s%10.s%10."
                  "1s%10.9s%10.10s%10.20s ...",
                  "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!",
                  "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!",
                  "Hello!", "Hello!", "Hello!", "Hello!");
  int b = sprintf(str2,
                  "Work with string: "
                  "%1s%10s%.s%1.s%.1s%1.1s%1.2s%2.1s%6.1s%6.6s%6.10s%10.s%10."
                  "1s%10.9s%10.10s%10.20s ...",
                  "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!",
                  "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!",
                  "Hello!", "Hello!", "Hello!", "Hello!");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test214 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_215) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  int a =
      s21_sprintf(str1,
                  "Work with string: "
                  "%-1s***%-10s***%-.s***%-1.s***%-.1s***%-1.1s***%-1.2s***%-2."
                  "1s***%-6.1s***%-6.6s***%-6.10s***%-10.s***%-10.1s***%-10.9s*"
                  "**%-10.10s***%-10.20s ...",
                  "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!",
                  "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!",
                  "Hello!", "Hello!", "Hello!", "Hello!");
  int b = sprintf(str2,
                  "Work with string: "
                  "%-1s***%-10s***%-.s***%-1.s***%-.1s***%-1.1s***%-1.2s***%-2."
                  "1s***%-6.1s***%-6.6s***%-6.10s***%-10.s***%-10.1s***%-10.9s*"
                  "**%-10.10s***%-10.20s ...",
                  "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!",
                  "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!",
                  "Hello!", "Hello!", "Hello!", "Hello!");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test215 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_216) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "% -20ld%+-20ld%- 20ld%-+20ld%-+ 20ld%-+ 30ld%0+30ld%+-30ld";
  int a = s21_sprintf(str1, format, 922337203685, -922337203685, 922337203685,
                      -922337203685, 922337203685, 75756546, 922337203685,
                      922337203685);
  int b = sprintf(str2, format, 922337203685, -922337203685, 922337203685,
                  -922337203685, 922337203685, 75756546, 922337203685,
                  922337203685);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test216 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_217) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%-20d%-+20d%- 20d%-#20d%-020d";
  int a = s21_sprintf(str1, format, 1, 12, 123, 12345, 124567890);
  int b = sprintf(str2, format, 1, 12, 123, 12345, 124567890);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test217 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_218) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%+20d%+20d%+ 20d%+020d%+.20d";
  int a = s21_sprintf(str1, format, 1, 11, 22, 3333, 45745645);
  int b = sprintf(str2, format, 1, 11, 22, 3333, 45745645);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test218 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_219) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%+20d%+20d%+ 20d%+020d%+.20d";
  int a = s21_sprintf(str1, format, -1, -11, -22, -3333, -45745645);
  int b = sprintf(str2, format, -1, -11, -22, -3333, -45745645);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test219 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_220) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "% #d% #d% 0d% 0d% .d% .d% 1.d% 1.d";
  int a = s21_sprintf(str1, format, 1, -11, 2, -22, 3, -33, 987, -987);
  int b = sprintf(str2, format, 1, -11, 2, -22, 3, -33, 987, -987);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test220 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_221) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%-Lf%-Lf%+Lf%+Lf% Lf% Lf%#Lf%#Lf%0Lf%0Lf";
  long double k = 333.33213;
  long double l = -333.33213;
  int a = s21_sprintf(str1, format, k, l, k, l, k, l, k, l, k, l);
  int b = sprintf(str2, format, k, l, k, l, k, l, k, l, k, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test221 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_222) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%-+Lf%- Lf%-#Lf%-0Lf";
  long double k = -333.33213;
  int a = s21_sprintf(str1, format, k, k, k, k);
  int b = sprintf(str2, format, k, k, k, k);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test222 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_223) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%1.1Lf";
  long double k = -4736574.3345356378213;
  int a = s21_sprintf(str1, format, k);
  int b = sprintf(str2, format, k);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test223 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_224) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%10.1Lf";
  long double k = -4736574.3345356378213;
  int a = s21_sprintf(str1, format, k);
  int b = sprintf(str2, format, k);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test224 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_225) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%10.10Lf";
  long double k = -4736574.3345356378213;
  int a = s21_sprintf(str1, format, k);
  int b = sprintf(str2, format, k);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test225 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_226) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%10.11Lf";
  long double k = -4736574.3345356378213;
  int a = s21_sprintf(str1, format, k);
  int b = sprintf(str2, format, k);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test226 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_227) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%0.0Lf";
  long double k = -4736574.3345356378213;
  int a = s21_sprintf(str1, format, k);
  int b = sprintf(str2, format, k);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test227 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_228) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%5.10Lf";
  long double k = -4736574.3345356378213;
  int a = s21_sprintf(str1, format, k);
  int b = sprintf(str2, format, k);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test228 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_229) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%50.10Lf%75.10Lf%19.10Lf";
  long double k = -4736574.334;
  int a = s21_sprintf(str1, format, k, k, k);
  int b = sprintf(str2, format, k, k, k);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test229 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_230) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%p%10p";
  long double k = -4736574.334;
  long double *ptr = &k;
  int a = s21_sprintf(str1, format, ptr, ptr);
  int b = sprintf(str2, format, ptr, ptr);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test230 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_231) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format =
      "%o%.o%0.o%.0o%0.0o%1.o%.1o%1.1o%1.3o%3.1o%3.3o%4.3o%3.4o%5.5o%6.5o%5.6o%"
      "ho";

  int a = s21_sprintf(str1, format, 100, 200, 300, 534573, 9988, 4, 100, 101,
                      102, 103, 104, 105, 106, 107, 108, 109, 564575646);
  int b = sprintf(str2, format, 100, 200, 300, 534573, 9988, 4, 100, 101, 102,
                  103, 104, 105, 106, 107, 108, 109, 564575646);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test231 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_232) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format =
      "%o%.o%0.o%.0o%0.0o%1.o%.1o%1.1o%1.3o%3.1o%3.3o%4.3o%3.4o%5.5o%6.5o%5.6o%"
      "10.11o%11.10o%11.11o%15.11o%15.9o%15.14o%15.19o";
  int a = s21_sprintf(str1, format, -100, -200, -300, -534573, -9988, -4, -100,
                      -101, -102, -103, -104, -105, -106, -107, -108, -109,
                      -1234, -1234, -1234, -1234, -1234, -1234, -1234);
  int b = sprintf(str2, format, -100, -200, -300, -534573, -9988, -4, -100,
                  -101, -102, -103, -104, -105, -106, -107, -108, -109, -1234,
                  -1234, -1234, -1234, -1234, -1234, -1234);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test232 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_233) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%d%+d% d%5d%-5d%05d%.3d%ld";
  int a = s21_sprintf(str1, format, 12345, -12345, 12345, 123, 123, 123, 12345,
                      (long)123456789L);
  int b = sprintf(str2, format, 12345, -12345, 12345, 123, 123, 123, 12345,
                  (long)123456789L);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test233 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_234) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%f%.2f%+.2E%10.2f%+10.2f%#10.2f";
  int a = s21_sprintf(str1, format, 123.456, 123.456, -123.456, 123.456,
                      123.456, 123.456);
  int b = sprintf(str2, format, 123.456, 123.456, -123.456, 123.456, 123.456,
                  123.456);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test234 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_235) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%s%.3s%-10s";
  int a = s21_sprintf(str1, format, "hello", "world", "test");
  int b = sprintf(str2, format, "hello", "world", "test");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test235 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_236) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%X%#x%#o%p%.*s%*d";
  int a = s21_sprintf(str1, format, 12345, 12345, 12345, (void *)0xDEADBEEF, 3,
                      "example", 5, 123);
  int b = sprintf(str2, format, 12345, 12345, 12345, (void *)0xDEADBEEF, 3,
                  "example", 5, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test236 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_237) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#x%#o%#g%c%05d%ld";
  int a = s21_sprintf(str1, format, 12345, 12345, 123.456, 'A', 123,
                      (long)123456789L);
  int b =
      sprintf(str2, format, 12345, 12345, 123.456, 'A', 123, (long)123456789L);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test237 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_238) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%05d%ld%E%#g% d%*.*f";
  int a = s21_sprintf(str1, format, 123, (long)123456789L, 123.456, 123.456,
                      123, 10, 2, 123.456);
  int b = sprintf(str2, format, 123, (long)123456789L, 123.456, 123.456, 123,
                  10, 2, 123.456);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test238 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_239) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%+d%#X%Ld%f%.2f%E";
  int a = s21_sprintf(str1, format, -123, 12345, (long long)123456789012345LL,
                      123.456, 123.456, 123.456);
  int b = sprintf(str2, format, -123, 12345, (long long)123456789012345LL,
                  123.456, 123.456, 123.456);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test239 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_240) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%10d%d%-10d%05d%+d% d%-10s%#X%o%X%s%-10s";
  int a = s21_sprintf(str1, format, 123, -123, 123, 123, 123, -123, "test",
                      12345, 12345, 12345, "", "abc");
  int b = sprintf(str2, format, 123, -123, 123, 123, 123, -123, "test", 12345,
                  12345, 12345, "", "abc");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test240 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_241) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%hu%hu%hu%.3s%.2f%s%*.*f";
  int a = s21_sprintf(str1, format, 65536, 100000, -65539, "abcdef", 123.456,
                      "TEST", 10, 2, 123.456);
  int b = sprintf(str2, format, 65536, 100000, -65539, "abcdef", 123.456,
                  "TEST", 10, 2, 123.456);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test241 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_242) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%+d%10.2f%lu%p%.2f";
  int a = s21_sprintf(str1, format, 123, 123.456, (unsigned long)4294967295UL,
                      (void *)0xDEADBEEF, 123.456);
  int b = sprintf(str2, format, 123, 123.456, (unsigned long)4294967295UL,
                  (void *)0xDEADBEEF, 123.456);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test242 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_243) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%s%s%c";
  int a = s21_sprintf(str1, format, "", "\0", "\0");
  int b = sprintf(str2, format, "", "\0", "\0");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test243 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_244) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%+5d%05d%-.2f%10d%#X%lo%hd";
  int a = s21_sprintf(str1, format, 123, 123, -123.456, 123456789, 12345,
                      (long)123456789L, (char)123);
  int b = sprintf(str2, format, 123, 123, -123.456, 123456789, 12345,
                  (long)123456789L, (char)123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test244 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_245) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.5s%p%-10s%.3s%.10s";
  int a = s21_sprintf(str1, format, "abcdefghij", (void *)0xDEADBEEF, "Test",
                      "example", "ThisIsALongText");
  int b = sprintf(str2, format, "abcdefghij", (void *)0xDEADBEEF, "Test",
                  "example", "ThisIsALongText");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test245 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_246) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%lo%+d%hd%#lo%+.2f%.3f%-10d";
  int a = s21_sprintf(str1, format, 64, 123456789, (char)123, (long)123456789L,
                      123.456, 123.456789, 123);
  int b = sprintf(str2, format, 64, 123456789, (char)123, (long)123456789L,
                  123.456, 123.456789, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test246 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_247) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%#010X%.6f%.3f%10d%-10s%hd%.0f% d%hx";
  int a = s21_sprintf(str1, format, 12345, 123.456789, 123.456, 123, "Example",
                      -32768, 123.456, 123, (char)123);
  int b = sprintf(str2, format, 12345, 123.456789, 123.456, 123, "Example",
                  -32768, 123.456, 123, (char)123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test247 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_248) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%.5s%#08X%.2E%lu%d";
  int a = s21_sprintf(str1, format, "ThisIsALongText", 12345, 123.456,
                      18446744073709551615UL, 2147483647);
  int b = sprintf(str2, format, "ThisIsALongText", 12345, 123.456,
                  18446744073709551615UL, 2147483647);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test248 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_249) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%10.2f%-10d%#X%#X";
  int a = s21_sprintf(str1, format, 123.456, 123, 12345, -54321);
  int b = sprintf(str2, format, 123.456, 123, 12345, -54321);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test249 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_250) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%d%d%hd%hd%ld%ld";
  int a = s21_sprintf(str1, format, INT_MIN, INT_MAX, SHRT_MIN, SHRT_MAX,
                      LONG_MIN, LONG_MAX);
  int b = sprintf(str2, format, INT_MIN, INT_MAX, SHRT_MIN, SHRT_MAX, LONG_MIN,
                  LONG_MAX);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test250 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_251) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%u %hu %lu %#o %#x %#X";
  int a = s21_sprintf(str1, format, UINT_MAX, USHRT_MAX, ULONG_MAX, 0123,
                      0xABCDEF, 0xABCDEF);
  int b = sprintf(str2, format, UINT_MAX, USHRT_MAX, ULONG_MAX, 0123, 0xABCDEF,
                  0xABCDEF);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test251 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_252) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%c %c %f";
  int a = s21_sprintf(str1, format, 'A', L'A', FLT_MIN);
  int b = sprintf(str2, format, 'A', L'A', FLT_MIN);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test252 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_253) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%d%d%d%d%d";
  int a = s21_sprintf(str1, format, -2147483647, 2147483647, 0, -123456789,
                      123456789);
  int b =
      sprintf(str2, format, -2147483647, 2147483647, 0, -123456789, 123456789);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test253 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_254) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%22.30d%22.30d%22.30d%22.30d%22.30d";
  int a = s21_sprintf(str1, format, -2147483647, 2147483647, 0, -123456789,
                      123456789);
  int b =
      sprintf(str2, format, -2147483647, 2147483647, 0, -123456789, 123456789);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test254 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_255) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  int a = s21_sprintf(str1, "%1.0f***%1.0f***%1.0f***%1.0f***%1.0f", 0.0,
                      123.456, -123.456, -0.00005456, -5565746456.56);
  int b = sprintf(str2, "%1.0f***%1.0f***%1.0f***%1.0f***%1.0f", 0.0, 123.456,
                  -123.456, -0.00005456, -5565746456.56);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test255 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_256) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  int a = s21_sprintf(str1, "%3.0f***%3.0f***%3.0f***%3.0f***%3.0f", 0.0,
                      123.456, -123.456, -0.00005456, -5565746456.56);
  int b = sprintf(str2, "%3.0f***%3.0f***%3.0f***%3.0f***%3.0f", 0.0, 123.456,
                  -123.456, -0.00005456, -5565746456.56);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test256 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_257) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format =
      "%o*%o*%-o*%-o*%+o*%+o*% o*% o*%#o*%#o*%0o*%0o*%-+o*%-+o*%- o*%- "
      "o*%-#o*%-#o*%-0o*%-0o*%+ o*%+ o*%+#o*%+#o*%+0o*%+0o*% #o*% #o*% 0o*% "
      "0o*%#0o*%#0o*%11.11o*%11.12o*%12.11o*%12.13o*%13.12o*%15.15o%2.2o*%0.2o*"
      "%1.2o*%2.3o*%3.3o*%3.4o*%4.3o";
  int a = s21_sprintf(
      str1, format, 1, -1, 10, -10, 111, -111, 1234, -1234, 98765, -98765, 634,
      -634, 1, 0, 2, -2, 3, -3, 4, -4, 11, -11, 456, -456, 123456789,
      -123456789, 123456789123456789, -123456789123456789, 19, -19, 77, -77,
      -123456789123456789, -123456789123456789, -123456789123456789,
      -123456789123456789, -123456789123456789, -123456789123456789,
      -123456789123456789, -123456789123456789, -123456789123456789,
      -123456789123456789, -123456789123456789, -123456789123456789,
      -123456789123456789);
  int b =
      sprintf(str2, format, 1, -1, 10, -10, 111, -111, 1234, -1234, 98765,
              -98765, 634, -634, 1, 0, 2, -2, 3, -3, 4, -4, 11, -11, 456, -456,
              123456789, -123456789, 123456789123456789, -123456789123456789,
              19, -19, 77, -77, -123456789123456789, -123456789123456789,
              -123456789123456789, -123456789123456789, -123456789123456789,
              -123456789123456789, -123456789123456789, -123456789123456789,
              -123456789123456789, -123456789123456789, -123456789123456789,
              -123456789123456789, -123456789123456789);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test257 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_258) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format =
      "%0.0o*%0.1o*%1.0o*%1.1o*%2.0o*%2.1o%2.2o*%0.2o*%1.2o*%2.3o*%3.3o*%3.4o*%"
      "4.3o%0.0o*%0.1o*%1.0o*%1.1o*%2.0o*%2.1o%2.2o*%0.2o*%1.2o*%2.3o*%3.3o*%3."
      "4o*%4.3o%11.11o*%11.12o*%12.11o*%12.13o*%13.12o*%15.15o%2.2o*%0.2o*%1."
      "2o*%2.3o*%3.3o*%3.4o*%4.3o";
  int a = s21_sprintf(
      str1, format, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, 123456789123456789, 123456789123456789,
      123456789123456789, 123456789123456789, 123456789123456789,
      123456789123456789, 123456789123456789, 123456789123456789,
      123456789123456789, 123456789123456789, 123456789123456789,
      123456789123456789, 123456789123456789);
  int b =
      sprintf(str2, format, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1,
              -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 123456789123456789,
              123456789123456789, 123456789123456789, 123456789123456789,
              123456789123456789, 123456789123456789, 123456789123456789,
              123456789123456789, 123456789123456789, 123456789123456789,
              123456789123456789, 123456789123456789, 123456789123456789);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test258 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_259) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%p%-p%-20p%+p%+20p%-+20p% p% 20p%#p%#20p%0p%020p%-+p%- p%-#p%-0p%+ "
      "p%+#p%+0p% #p% 0p%#0p";
  int a =
      s21_sprintf(str1, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89);
  int b = sprintf(str2, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test259 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_260) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%0.0p%0.p%.0p%3.3p*%14.10p*%20.10p*%20.14p%20.19p*%0.14p*%5.20p%14.20p%"
      "20.20p*%20.0p";
  int a = s21_sprintf(str1, format89, format89, format89, format89, format89,
                      format89, format89, format89, format89, format89,
                      format89, format89, format89, format89);
  int b = sprintf(str2, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test260 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_261) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%+0.0p%+0.p%+.0p%+3.3p*%+14.10p*%+20.10p*%+20.14p%+20.19p*%+0.14p*%+5."
      "20p%+14.20p%+20.20p*%+20.0p%-0.0p%-0.p%-.0p%-3.3p*%-14.10p*%-20.10p*%-"
      "20.14p%-20.19p*%-0.14p*%-5.20p%-14.20p%-20.20p*%-20.0p% 0.0p% 0.p% .0p% "
      "3.3p*% 14.10p*% 20.10p*% 20.14p% 20.19p*% 0.14p*% 5.20p% 14.20p% "
      "20.20p*% "
      "20.0p%#0.0p%#0.p%#.0p%#3.3p*%#14.10p*%#20.10p*%#20.14p%#20.19p*%#0.14p*%"
      "#5.20p%#14.20p%#20.20p*%#20.0p";
  int a = s21_sprintf(
      str1, format89, format89, format89, format89, format89, format89,
      format89, format89, format89, format89, format89, format89, format89,
      format89, format89, format89, format89, format89, format89, format89,
      format89, format89, format89, format89, format89, format89, format89,
      format89, format89, format89, format89, format89, format89, format89,
      format89, format89, format89, format89, format89, format89, format89,
      format89, format89, format89, format89, format89, format89, format89,
      format89, format89, format89, format89, format89);
  int b = sprintf(str2, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test261 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_262) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%00.0p%00.p%0.0p%03.3p*%014.10p*%020.10p*%020.14p%020.19p*%00.14p*%05."
      "20p%014.20p%020.20p*%020.0p";
  int a = s21_sprintf(str1, format89, format89, format89, format89, format89,
                      format89, format89, format89, format89, format89,
                      format89, format89, format89, format89);
  int b = sprintf(str2, format89, format89, format89, format89, format89,
                  format89, format89, format89, format89, format89, format89,
                  format89, format89, format89);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test262 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_263) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%c*%-c*%+c*% c*%#c*%0c*%-+c*%- c*%-#c*%-0c*%+ c*%+#c*%+0c*% #c*% "
      "0c*%#0c*%10c*%+10c*%010c*%0.0c*%0.1c*%1.0c*%1.1c*%5.0c%5.1c*%5.5c*%5.8c*"
      "%0.8c*%1.8c%-10.6c*%06.10c***%+- #05.8c";
  int a = s21_sprintf(str1, format89, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
                      'o', 'p', 'a', '[', '*', '\\', '\'', '\n', '\"', '\t',
                      '\r', '\b', '\f', '\v', '\a', '\x41', '\101', '1', '0',
                      '.', '6', '&', '$', 'Z');
  int b =
      sprintf(str2, format89, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
              'a', '[', '*', '\\', '\'', '\n', '\"', '\t', '\r', '\b', '\f',
              '\v', '\a', '\x41', '\101', '1', '0', '.', '6', '&', '$', 'Z');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test263 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_264) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%d*1!*%-10d*2!*%-d*3!*%+d*4!*% d*5!*%#d*6!*%0d*7!*%010d*8!*%-+d*9!*%- "
      "d*10!*%-#d*11!*%-0d*12!*%+ d*13!*%+#d*14!*%+010d*15!*%+0d*16!*% "
      "#d*17!*% 0d*18!*% "
      "010d*19!*%#0d*20!*%#05d*21!*%0.0d*22!*%0.1d*23!*%1.0d*24*%1.1d*25*%2.0d*"
      "26*%2.1d*27*%2.2d*28*%0.2d*29*%5.2d*30*%5.5d*31*%7.5d*32*%5.7d*33*%-7."
      "5d*34*%-5.7d*35*%-0.0d*36*%-2.2d*37*%-7.7d*38*%+7.5d*38*%+7.5d*39*%+5."
      "7d*40*%07.5d*41*%05.7d*42*%-+ 5d*43*%-+ #0d*44*%-+ #05.7d";
  int a =
      s21_sprintf(str1, format89, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
                  30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44);
  int b = sprintf(str2, format89, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
                  30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test264 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_265) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%d*1!*%-10d*2!*%-d*3!*%+d*4!*% d*5!*%#d*6!*%0d*7!*%010d*8!*%-+d*9!*%- "
      "d*10!*%-#d*11!*%-0d*12!*%+ d*13!*%+#d*14!*%+010d*15!*%+0d*16!*% "
      "#d*17!*% 0d*18!*% "
      "010d*19!*%#0d*20!*%#05d*21!*%0.0d*22!*%0.1d*23!*%1.0d*24*%1.1d*25*%2.0d*"
      "26*%2.1d*27*%2.2d*28*%0.2d*29*%5.2d*30*%5.5d*31*%7.5d*32*%5.7d*33*%-7."
      "5d*34*%-5.7d*35*%-0.0d*36*%-2.2d*37*%-7.7d*38*%+7.5d*38*%+7.5d*39*%+5."
      "7d*40*%07.5d*41*%05.7d*42*%-+ 5d*43*%-+ #0d*44*%-+ #05.7d";
  int a =
      s21_sprintf(str1, format89, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11,
                  -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23,
                  -24, -25, -26, -27, -28, -29, -30, -31, -32, -33, -34, -35,
                  -36, -37, -38, -39, -40, -41, -42, -43, -44);
  int b = sprintf(str2, format89, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11,
                  -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23,
                  -24, -25, -26, -27, -28, -29, -30, -31, -32, -33, -34, -35,
                  -36, -37, -38, -39, -40, -41, -42, -43, -44);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test265 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_266) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%d*1!*%-10d*2!*%-d*3!*%+d*4!*% d*5!*%#d*6!*%0d*7!*%010d*8!*%-+d*9!*%- "
      "d*10!*%-#d*11!*%-0d*12!*%+ d*13!*%+#d*14!*%+010d*15!*%+0d*16!*% "
      "#d*17!*% 0d*18!*% "
      "010d*19!*%#0d*20!*%#05d*21!*%0.0d*22!*%0.1d*23!*%1.0d*24*%1.1d*25*%2.0d*"
      "26*%2.1d*27*%2.2d*28*%0.2d*29*%5.2d*30*%5.5d*31*%7.5d*32*%5.7d*33*%-7."
      "5d*34*%-5.7d*35*%-0.0d*36*%-2.2d*37*%-7.7d*38*%+7.5d*38*%+7.5d*39*%+5."
      "7d*40*%07.5d*41*%05.7d*42*%-+ 5d*43*%-+ #0d*44*%-+ #05.7d";
  int a = s21_sprintf(str1, format89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  int b = sprintf(str2, format89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test266 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_267) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%f*1!*%-10f*2!*%-f*3!*%+f*4!*% f*5!*%#f*6!*%0f*7!*%010f*8!*%-+f*9!*%- "
      "f*10!*%-#f*11!*%-0f*12!*%+ f*13!*%+#f*14!*%+010f*15!*%+0f*16!*% "
      "#f*17!*% 0f*18!*% "
      "010f*19!*%#0f*20!*%#05f*21!*%0.0f*22!*%0.1f*23!*%1.0f*24*%1.1f*25*%2.0f*"
      "26*%2.1f*27*%2.2f*28*%0.2f*29*%5.2f*30*%5.5f*31*%7.5f*32*%5.7f*33*%-7."
      "5f*34*%-5.7f*35*%-0.0f*36*%-2.2f*37*%-7.7f*38*%+7.5f*38*%+7.5f*39*%+5."
      "7f*40*%07.5f*41*%05.7f*42*%-+ 5f*43*%-+ #0f*44*%-+ #05.7f";
  int a = s21_sprintf(str1, format89, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8,
                      0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9,
                      2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0,
                      3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0, 4.1,
                      4.2, 4.3, 4.4, 4.5, 4.6);
  int b =
      sprintf(str2, format89, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0,
              1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3,
              2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6,
              3.7, 3.8, 3.9, 4.0, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test267 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_268) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%f*1!*%-10f*2!*%-f*3!*%+f*4!*% f*5!*%#f*6!*%0f*7!*%010f*8!*%-+f*9!*%- "
      "f*10!*%-#f*11!*%-0f*12!*%+ f*13!*%+#f*14!*%+010f*15!*%+0f*16!*% "
      "#f*17!*% 0f*18!*% "
      "010f*19!*%#0f*20!*%#05f*21!*%0.0f*22!*%0.1f*23!*%1.0f*24*%1.1f*25*%2.0f*"
      "26*%2.1f*27*%2.2f*28*%0.2f*29*%5.2f*30*%5.5f*31*%7.5f*32*%5.7f*33*%-7."
      "5f*34*%-5.7f*35*%-0.0f*36*%-2.2f*37*%-7.7f*38*%+7.5f*38*%+7.5f*39*%+5."
      "7f*40*%07.5f*41*%05.7f*42*%-+ 5f*43*%-+ #0f*44*%-+ #05.7f";
  int a =
      s21_sprintf(str1, format89, -0.1, -0.2, -0.3, -0.4, -0.5, -0.6, -0.7,
                  -0.8, -0.9, -1.0, -1.1, -1.2, -1.3, -1.4, -1.5, -1.6, -1.7,
                  -1.8, -1.9, -2.0, -2.1, -2.2, -2.3, -2.4, -2.5, -2.6, -2.7,
                  -2.8, -2.9, -3.0, -3.1, -3.2, -3.3, -3.4, -3.5, -3.6, -3.7,
                  -3.8, -3.9, -4.0, -4.1, -4.2, -4.3, -4.4, -4.5, -4.6);
  int b = sprintf(str2, format89, -0.1, -0.2, -0.3, -0.4, -0.5, -0.6, -0.7,
                  -0.8, -0.9, -1.0, -1.1, -1.2, -1.3, -1.4, -1.5, -1.6, -1.7,
                  -1.8, -1.9, -2.0, -2.1, -2.2, -2.3, -2.4, -2.5, -2.6, -2.7,
                  -2.8, -2.9, -3.0, -3.1, -3.2, -3.3, -3.4, -3.5, -3.6, -3.7,
                  -3.8, -3.9, -4.0, -4.1, -4.2, -4.3, -4.4, -4.5, -4.6);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test268 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_269) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%f*1!*%-10f*2!*%-f*3!*%+f*4!*% f*5!*%#f*6!*%0f*7!*%010f*8!*%-+f*9!*%- "
      "f*10!*%-#f*11!*%-0f*12!*%+ f*13!*%+#f*14!*%+010f*15!*%+0f*16!*% "
      "#f*17!*% 0f*18!*% "
      "010f*19!*%#0f*20!*%#05f*21!*%0.0f*22!*%0.1f*23!*%1.0f*24*%1.1f*25*%2.0f*"
      "26*%2.1f*27*%2.2f*28*%0.2f*29*%5.2f*30*%5.5f*31*%7.5f*32*%5.7f*33*%-7."
      "5f*34*%-5.7f*35*%-0.0f*36*%-2.2f*37*%-7.7f*38*%+7.5f*38*%+7.5f*39*%+5."
      "7f*40*%07.5f*41*%05.7f*42*%-+ 5f*43*%-+ #0f*44*%-+ #05.7f";
  int a = s21_sprintf(str1, format89, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0, 0.0);
  int b =
      sprintf(str2, format89, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  printf("Test269 --------------\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_270) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "%f*1!*%-10f*2!*%-f*3!*%+f*4!*% f*5!*%#f*6!*%0f*7!*%010f*8!*%-+f*9!*%- "
      "f*10!*%-#f*11!*%-0f*12!*%+ f*13!*%+#f*14!*%+010f*15!*%+0f*16!*% "
      "#f*17!*% 0f*18!*% "
      "010f*19!*%#0f*20!*%#05f*21!*%0.0f*22!*%0.1f*23!*%1.0f*24*%1.1f*25*%2.0f*"
      "26*%2.1f*27*%2.2f*28*%0.2f*29*%5.2f*30*%5.5f*31*%7.5f*32*%5.7f*33*%-7."
      "5f*34*%-5.7f*35*%-0.0f*36*%-2.2f*37*%-7.7f*38*%+7.5f*38*%+7.5f*39*%+5."
      "7f*40*%07.5f*41*%05.7f*42*%-+ 5f*43*%-+ #0f*44*%-+ #05.7f";
  int a = s21_sprintf(
      str1, format89, 6610.11966, 6610.21966, 6610.31966, 6610.41966,
      6610.51966, 6610.61966, 6610.71966, 6610.81966, 6610.91966, 6611.01966,
      6611.11966, 6611.21966, 6611.31966, 6611.41966, 6611.51966, 6611.61966,
      6611.71966, 6611.81966, 6611.91966, 6612.01966, 6612.11966, 6612.21966,
      6612.31966, 6612.41966, 6612.51966, 6612.61966, 6612.71966, 6612.81966,
      6612.91966, 6613.01966, 6613.11966, 6613.21966, 6613.31966, 6613.41966,
      6613.51966, 6613.61966, 6613.71966, 6613.81966, 6613.91966, 6614.01966,
      6614.11966, 6614.21966, 6614.31966, 6614.41966, 6614.51966, 6614.61966);
  int b = sprintf(
      str2, format89, 6610.11966, 6610.21966, 6610.31966, 6610.41966,
      6610.51966, 6610.61966, 6610.71966, 6610.81966, 6610.91966, 6611.01966,
      6611.11966, 6611.21966, 6611.31966, 6611.41966, 6611.51966, 6611.61966,
      6611.71966, 6611.81966, 6611.91966, 6612.01966, 6612.11966, 6612.21966,
      6612.31966, 6612.41966, 6612.51966, 6612.61966, 6612.71966, 6612.81966,
      6612.91966, 6613.01966, 6613.11966, 6613.21966, 6613.31966, 6613.41966,
      6613.51966, 6613.61966, 6613.71966, 6613.81966, 6613.91966, 6614.01966,
      6614.11966, 6614.21966, 6614.31966, 6614.41966, 6614.51966, 6614.61966);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_271) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format89 =
      "*1* %hu *2* %lu *3* %u *4* %5u *5* %-5u *6* %-10u *7* %10u *8* %-10u "
      "*9* %09u *10* %010u *11* %010lu *12* %020lu *13* %20u *14* %-20u *15* "
      "%020u *16* %.10u *17* %-.7u *18* %0.7u *19* %-07u *20* % u *21* %- u * "
      "22* %+07u * 23* %+ lu *24* %015.u *25* ";
  unsigned short us_val = 32767;
  unsigned long ul_val = 4294967295UL;
  int a = s21_sprintf(str1, format89, us_val, us_val, us_val, us_val, us_val,
                      us_val, us_val, us_val, us_val, us_val, ul_val, ul_val,
                      us_val, us_val, us_val, us_val, us_val, us_val, us_val,
                      us_val, us_val, us_val, ul_val, ul_val);
  int b = sprintf(str2, format89, us_val, us_val, us_val, us_val, us_val,
                  us_val, us_val, us_val, us_val, us_val, ul_val, ul_val,
                  us_val, us_val, us_val, us_val, us_val, us_val, us_val,
                  us_val, us_val, us_val, ul_val, ul_val);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_272) {
  char *str1, *str2;
  str1 = calloc(1024 + 1, sizeof(char));
  str2 = calloc(1024 + 1, sizeof(char));
  char *format = "%%fghgklhjdlhdffjgkl%%%d";
  int a = s21_sprintf(str1, format, 1);
  int b = sprintf(str2, format, 1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
  free(str1);
  free(str2);
}
END_TEST

Suite *make_suite(void) {
  Suite *s = suite_create("Sprintf tests");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);
  tcase_add_test(tc_core, test_5);
  tcase_add_test(tc_core, test_6);
  tcase_add_test(tc_core, test_7);
  tcase_add_test(tc_core, test_8);
  tcase_add_test(tc_core, test_9);
  tcase_add_test(tc_core, test_10);
  tcase_add_test(tc_core, test_11);
  tcase_add_test(tc_core, test_12);
  tcase_add_test(tc_core, test_13);
  tcase_add_test(tc_core, test_14);
  tcase_add_test(tc_core, test_15);
  tcase_add_test(tc_core, test_16);
  tcase_add_test(tc_core, test_17);
  tcase_add_test(tc_core, test_18);
  tcase_add_test(tc_core, test_19);
  tcase_add_test(tc_core, test_20);
  tcase_add_test(tc_core, test_21);
  tcase_add_test(tc_core, test_22);
  tcase_add_test(tc_core, test_23);
  tcase_add_test(tc_core, test_24);
  tcase_add_test(tc_core, test_25);
  tcase_add_test(tc_core, test_26);
  tcase_add_test(tc_core, test_27);
  tcase_add_test(tc_core, test_28);
  tcase_add_test(tc_core, test_29);
  tcase_add_test(tc_core, test_30);
  tcase_add_test(tc_core, test_31);
  tcase_add_test(tc_core, test_32);
  tcase_add_test(tc_core, test_33);
  tcase_add_test(tc_core, test_34);
  tcase_add_test(tc_core, test_35);
  tcase_add_test(tc_core, test_36);
  tcase_add_test(tc_core, test_37);
  tcase_add_test(tc_core, test_38);
  tcase_add_test(tc_core, test_39);
  tcase_add_test(tc_core, test_40);
  tcase_add_test(tc_core, test_41);
  tcase_add_test(tc_core, test_42);
  tcase_add_test(tc_core, test_43);
  tcase_add_test(tc_core, test_44);
  tcase_add_test(tc_core, test_45);
  tcase_add_test(tc_core, test_46);
  tcase_add_test(tc_core, test_47);
  tcase_add_test(tc_core, test_48);
  tcase_add_test(tc_core, test_49);
  tcase_add_test(tc_core, test_50);
  tcase_add_test(tc_core, test_51);
  tcase_add_test(tc_core, test_52);
  tcase_add_test(tc_core, test_53);
  tcase_add_test(tc_core, test_54);
  tcase_add_test(tc_core, test_55);
  tcase_add_test(tc_core, test_56);
  tcase_add_test(tc_core, test_57);
  tcase_add_test(tc_core, test_58);
  tcase_add_test(tc_core, test_59);
  tcase_add_test(tc_core, test_60);
  tcase_add_test(tc_core, test_61);
  tcase_add_test(tc_core, test_62);
  tcase_add_test(tc_core, test_63);
  tcase_add_test(tc_core, test_64);
  tcase_add_test(tc_core, test_65);
  tcase_add_test(tc_core, test_66);
  tcase_add_test(tc_core, test_67);
  tcase_add_test(tc_core, test_68);
  tcase_add_test(tc_core, test_69);
  tcase_add_test(tc_core, test_70);
  tcase_add_test(tc_core, test_71);
  tcase_add_test(tc_core, test_72);
  tcase_add_test(tc_core, test_73);
  tcase_add_test(tc_core, test_74);
  tcase_add_test(tc_core, test_75);
  tcase_add_test(tc_core, test_76);
  tcase_add_test(tc_core, test_77);
  tcase_add_test(tc_core, test_78);
  tcase_add_test(tc_core, test_79);
  tcase_add_test(tc_core, test_80);
  tcase_add_test(tc_core, test_81);
  tcase_add_test(tc_core, test_82);
  tcase_add_test(tc_core, test_83);
  tcase_add_test(tc_core, test_84);
  tcase_add_test(tc_core, test_85);
  tcase_add_test(tc_core, test_86);
  tcase_add_test(tc_core, test_87);
  tcase_add_test(tc_core, test_88);
  tcase_add_test(tc_core, test_89);
  tcase_add_test(tc_core, test_90);
  tcase_add_test(tc_core, test_91);
  tcase_add_test(tc_core, test_92);
  tcase_add_test(tc_core, test_93);
  tcase_add_test(tc_core, test_94);
  tcase_add_test(tc_core, test_95);
  tcase_add_test(tc_core, test_96);
  tcase_add_test(tc_core, test_97);
  tcase_add_test(tc_core, test_98);
  tcase_add_test(tc_core, test_99);
  tcase_add_test(tc_core, test_100);
  tcase_add_test(tc_core, test_101);
  tcase_add_test(tc_core, test_102);
  tcase_add_test(tc_core, test_103);
  tcase_add_test(tc_core, test_104);
  tcase_add_test(tc_core, test_105);
  tcase_add_test(tc_core, test_106);
  tcase_add_test(tc_core, test_107);
  tcase_add_test(tc_core, test_108);
  tcase_add_test(tc_core, test_109);
  tcase_add_test(tc_core, test_110);
  tcase_add_test(tc_core, test_111);
  tcase_add_test(tc_core, test_112);
  tcase_add_test(tc_core, test_113);
  tcase_add_test(tc_core, test_114);
  tcase_add_test(tc_core, test_115);
  tcase_add_test(tc_core, test_116);
  tcase_add_test(tc_core, test_117);
  tcase_add_test(tc_core, test_118);
  tcase_add_test(tc_core, test_119);
  tcase_add_test(tc_core, test_120);
  tcase_add_test(tc_core, test_121);
  tcase_add_test(tc_core, test_122);
  tcase_add_test(tc_core, test_123);
  tcase_add_test(tc_core, test_124);
  tcase_add_test(tc_core, test_125);
  tcase_add_test(tc_core, test_126);
  tcase_add_test(tc_core, test_127);
  tcase_add_test(tc_core, test_128);
  tcase_add_test(tc_core, test_129);
  tcase_add_test(tc_core, test_130);
  tcase_add_test(tc_core, test_131);
  tcase_add_test(tc_core, test_132);
  tcase_add_test(tc_core, test_133);
  tcase_add_test(tc_core, test_134);
  tcase_add_test(tc_core, test_135);
  tcase_add_test(tc_core, test_136);
  tcase_add_test(tc_core, test_137);
  tcase_add_test(tc_core, test_138);
  tcase_add_test(tc_core, test_139);
  tcase_add_test(tc_core, test_140);
  tcase_add_test(tc_core, test_141);
  tcase_add_test(tc_core, test_142);
  tcase_add_test(tc_core, test_143);
  tcase_add_test(tc_core, test_144);
  tcase_add_test(tc_core, test_145);
  tcase_add_test(tc_core, test_146);
  tcase_add_test(tc_core, test_147);
  tcase_add_test(tc_core, test_148);
  tcase_add_test(tc_core, test_149);
  tcase_add_test(tc_core, test_150);
  tcase_add_test(tc_core, test_151);
  tcase_add_test(tc_core, test_152);
  tcase_add_test(tc_core, test_153);
  tcase_add_test(tc_core, test_154);
  tcase_add_test(tc_core, test_155);
  tcase_add_test(tc_core, test_156);
  tcase_add_test(tc_core, test_157);
  tcase_add_test(tc_core, test_158);
  tcase_add_test(tc_core, test_159);
  tcase_add_test(tc_core, test_160);
  tcase_add_test(tc_core, test_161);
  tcase_add_test(tc_core, test_162);
  tcase_add_test(tc_core, test_163);
  tcase_add_test(tc_core, test_164);
  tcase_add_test(tc_core, test_165);
  tcase_add_test(tc_core, test_166);
  tcase_add_test(tc_core, test_167);
  tcase_add_test(tc_core, test_168);
  tcase_add_test(tc_core, test_169);
  tcase_add_test(tc_core, test_170);
  tcase_add_test(tc_core, test_171);
  tcase_add_test(tc_core, test_172);
  tcase_add_test(tc_core, test_173);
  tcase_add_test(tc_core, test_174);
  tcase_add_test(tc_core, test_175);
  tcase_add_test(tc_core, test_176);
  tcase_add_test(tc_core, test_177);
  tcase_add_test(tc_core, test_181);
  tcase_add_test(tc_core, test_182);
  tcase_add_test(tc_core, test_183);
  tcase_add_test(tc_core, test_184);
  tcase_add_test(tc_core, test_185);
  tcase_add_test(tc_core, test_186);
  tcase_add_test(tc_core, test_187);
  tcase_add_test(tc_core, test_188);
  tcase_add_test(tc_core, test_189);
  tcase_add_test(tc_core, test_190);
  tcase_add_test(tc_core, test_191);
  tcase_add_test(tc_core, test_192);
  tcase_add_test(tc_core, test_193);
  tcase_add_test(tc_core, test_194);
  tcase_add_test(tc_core, test_195);
  tcase_add_test(tc_core, test_196);
  tcase_add_test(tc_core, test_197);
  tcase_add_test(tc_core, test_198);
  tcase_add_test(tc_core, test_199);
  tcase_add_test(tc_core, test_200);
  tcase_add_test(tc_core, test_201);
  tcase_add_test(tc_core, test_202);
  tcase_add_test(tc_core, test_203);
  tcase_add_test(tc_core, test_204);
  tcase_add_test(tc_core, test_205);
  tcase_add_test(tc_core, test_206);
  tcase_add_test(tc_core, test_207);
  tcase_add_test(tc_core, test_208);
  tcase_add_test(tc_core, test_209);
  tcase_add_test(tc_core, test_211);
  tcase_add_test(tc_core, test_213);
  tcase_add_test(tc_core, test_214);
  tcase_add_test(tc_core, test_215);
  tcase_add_test(tc_core, test_216);
  tcase_add_test(tc_core, test_217);
  tcase_add_test(tc_core, test_218);
  tcase_add_test(tc_core, test_219);
  tcase_add_test(tc_core, test_220);
  tcase_add_test(tc_core, test_221);
  tcase_add_test(tc_core, test_222);
  tcase_add_test(tc_core, test_223);
  tcase_add_test(tc_core, test_224);
  tcase_add_test(tc_core, test_225);
  tcase_add_test(tc_core, test_226);
  tcase_add_test(tc_core, test_227);
  tcase_add_test(tc_core, test_228);
  tcase_add_test(tc_core, test_229);
  tcase_add_test(tc_core, test_230);
  tcase_add_test(tc_core, test_231);
  tcase_add_test(tc_core, test_232);
  tcase_add_test(tc_core, test_233);
  tcase_add_test(tc_core, test_234);
  tcase_add_test(tc_core, test_235);
  tcase_add_test(tc_core, test_236);
  tcase_add_test(tc_core, test_237);
  tcase_add_test(tc_core, test_238);
  tcase_add_test(tc_core, test_239);
  tcase_add_test(tc_core, test_240);
  tcase_add_test(tc_core, test_241);
  tcase_add_test(tc_core, test_242);
  tcase_add_test(tc_core, test_243);
  tcase_add_test(tc_core, test_244);
  tcase_add_test(tc_core, test_245);
  tcase_add_test(tc_core, test_246);
  tcase_add_test(tc_core, test_247);
  tcase_add_test(tc_core, test_248);
  tcase_add_test(tc_core, test_249);
  tcase_add_test(tc_core, test_250);
  tcase_add_test(tc_core, test_251);
  tcase_add_test(tc_core, test_252);
  tcase_add_test(tc_core, test_253);
  tcase_add_test(tc_core, test_254);
  tcase_add_test(tc_core, test_255);
  tcase_add_test(tc_core, test_256);
  tcase_add_test(tc_core, test_257);
  tcase_add_test(tc_core, test_258);
  tcase_add_test(tc_core, test_259);
  tcase_add_test(tc_core, test_260);
  tcase_add_test(tc_core, test_261);
  tcase_add_test(tc_core, test_262);
  tcase_add_test(tc_core, test_263);
  tcase_add_test(tc_core, test_264);
  tcase_add_test(tc_core, test_265);
  tcase_add_test(tc_core, test_266);
  tcase_add_test(tc_core, test_267);
  tcase_add_test(tc_core, test_268);
  tcase_add_test(tc_core, test_269);
  tcase_add_test(tc_core, test_270);
  tcase_add_test(tc_core, test_271);
  tcase_add_test(tc_core, test_272);

  suite_add_tcase(s, tc_core);
  return s;
}