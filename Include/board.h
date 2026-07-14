#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#define BOARD_SIZE 9

typedef struct {
    int cells[BOARD_SIZE][BOARD_SIZE];
} sudoku;

bool load_board(sudoku *board, const char *filename);
void print_board(const sudoku *board);

#endif