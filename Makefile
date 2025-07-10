CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
TEST_FLAGS=-lcheck -lm -lpthread -lsubunit

SRC_DIR=s21_funcs
TEST_DIR=tests

SRC_FILES=$(shell find $(SRC_DIR) -name "*.c")
TEST_FILES=$(shell find $(TEST_DIR) -name "*.c")

OBJ=$(SRC_FILES:.c=.o)
TOBJ=$(TEST_FILES:.c=.o)

LIB_NAME=s21_string.a
TARGET=s21_tests

UNAME=$(shell uname -s)

ifeq ($(UNAME), Linux)
    LIBS = -lcheck -lm -lrt -lpthread -lsubunit
else
    LIBS = -lcheck
endif

all: $(TARGET)

clean:
	rm -rf $(OBJ) $(TOBJ) $(TARGET) $(TARGET)_gcov $(LIB_NAME) report coverage.info *.gcda *.gcno *.info

.PHONY: all clean test gcov_report check_style fix_style

test: $(TARGET)
	./$(TARGET)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@

$(TARGET): $(LIB_NAME) $(TOBJ)
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(TOBJ) $(LIB_NAME) -o $@ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n --style=file $(SRC_DIR)/*.c $(SRC_DIR)/*.h $(TEST_DIR)/*.c
	clang-format -i --style=file $(SRC_DIR)/*.c $(SRC_DIR)/*.h $(TEST_DIR)/*.c
	rm ./.clang-format

gcov_report:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage -I$(SRC_DIR) $(SRC_FILES) $(TEST_FILES) -o $(TARGET)_gcov $(TEST_FLAGS)
	./$(TARGET)_gcov
	lcov -t "$(TARGET)" -o $(TARGET).info -c -d .
	genhtml -o report $(TARGET).info
	xdg-open report/index.html || open report/index.html
