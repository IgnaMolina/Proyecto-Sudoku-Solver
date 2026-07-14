#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "board.h"

bool is_valid_move(const sudoku *board, const int num, const int columna, const int fila){
    int num_tablero;
    //Chequeo la fila
    for(int i = 0; i < BOARD_SIZE; i++){
        if(board -> cells[i][columna] == num ){
            return false;
        }
        if(board -> cells[fila][i] == num){
            return false;
        }
    }
    int inicio_fila  = (fila/3) * 3;
    int inicio_columna = (columna/3) *3;
    for(int f = inicio_fila; f < inicio_fila + 3; f++){
        for(int c = inicio_columna; c < inicio_columna + 3; c++){
            if(board -> cells[f][c] == num){
            return false;
            }  
        } 
    }
    return true;
}

bool find_empty_space(const sudoku *board, int *fila,int *columna){
    for (int f = 0; f < BOARD_SIZE; f++){
        for(int c = 0; c < BOARD_SIZE; c++){
            if(board -> cells[f][c] == 0){
               *fila = f;
               *columna = c;
               return true;
            }
        }
    }
    return false; 
}
bool solve_sudoku(sudoku *board){
    int fila;
    int columna; 
    if(!find_empty_space(board, &fila, &columna)){
        return true;
    }else{
        for(int n = 1; n <= 9; n++){
            if(is_valid_move(board, n, columna, fila)){
                board -> cells[fila][columna] = n;
                if(solve_sudoku(board)){
                    return true;
                }
                   board -> cells[fila][columna] = 0; 
            }
        }
    }
    return false;
}
