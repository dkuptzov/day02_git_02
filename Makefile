CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GREP = main.c s21_atoi.c s21_binary.c s21_case.c s21_sprintf.c
#OBJ = s21_atoi.o s21_binary.o s21_case.o s21_sprintf.o s21_insert.o s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memset.o s21_strchr.o s21_strcpy.o s21_strcspn.o s21_strerror.o s21_string.o s21_strlen.o s21_strncat.o s21_strcmp.o s21_strncpy.o s21_strpbrk.o s21_strrchr.o s21_strstr.o s21_strtok.o s21_to_lower.o s21_to_upper.o s21_trim.o
OBJ = s21_atoi.o s21_binary.o s21_case.o s21_sprintf.o
TEST = check_tests
#TEST_FILE = tests.c testdir/s21_test.c testdir/s21_test_insert.c testdir/s21_test_memchr.c testdir/s21_test_memcmp.c testdir/s21_test_memset.c testdir/s21_test_strchr.c testdir/s21_test_strcpy.c testdir/s21_test_strcspn.c testdir/s21_test_strlen.c testdir/s21_test_strncat.c testdir/s21_test_strncmp.c testdir/s21_test_strncpy.c testdir/s21_test_strrchr.c testdir/s21_test_to_upper.c
TEST_FILE = s21_tests.c
QUEST1 = s21_sprintf
QUEST2 = test
AR = ar
L = -lcheck -lsubunit -lm
LM = -lm
LIB_A = s21_string.a
GCOV_TOOLS := --coverage

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o_gcov: %.c
	$(CC) $(CFLAGS) $(GCOV_TOOLS) -c $< -o $@

all: s21_string.a test

s21_string.a: $(OBJ)
	$(AR) crs $@ $^
	rm -rf $(OBJ)

s21_sprintf: $(GREP)
	$(CC) $(CFLAGS) $^ -o $(QUEST1) $(LM)

test:
	$(CC) -o $(TEST) $(TEST_FILE) $(LIB_A) $(L)

s21_string_gcov.a: $(addsuffix _gcov,$(OBJ))
	$(AR) crs $@ $^
	rm -f $(addsuffix _gcov,$(OBJ))

test_gcov: $(TEST_FILE) s21_string_gcov.a
	$(CC) $(CFLAGS) $(GCOV_TOOLS) $^ -o $(TEST)_gcov $(L)

gcov_report: test_gcov
	./$(TEST)_gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml -o cov_html coverage.info
	rm -f coverage.info *.gcda *.gcno pokrit *.info

.PHONY: clean

clean:
	rm -rf $(QUEST1) $(QUEST2) $(LIB_A) *.o

rebuild: clean all