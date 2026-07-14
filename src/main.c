#include <stdio.h>
#include "board.h"
#include "solver.h"


int main(void){
    sudoku board;
    if(!load_board(&board, "sudoku.txt")){
        printf("Error: carga del archivo incorrecta.\n");
        return 1;
    }
    printf("Tablero inicial:\n");
    print_board(&board);
    if(!solve_sudoku(&board)){
        printf("Error: El sudoku no tiene solucion.\n");
        return 1;
    }
    printf("Tablero final:\n");
    print_board(&board);
return 0;
}