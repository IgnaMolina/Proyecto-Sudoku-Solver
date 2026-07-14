#include <stdio.h>
#include "board.h"
#include "solver.h"


int main(int argc, char *argv[]){
    sudoku board;
    if (argc != 2) {
        printf("Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    if (!load_board(&board, argv[1])) {
        printf("Error al cargar el archivo.\n");
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