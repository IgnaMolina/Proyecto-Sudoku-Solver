	CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Iinclude

SRC = src/main.c \
      src/board.c \
      src/solver.c

TARGET = sudoku

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)