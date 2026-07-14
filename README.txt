# Sudoku Solver in C

A command-line Sudoku solver written in C using a recursive backtracking algorithm.

## Features

- Load Sudoku boards from text files.
- Validate the input format.
- Solve any valid Sudoku using backtracking.
- Print both the original and solved board.
- Modular project structure.

## Project Structure

.
├── include/
│   ├── board.h
│   └── solver.h
├── src/
│   ├── board.c
│   ├── solver.c
│   └── main.c
├── tests/
│   ├── sudoku1.txt
│   ├── sudoku2.txt
│   ├── sudoku3.txt
│   └── sudoku4.txt
├── Makefile
└── README.md

## Requirements

- GCC (C11 compatible)
- GNU Make (optional, recommended)

## Compilation

### Using Make

'''bash
make

### Without Make

'''bash
gcc -Wall -Wextra -Wpedantic -std=c11 -Iinclude src/main.c src/board.c src/solver.c -o sudoku
'''

On Windows the executable will usually be:

'''bash
sudoku.exe
'''

## Usage

Linux:

'''bash
./sudoku tests/sudoku1.txt
'''

Windows (PowerShell):

'''powershell
.\sudoku.exe tests\sudoku1.txt
'''

Windows (CMD):

'''cmd
sudoku.exe tests\sudoku1.txt
'''

## Input Format

The input file must contain exactly 9 rows and 9 columns.

Example:

530070000
600195000
098000060
800060003
400803001
700020006
060000280
000419005
000080079


Use '0' to represent empty cells.

## Algorithm

The solver uses recursive backtracking:

1. Find the first empty cell.
2. Try numbers from 1 to 9.
3. Check whether the move is valid.
4. Continue recursively.
5. Backtrack if necessary.
